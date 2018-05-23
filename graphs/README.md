### 3 ways to represent graphs:

#### Adjacency List: (For a good example, check out Bidirectional BFS example)
 - Pros:
   - Less space (O|V| + O|E|). Worst case O(V^2) space
   - Adding a vertex is easy
 - Cons:
   - To find if edge between u and v takes O(V) time

#### Adjacency Matrix:
 - Pros:
   - Removing edge takes O(1) time
   - To find if edge between u and v takes O(1) time
 - Cons:
   - Consumes more space O(V^2)
   - Even if the graph is sparse (contains less number of edges), it consumes the same space
   - Adding a vertex is O(V^2) time

#### Objects and Pointers:
 - Pros:
   - 
 - Cons:
   - 

