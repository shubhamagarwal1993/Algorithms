# Instagram
A Photo sharing service, where users can upload photos, and share them with other users.

# Requirements:
## Creation, Retrieval, and User Account:
- Users can upload and retrieve photos
- Photos can be private or public
- Users can follow other users
- The news feed for each user will consist of top photos of all the people the user follows.
- User can search for photos/videos based on photo/video title
- 2 million new photos every day, 23 new photos per second

## Retrieval
- Assume a 100 to 1 retrieve to upload ratio for a photo
- Latency should be 200 ms for news feed generation
- Consistency can take a hit in the interest of availability
- Our service should be highly reliable
- System should be highly available

## Analytics:
- ...

## Capacity:
- Average photo size => 200 KB
- 500 million total users, with 1 million daily active users

# Memory Management and Capacity calculations:
## Traffic calculations:
- Total new photos per second => 23 photos / sec
- Total photo retrievals per second => 2300 / sec
                                    |--> comes from 100 times the write request as an assumption

## Database Memory calculations:
- Total space required for 1 day of photos: 2 million * 200 Kb => 400 Gb
- Total space required for 10 years of photos: (10 * 12 * 30) * 400Gb => 1440 Tb

## Caching Memory calculations:
Assume 20% URLs generate 80% traffic, and our cache stays warm for 1 day. Thus we need to cache 20% daily traffic
- Total photos per day => 2 million
- Total memory needed  => 2 million * 200Kb => 400Gb

## Bandwidth calculations:
- For incoming data => (photos / sec) * (size of each photo)
                    => (23 photos / sec) * (200 Kb)
                    => 4600 Kb / sec
                    => 4.6 Mb / sec
- For outgoing data => (100) * (bandwidth for incoming data)
                    => (100) * 4.6 Mb / sec)
                    => 460 MB / sec

# API Design:
Use REST API endpoints so other services can use it.
- Create:
```
createPhoto(loginToken, photo, photoName=None)
loginToken: The user token to track for analytics, throttle max usage, or detect spamming
photo: base64 encoded image data
photoName (optional): title/name of photo, will be useful for retrieval/search

Returns a success code with json containing all fields, but the image since it's too expensive.
```
- Delete:
```
deletePhoto(loginToken, photo)
loginToken: The user token to track for analytics, throttle max usage, or detect spamming
photo: base64 encoded image data

Returns a success code with no data
```
- Get/Retrieve:
```
getPhoto(loginToken, photoName=None)
loginToken: The user token to track for analytics, throttle max usage, or detect spamming
photoName (optional): title/name of photo for search

Return:
If no data provided for photoName, returns a success code with json containing
    A list of all photos of the user
If data is provided for photoName, returns a success code with json containing
    A list of all private photos of the user whose title matches it
    A list of all public photos from across the database whose title matchehs it
```
- Generate Timeline:
```
getTimeline(loginToken, pagination=None)
loginToken: The user token to track for analytics, throttle max usage, or detect spamming
pagination (optional): if scrolling, we can return photos after certain count

Return:
Returns a success code with json containing photos from user's following list posted within the last 24 hours sorted in descending order of time.

Note: This can be a huge list, and we should use pagination to return 5 photos for each request
```

# Database Design:
```
Table 1: User data
Id, first, last, email, password
Table 2: Photos
Id, S3 id, userID, photoName, permissionID, created
Table 3: PermissionTypes
Id, PermissionType
```
- We can make another table just for originalURLs so they are not repeated if a lot of tinyURLs refer to the same originalURL. This will result in more joins or id lookups.
- We can use a noSQL or SQL database, both should be fine. This data is very ordered by time, and it might be easier to go with a NoSQL database.

# Algorithm:
NA

# Other smaller things to consider:
## Data partitioning:
## Cache:
## Load Balancer:
## Purging or DB cleanup:
## Telemetry:
## Different kinds of data that can be captures:
## Security and Permissions:
   - Users can choose who can see their photos, public, followers/friends, or private.

