// Design data structures for a very large social network
// Design an algorithm to show the shortest path between 2 people

// graph - each person is a node - edge between 2 nodes indicates friends
// To find path between 2 people - BFS or a bi-directional BFS


// This class will represent the path as we are searching it storing each Person and the 
// previousNode we visited in the path
class PathNode {
    private:
        Person person = NULL;
        PathNode previousNode = NULL;
    public:
        PathNode(Person person, PathNode previousNode) {
            this.person = person;
            this.previousNode = previousNode;
        }

        Person getPerson() { return person; }

        LinkedList<Person> collapse(bool startsWithRoot) {
            LinkedList<Person> path = new LinkedList<Person>();
            PathNode node = this;
            while(node != NULL) {
                if(startsWithRoot) {
                    path.addLast(node.person);
                } else {
                    path.addFirst(node.person);
                }
                node = node.previousNode;
            }
            return path;
        }
};

// holds data we need for BFS
class BFSData {
    private:
        unordered_map<Node, visited> isVisited = new unordered_map<int, PathNode>();
        Queue<PathNode> toVisit = new LinkedList<PathNode>();
    public:
        BFSData(Person root) {
            PathNode sourcePath = new PathNode(root, NULL);
            toVisit.add(sourcePath);
            visited.put(root.getID(), sourcePath);
        }

        bool isFinished() { return toVisit.isEmpty(); }
};

// Merge paths where searches met at connection
LinkedList<Person> mergePaths(BFSData bfs1, BFSData bfs2, int connection) {
    PathNode end1 = bfs1.visited.get(connection);       // end1 -> source
    PathNode end2 = bfs2.visited.get(connection);       // end2 -> destination
    LinkedList<person> pathOne = end1.collapse(false);
    LinkedList<person> pathTwo = end2.collapse(true);   // reverse
    pathTwo.removeFirst();                              // remove connection
    pathOne.addAll(pathTwo);                            // add second path
    return pathOne;
}

// Search one level and return collision, if any
Person searchLevel(unordered_map<int, Person> people, BFSData primary, BFSData secondary) {
    // We only want to search one level at a time
    // Count how many nodes are currently in the primary's level  and only do that many nodes
    // We will continue to add nodes to the end
    int count = primary.toVisit.size();

    for (int i = 0; i < count; ++i) {
        // pull out first node
        PathNode pathNode = primary.toVisit.poll();
        int personId = pathNode.getPerson().getID();

        // check if it's already been visited
        if(secondary.visited.containsKey(personId)) {
            return pathNode.getPerson();
        }

        // Add friends to queue
        Person person = pathNode.getPerson();
        vector<int> friends = person.getFriends();
        for(int friendId: friends) {
            if(!primary.visited.containsKey(friendId)) {
                Person friend = people.get(friendId);
                PathNode next = new PathNode(friend, pathNode);
                primary.visited.put(friendId, next);
                primary.toVisit.add(next);
            }
        }
    }
    return NULL;
}

LinkedList<Person> findPathBiBFS(unordered_map<int, Person> people, int source, int destination) {
    BFSData sourceData = new BFSData(people.get(source));
    BFSData destData = new BFSData(people.get(destination));

    while(!sourceData.isFinished() && !destData.isFinished()) {
        // search out from source
        Person collision = searchLevel(people, sourceData, destData);
        if(collision != NULL) {
            resturn mergePaths(sourceData, destData, collision.getID());
        }

        // search out from destination
        collision = searchLevel(people, destData, sourceData);
        if(collision != NULL) {
            resturn mergePaths(sourceData, destData, collision.getID());
        }
    }
    return NULL;
}