## Features of p2p
 - Redundant storage
 - Selection of nearby servers
 - Search
 - Authentication

### Chord protocol is used for:
 - given a key, map the key onto a node
 - to find the locations of keys
 - how new nodes join the system
 - how to recover from failure (or planned departure) os existing nodes

### Hash function (uses consistent hashing):
 - fast distributed computation to map keys to nodes responsible for them
 - balance node, so that all nodes receive roughly the same number of keys
 - when node n joins or leaves the network, only O(1/N) fraction of the keys are moved
 - routing table is distributed. Each node has routing info for only O(log N) other nodes.
   A node resolves hash function by communicating with max O(log N) nodes in a N node system
   A lookup requires O(log N) messages
 - when a node joins or leaves the system, chord updates routing information in no more than O(log^2 N) msgs

### Consistent hashing:
 - node: m-bit identifier using a base hash function such as SHA-1
   - hash the node's IP address
   - nodes are ordered in a circle of 0 to 2^m - 1 (identifier circle modulo 2^m)
 - key : m-bit identifier using a base hash function such as SHA-1
   - hash the key k
   - k is assigned to first node whose identifier is equal to or follows k [successor(k)] clockwise from k

#### New node n joins the network:
 - certain keys previously assigned to n's successor now become assigned to n

#### Existing node n leave the network:
 - all of n's assigned keys are reassigned to n's successor

### Theorem 1: For any set of N nodes and K keys:
 - bound of e = O(log N). e can be reduced to a small constant by having each node run O(log N) virtual nodes each with it's own identifier
 - each node is responsible for at most (1 + e)K/N keys
 - When an (N + 1)st node joins or leaves the network, responsibility for O(K/N) keys changes hand (and only to or from the joining or leaving node)

### Scalable key location:
 - m is the number of bits in the key/node identifiers.
 - Each node N maintains a routing table with at most m entries, called the finger table
 - The ith entry in the finger table at node n, contains the identity of the first node s that succeeds n by at least 2^(i-1) on the identity circle
   - n is the current node, we need to find node s
   - `s = successor(n + 2^(i-1))` where 1 <= i <= m
   - s is the ith finger of node n, denoted by `n.finger[i].node`
   - The first finger of node n is its immediate successor of the identity circle, for convenience we can refer to it as the successor rather than the first finger

### Finger Table

| Notation        | Definition                                             |
|-----------------|--------------------------------------------------------|
| finger[k].start | (n + 2^(k-1) mod 2^m, 1 <= k <= m                      |
| .interval       | [ finger[k].start, finger[k+1].start )                 |
| successor       | the next node on the identifier circle; finger[1].node |
| .node           | first node >= n.finger[k].start                        |
| predecessor     | the previous node on the identifier circle             |

#### Important characteristics
 - each node stores information about only a small number of other nodes
 - each node knows more about nodes closely following it on the identifier circle than about nodes far away
 - a node's finger table does not contain enough information to determine the successor of an arbitrary key k

#### node n does not know the successor of a key k
 - if n can find a node whose ID is closer than its own to k, that node will know more about the identifier circle in the region of k than n does
 - n searches its finger table for the node j whose ID most immediately preceeds k, and asks j for the node it knows whose ID is closest to k
 - n leans about nodes with IDs closer and closer to k
 - The finger pointers at repeatedly doubling distances around the circle cause each iteration of the loop to halve the distance to the target identifier

### Theorem 2: For any set of N nodes and K keys:
 - The number of nodes that must be contacted to find a successor in an N-node network is O(log N)

### Node Joins:
 - arbitraty nodes can join at any time, we need to preserve the ability to locate every key in the network 
 - Chord preserves 2 invariants:
   - each node's successor is correctly maintained
   - for every key k, node successor(k) is responsible for k

### Theorem 3: For any set of N nodes and K keys:
 - Any node joining or leaving an N node Chord network will use O(log^2 N) messages to re-establish the chord routing invariants and finger tables:
 - Each node maintains a predecessor pointer
 - A node's predecessor pointer contains the Chord identifier and IP address of the immediate predecessor of that node and can be used to walk counter-clockwise around the identifier circle

#### To maintain the invariants when a node n joins the network, Chord performs 3 tasks:
 - Initialize the predecessor and fingers of node n
 - Update the predecessors and fingers of existing nodes to reflect the addition of n
 - Notify the higher layer software so that it can transfer state (E.g. values) associated with keys that node n is now responsible for

We assume that the new node learns the identity of an existing Chord node n' by some external mechanism. Node n uses n' to initialize its state and add itself to the existing Chord network, as follows:
 - Initializing fingers and predecessor:
   - Node n learns its predecessor and fingers by asking n' to look them up
 - Updating fingers of existing nodes:
   - 
 - Transferring keys:
   - Node n can become the successor only for keys that were previously the responsibility of the node immediately following n, so n only needs to contact that one node to transfer responsibility for all relevant keys
