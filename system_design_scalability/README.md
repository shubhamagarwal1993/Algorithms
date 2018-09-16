### Handling the questions
 - go broad first, write key features on board
 - make assumptions / estimates - how much total space will be needed to store all the data
 - scope the problem


### Basic components
 - somthing to store data
 - something for logic, like for APIs or proccesses
 - scaling (caching, load balancing, non-relational databases, microservices, and sharding)
 - distributed systems, SOA, n-tiered software architecture
 - stream processing, batch processing, search, and retrieval

### Steps
 - Ask questions. Write requirements or key points on board
 - Start with the customer in mind. Who is the customer and what problem are you solving for them
 - Draw diagram on board to express your ideas. Blocks with basic description and arrows between them
   - software components and data sources:
   - arrows: to show web services, APIs, and processed connecting software components
 - Discuss trade-offs in your design. Advantage and dis-advantanges of your system
   - Chaning a component might be a part of this discussion

                                                                                     _________
    ---------            ---------------------   files written to persistent store  |         |
    | Images | -------> | Image write service | ----------------------------------> |         |
    ---------            ---------------------                                      | Image   |
                                                                                    | File    |
                                                                                    | Storage |
     --------   Request image                                                       |         |
    | Client | --------------> | Image retrieval service | -----------------------> |         |
     --------                                                                       |         |
            <------------------------------------------------| image | -------------|_________|



### Solving steps:
  - draw a few basic boxes first (5 - 6 components)
    - compute
    - storage
    - front-end
    - back-end
    - caching
    - queueing
    - networking
    - load-balancing
