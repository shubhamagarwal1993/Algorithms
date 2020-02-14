"""
Make a simple graph

Do a BFS to get from start to end node and print path
"""

# -*- encoding: utf-8 *-*


class Node:
    """
    represents a node of the graph
    """
    def __init__(self, data):
        self.data = data


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

    def BFS_all(self, graph, start):
        """
        Print complete BFS of graph from starting node
        V: number of vertices
        E: number of edges
        Time complexity: O(V + E), each edge and vertex combination visited once
        Space complexity: O(V), to hold a visited list and a queue which can have all vertices at once in worst case
        """

        # Mark all the vertices as not visited
        visited = [False] * self.total_vertices

        # Create a queue for BFS
        queue = []

        # Mark the current node as visited and enqueue it
        visited[start] = True
        queue.append(start)

        # Loop over queue and print vertices
        while len(queue) > 0:
            # Dequeue a vertex from queue and print it
            start = queue.pop(0)
            print(start, end=" ")
            # Get all adjacent vertices of new start, if not visited then put in queue
            if start in self.adj:
                end_node_list = self.adj[start]

                # if node in end_node_list not visited, add to queue
                for index in range(len(end_node_list)):
                    if not visited[end_node_list[index]]:
                        visited[end_node_list[index]] = True
                        queue.append(end_node_list[index])
        print()
        return

    def BFS_path(self, graph, start, end):
        """
        Print complete BFS of graph from starting node
        V: number of vertices
        E: number of edges
        Time complexity: O(V + E), each edge and vertex combination visited once
        Space complexity: O(V), to hold a visited list and a queue which can have all vertices at once in worst case

          0 ---> 1 ---> 3 ---> 4
          |                    ^
          |                    |
          V                    |
          2 -------------------|
        """

        # Clear graph
        self.adj = {}
        self.add_directed_edge(0, 1)
        self.add_directed_edge(0, 2)
        self.add_directed_edge(1, 3)
        self.add_directed_edge(3, 4)
        self.add_directed_edge(2, 4)

        # Mark all the vertices as not visited
        visited = [False] * self.total_vertices

        path = [-1] * self.total_vertices
        path_index = 0

        self.print_all_paths(start, end, visited, path, path_index)

    def print_all_paths(self, start, end, visited, path, path_index):
        """
        Time Complexity: O(n!)
        """
        # Mark the current node as visited and enqueue it
        visited[start] = True
        path[path_index] = start
        path_index += 1

        # Check if we found path
        if start == end:
            for i in range(path_index):
                print(path[i], end=" ")
            print()
        else:
            # Get all adjacent vertices of new start, if not visited then put in queue
            if start in self.adj:
                end_node_list = self.adj[start]

                # if node in end_node_list not visited, add to queue
                for index in range(len(end_node_list)):
                    if not visited[end_node_list[index]]:
                        self.print_all_paths(end_node_list[index], end, visited, path, path_index)
        path_index -= 1
        visited[start] = False
        return

    def BFS(self, graph, start, end, pred):
        """
        Store predecessor of each vertex in array p
        """
        queue = []

        visited = [False] * self.total_vertices

        visited[start] = True
        queue.append(start)

        while len(queue) > 0:
            start = queue.pop(0)

            # Get all adjacent vertices of new start, if not visited then put in queue
            if start in self.adj:
                end_node_list = self.adj[start]

                # if node in end_node_list not visited, add to queue
                for index in range(len(end_node_list)):
                    if not visited[end_node_list[index]]:
                        visited[end_node_list[index]] = True
                        pred[end_node_list[index]] = start
                        queue.append(end_node_list[index])

                        # Check if path found
                        if (end_node_list[index] == end):
                            return True

        print()
        return

    def BFS_shortest_path(self, graph, start, end):
        """
        This algorithm will work even when negative weight cycles are present in the graph.
        Time complexity: O(E + V)

        Steps:
         - store the predecessor of a given vertex while doing the breadth first search.
        """

        # predecessor[i] array stores predecessor of i
        pred = [-1] * self.total_vertices

        if self.BFS(graph, start, end, pred) is False:
            print("Given source and destination are not connected")
            return

        while True:
            if pred[end] == -1:
                print(start, end=" ")
                break
            print(end, end=" ")
            end = pred[end]
        print()
        return


def main():
    total_vertices = 7
    graph = Graph(total_vertices)
    graph.construct_directed_graph()
    graph.print_adj_list()
    graph.BFS_all(graph, 0)
    graph.BFS_path(graph, 0, 4)
    graph.BFS_shortest_path(graph, 0, 4)
    return


if __name__ == '__main__':
    main()

