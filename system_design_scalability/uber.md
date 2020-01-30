# Uber riding service system design
- Riders can request rides - pickup and dropoff locations
- Drivers can drive whenever they want

# Requirements:
## Creation, and user accounts
- Driver side
  - Can turn on/off job
- Rider side
  - Can request ride
  - Can pay for the ride
## Retrievals
- Get user location, and map related to it.
- Get information about a current ride
## Analytics
- Frequency of rides requested over a day
- Average rides per user over a month
## Capacity
- Assume 1,000 rides requested per second
- Assume 10,000 drivers are on at any time, and 500 are switching in, and out of the system every second

# Memory management, and Capacity calculations:

## Traffic
- Riders
  - Total rides per second => 1,000
  - Total payments per second => 1,000 (should be same as total riders / sec)
- Drivers
  - Total driver change requests per second => 500 (only the ones filtering in, and out)
## Bandwidth
- Riders
  - Total data blob for each ride request => 2 Kb
  - Total data blob for each payment request => 2 Kb
- Drivers
  - Total data blob for each driver requests => 2 Kb

- For incoming data => (Total rides / sec * blob size for each ride request) +
                       (Total payments / sec * blob size for each payment) +
                       (Total driver change request * blob size for user change)
                      => (1,000 * 2 Kb) + (1,000 * 2 Kb) + (500 * 2 Kb)
                      => 2 Mb + 2 Mb + 1 Mb
                      => 5 Mb / sec
- For outgoing data => (Total rides / sec * blob size for each ride end) + (Total driver change * blob size for each driver data change)
                    => (1,000 * 2 Kb) + (500 * 1 Kb)
                    => 2.5 Mb / sec

## Database memory capacity
- Assume we keep rides upto 5 years
- For driver
  - Total size of driver changes in 5 years => (500 * 2Kb) * (5 * 12 * 30 * 24 * 60 * 60) => 160 Tb
- For rider
 - Total size of rides in 5 years => (1000 * 2Kb) * (5 * 12 * 30 * 24 * 60 * 60) => 320 Tb
- Total size => 160 Tb + 320 Tb => 480 Tb

## Caching memory capacity
- Active ride details, up to 2 hours
- Active ride location update every min, assume avg ride lasts for 15 mins
- Cache user location => 1 min, assume avg for 20 mins

- Total memory for active rides => (1,000 * 5Kb) * (2 * 60 * 60) => 36 Gb
- Total memory for location update => (1,000 * 1Kb) * (15 * 60) => 900 Mb
- Total memory for user location => (1,000 * 1Kb) * (20 * 60) => 1200 Mb
- Total memory needed for cache => 36 Gb + 900 Mb + 1200 Mb => 38.1 Gb

# API Design
- Driver side
  - Filter in/out
  ```
  driverJobStatusChange(loginToken, jobStatus)
  loginToken: The user token to track for analytics, throttle max usage, or detect spamming
  jobStatus: A boolean to indicate whether a driver wants to be active, or inactive

  Returns a success code with json containing all fields
  ```
- Rider side
  - Request ride
  ```
  riderRequestRide(loginToken, start_location, end_location)
  loginToken: The user token to track for analytics, throttle max usage, or detect spamming
  start_location: The ride start location, for driver matching
  end_location: The ride end location

  Returns a success code with ride details
  ```
  - Pay for ride
  ```
  riderRidePayment(loginToken, payment_details)
  loginToken: The user token to track for analytics, throttle max usage, or detect spamming
  payment_details: The payment account to use

  Returns a success code with no data
  ```

# Database design
- Table1: Rider user account
id, first, last, email, created
- Table2: Driver user account
id, first, last, email, created
- Table3: trips
id, rider_id, created, start_location, end_location
- Table4: Rider locations
record_time, rider_id, location, record_time
- Table5: Driver locations
record_time, driver_id, location, record_time
- Table6: Payments:
id, rider_id, payment_details

# Algorithm
- We need to break this up into microservices, and handle different types of data as they demand:
  - Location data: Use a timeseries database to get user location history for the ride time, instead of querying a table full of other users
  - Driver/Rider data: Use a simple psql database, this is a very relational data that does not change much
  - Payments: Make this a separate service, since payments can be queued and happen later on
  - Rider/Driver matching: Use geospatial datastructure (check implementation in redis) to find drivers close to start_location of a ride.
  - Login/authentication database: Can start with a single point of failure like system, where login tokens are generated for a user session and cached.

# Other things to consider
- Data sharding
- Purging or db cleanup, since old data is very useless for users in such an app
- Telemetry: Track hits of different endpoints, because scaling of each service can be very independent.
- Security and Permissions: Rider location sharing needs to be permission based.
