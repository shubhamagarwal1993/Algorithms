# Description
Uber riding service, drivers and riders, pick up and drop off without any modifications

# Requirements
## Creation, and user accounts
- Driver side
  - Can turn on/off job
- Rider side
  - Can request ride
  - Can pay for the ride
## Retrievals
- Get user location, and map related to it.
## Analytics
- Frequency of rides requested over a day
## Capacity
- Assume 10,000 rides requested per second
- Assume 7000 drivers are on at any time, and 2000 are switching in, and out of the system every hour

# Memory management, and capacity calculations
## Traffic
## Bandwidth
## Database memory capacity
## Caching memory capacity

# API Design
- driverJobStatusChange()
- riderRequestRide()
- riderRidePayment()

# Database design
- Table1: User account
id, first, last, email
- Table2: trips
id, created, start_location, end_location
- Table3: Rider
id, user_id, created, start_location, end_location
- Table4: Driver
id, user_id, active, current_loc
- Ta

# Algorithm

# Other things to consider
