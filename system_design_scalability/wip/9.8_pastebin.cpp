// pastebin - user can enter a piece of text and get a randomly generated URL for public access

scope the problem:
 - no user accounts or editing documents
 - analytics for how many times a page is accessed
 - docs get deleted if not accessed in a long time
 - URLs should not be guessable

assumptions:
 - system gets heavy traffic, and has many millions of documents
 - some documents get much more traffic than others

Major Components:
- store files with name-hash
  No need to store files in db as we do not need search capability.
- make a db with URL to name-hash
- make a db for analytics, it can have rows for URL, each visit (timestamp, IP address, and location)

Key Issues:
 - some docs are accessed more frequently than others
   use cache to store the most recently accessed URLs/files inmemory
   Cache can have a timeout, since docs will not be edited, no need to invalidate cache manually/logically
 - sharding the DB
   map from hash(URL) % N to locate machine / database which will have the URL

Generating URLs
 - cannot be monotonically increasing int value as this can be guessed
 - generate a random GUID (128 bit) number, check if URL exists. This would eliminate collisions if any