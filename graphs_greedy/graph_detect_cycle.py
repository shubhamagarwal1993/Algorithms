"""
Make a simple directed graph with cycle
Make a simple undirected graph with cycle

DFS on both to detect the cycle
"""

# -*- encoding: utf-8 *-*


class Node:
    """
    represents a node of the graph
    """
    def __init__(self, data):
        self.data = data


class Edge:
    """
    represent an edge of the graph
    """
    def __init__(self, src, dest, weight):
        self.src = src
        self.dest = dest
        self.weight = weight

    def getSrc(self):
        return self.src

    def getDest(self):
        return self.dest


class Graph:
    """
    represents a directed graph using adjacency list representation
              6 <-------- 5
              ^           ^
              |           |
              0 --> 1 --> 4 <---
                \  /      ^     |
                 vv       |     |
         3 <---- 2--------      |
         |                      |
          ----------------------
    """
    def __init__(self, total_vertices):
        self.total_vertices = total_vertices
        self.adj = {}

    def print_adj_list(self):
        print(self.adj)

    def construct_directed_graph(self):
        self.add_directed_edge(0, 1)
        self.add_directed_edge(0, 2)
        self.add_directed_edge(0, 6)
        self.add_directed_edge(1, 2)
        self.add_directed_edge(1, 4)
        self.add_directed_edge(2, 3)
        self.add_directed_edge(2, 4)
        self.add_directed_edge(3, 4)
        self.add_directed_edge(4, 5)
        self.add_directed_edge(5, 6)

    def construct_undirected_graph(self):
        """
                  6 ---------|
                  |          |
                  |          |
                  0 -- 1     |
                  |  /       |
                  | /        |
                  2 -- 4 --- 5
                  |  /
                  | /
                  3
        """
        self.add_directed_edge(0, 1)
        self.add_directed_edge(1, 0)
        self.add_directed_edge(0, 2)
        self.add_directed_edge(2, 0)
        self.add_directed_edge(1, 2)
        self.add_directed_edge(2, 1)
        self.add_directed_edge(1, 4)
        self.add_directed_edge(4, 1)
        self.add_directed_edge(0, 6)
        self.add_directed_edge(6, 0)
        self.add_directed_edge(2, 3)
        self.add_directed_edge(3, 2)
        self.add_directed_edge(3, 4)
        self.add_directed_edge(4, 3)
        self.add_directed_edge(4, 5)
        self.add_directed_edge(5, 4)
        self.add_directed_edge(5, 6)
        self.add_directed_edge(6, 5)
        self.add_directed_edge(2, 4)
        self.add_directed_edge(4, 2)

    def add_directed_edge(self, start, end):
        if start in self.adj:
            start_edge_list = self.adj[start]
            for index in range(len(start_edge_list)):
                if start_edge_list[index] == end:
                    return
            start_edge_list.append(end)
            self.adj[start] = start_edge_list
        else:
            self.adj[start] = [end]
        return

    def add_undirected_edge(self, start, end):
        self.add_directed_edge(start, end)
        self.add_directed_edge(end, start)

    def undirected_graph_detect_cycle_DFS_util(self, curr_node, visited, path, parent):
        visited[curr_node] = True
        path.append(curr_node)

        # Recur for all adjacent vertices
        if curr_node in self.adj:
            end_node_list = self.adj[curr_node]
            for adj_node in end_node_list:
                if not visited[adj_node]:
                    if self.undirected_graph_detect_cycle_DFS_util(adj_node, visited, path, curr_node):
                        return True
                elif adj_node != parent:
                    path.append(adj_node)
                    path.append(parent)
                    return True
        path.pop(-1)
        return False

    def undirected_graph_detect_cycle_DFS(self):
        path = []
        visited = [False] * self.total_vertices

        # In an undirected graph, parent will from a loop
        # We need to keep a node's parent updated to avoid check for cycle with parent
        parent = -1

        # Call recursive helper function to detect cycle in different DFS trees
        for curr_node in range(self.total_vertices):
            if not visited[curr_node]:
                if self.undirected_graph_detect_cycle_DFS_util(curr_node, visited, path, parent):
                    print("Found a cycle with DFS", path)
                    break
                else:
                    print("Graph doesn't contain cycle")
        return

    def find(self, parent, node):
        """
        Takes a vertex and finds its main parent
        """
        if parent[node] == -1:
            return node
        return self.find(parent, parent[node])

    def union_vertices(self, parent, src_parent, dest_parent):
        """
        Takes parents and merges them into one set
        """
        src_set = self.find(parent, src_parent)
        dest_set = self.find(parent, dest_parent)
        if src_set >= 0:
            parent[src_set] = dest_set

    def undirected_graph_detect_cycle_union_find(self):
        """
        Detect cycle in an undirected graph using disjoint set (or union-find)

        Uses a disjoint set data structure, this data structure keeps track of set of elements partitioned
        into a number of disjoint subsets

        This algo performs 2 functions:
        - Find:  Find which subset a particular element is in. Used to determine if 2 elements are in the same subset
        - Union: Join 2 subsets into a single subset

        How it works:
        - Keep track of the subsets in an array called parent[]
        - Initially, all slots of parent array are initialized to -1
        - This means there is only one item in every subset

        - Now process all edges one by one
            - For each edge, make subsets using both the vertices of the edge
            - If both the vertices are in the same subset, a cycle is found
            - If vertices are in different subset, take union of them. Make node 0 parent of node 1
        """
        parent = [-1] * self.total_vertices
        path = []

        # Loop over all vertices, to get all edges between src and dest
        for src_node, dest_nodes in self.adj.items():
            for dest_node in dest_nodes:
                src_parent = self.find(parent, src_node)
                dest_parent = self.find(parent, dest_node)

                path.append(dest_node)

                # If parents are the same, we have a cycle
                if src_parent == dest_parent:
                    print("Found a cycle with union-find", end=" ")
                    print(path)
                    return

                # If no cycle, combine src and dest
                self.union_vertices(parent, src_parent, dest_parent)

        return

    def directed_graph_detect_cycle_DFS(self):
        path = []
        visited = [False] * self.total_vertices
        rec_stack = [-1] * self.total_vertices

        # In an undirected graph, parent will from a loop
        # We need to keep a node's parent updated to avoid check for cycle with parent
        parent = -1

        # Call recursive helper function to detect cycle in different DFS trees
        for curr_node in range(self.total_vertices):
            if not visited[curr_node]:
                if self.directed_graph_detect_cycle_DFS_util(curr_node, visited, rec_stack, path):
                    print("Found a cycle with DFS", path)
                    break
                else:
                    print("Graph doesn't contain cycle")
        return

    def directed_graph_detect_cycle_DFS_util(self, curr_node, visited, rec_stack, path):

        if not visited[curr_node]:
            visited[curr_node] = True
            rec_stack[curr_node] = curr_node
            path.append(curr_node)

            # Recur for all adjacent vertices
            if curr_node in self.adj:
                end_node_list = self.adj[curr_node]
                for adj_node in end_node_list:
                    if not visited[adj_node]:
                        if self.undirected_graph_detect_cycle_DFS_util(adj_node, visited, path, curr_node):
                            return True
                    elif rec_stack[adj_node] >= 0:
                        path.append(adj_node)
                        print("Found a cycle with DFS", end=" ")
                        return True

        rec_stack[curr_node] = -1
        path.pop(-1)
        return False


def main():
    """
    Detect cycle in a graph
    """
    total_vertices = 7

    """
    Detect cycle in undirected graph
    Can use union-find, DFS, BFS, or graph coloring.

    Time Complexity:
        DFS: O(V + E)
        BFS: O(V + E)
        graph coloring: O(V + E)
        union-find: O(E logV)
    Space Complexity:
        All take O(V) => O(V) path of cycle, O(V) recursion stack, O(V) visited array
    """
    graph_undirected = Graph(total_vertices)
    graph_undirected.construct_undirected_graph()
    # using DFS
    graph_undirected.undirected_graph_detect_cycle_DFS()
    # using union-find
    graph_undirected.undirected_graph_detect_cycle_union_find()

    """
    Detect cycle in directed graph
    Can use DFS, tarjan's algo, or graph coloring. All take time O(V + E)

    Using DFS:
        Time Complexity: O(V + E),
        Space Complexity: O(V) => O(V) path of cycle, O(V) recursion stack, O(V) visited array
    """
    graph_directed = Graph(total_vertices)
    graph_directed.construct_directed_graph()
    # using DFS
    graph_directed.directed_graph_detect_cycle_DFS()
    return


if __name__ == '__main__':
    main()

