// 10 billion URLs. How to detect the duplicate documents?
// In this case, assume duplicate means that the URLs are identical

Assume: Each URL on an aveage is 100 characters -> 400 bytes
10 billion URLS would be 1000 billion characters 	-> 4000 billion bytes 
													-> 4 billion Kb
													-> 4,000,000 MB
													-> 4000 GB
													-> 4 TB

Assume we can fit this on one machine. 2 ways to find duplicate URLs
 - Hash table  
   - create a hash table, URL maps to true (this value is immaterial).
   - if key (URL) exists, then we can find duplicates
 - Sorting
   - sort the list, look for duplicates
   - This will take extra time

Now with 4TB of data, we can solve in 2 ways:
  - store data on disk
    - do 2 passes of the document
    - the first pass will split the list of URLs into 4000 chunks of 1 GB Each
      - store URL u in a file names <x>.txt where x = hash(u)%4000
      - We do this becase if 2 URLS are the same, then they have the same hash, and would be in the same file
      - this way, if there are duplicate URLs, then they would be in the same file and not across files
    - the second pass will load each file into memory, create a hash table of URLs and look for duplicates

  - split data on different machines
    - do 2 passes of the document
    - the first pass will split the list of URLs into 4000 chunks of 1 GB Each
      - store URL u in a machine called x where x = hash(u)%4000
      - We do this becase if 2 URLS are the same, then they have the same hash, and would be in the same machine
      - this way, if there are duplicate URLs, then they would be in the same machine and not across machines
    - the second pass will be each machine crearing a hash table of URLs and looking for duplicates
      - out main machine can ask each machine for duplicates
  - Pros: parallellize the operation, since each machine would look for duplicates at the same time
  - Cons: relying on a lot of machines, will have to handle failures. Added comlexity