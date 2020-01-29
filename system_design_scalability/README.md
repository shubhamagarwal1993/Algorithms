# Approaching system design questions
 - Go broad first, write key features on board
 - Make assumptions / estimates
 - Scope the problem
 - Start with the customer in mind. Who is the customer and what problem are you solving for them
 - Draw diagram on board to express your ideas. Blocks with basic description and arrows between them
   - Software components and data sources:
   - Arrows: to show web services, APIs, and processed connecting software components
 - Discuss trade-offs in your design. Advantage and dis-advantanges of your system
   - Chaning a component might be a part of this discussion

```
                                                                                     _________
    ---------            ---------------------   files written to persistent store  |         |
    | Images | -------> | Image write service | ----------------------------------> |         |
    ---------            ---------------------                                      | Image   |
                                                                                    | File    |
                                                                                    | Storage |
     --------   Request image                                                       |         |
    |        | --------------> | Image retrieval service | -----------------------> |         |
    | Client |                                                                      |         |
    |        | <---------------------------------------------| image | -------------|_________|
    |--------|
```

## Steps to follow:
### Description
 - Basic description of the problem
### Requirements:
 - Creation, and User Account
 - Retrieval
 - Analytics
 - Capacity
### Memory management and capacity calculations
 - Traffic calculations
 - Database memory calculations
 - Caching memory calculations
 - Bandwidth calculations

### API Design
 - Create: Function with arguments, and returned code/data
 - Delete: Function with arguments, and returned code/data

### Database Design
 - User data
 - Actual problem data, with inner joinable userID column. This can then be used to do analytics

### Algorithm
 - A more concreate detail of what the algorithm(s) will look like

### Other things to consider
 - Data partitioning
 - Caching
 - Load balancing
 - Purging, and db cleanup
 - Telemetry
 - Security, and permissions
 - Microservices
 - Job queues
 - stream processing, batch processing, search, and retrieval
 - networking
 - front-end
 - back-end

