"""
Make a simple graph

Do a DFS to get from start to end node and print path
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

    def DFS_all_util(self, graph, start, visited):
        visited[start] = True
        print(start, end=" ")

        if start in self.adj:
            end_node_list = self.adj[start]
            for index in range(len(end_node_list)):
                if not visited[end_node_list[index]]:
                    self.DFS_all_util(graph, end_node_list[index], visited)

    def DFS_all(self, graph, start):
        """
        Print complete DFS of graph from starting node
        V: number of vertices
        E: number of edges
        Time complexity: O(V + E), each edge and vertex combination visited once
        Space complexity: O(V), to hold a visited list and a queue which can have all vertices at once in worst case
        """

        # Mark all the vertices as not visited
        visited = [False] * self.total_vertices

        self.DFS_all_util(graph, start, visited)
        print()

    def DFS_path_util(self, graph, start, end, visited, prev):
        visited[start] = True

        if start in self.adj:
            end_node_list = self.adj[start]
            for index in range(len(end_node_list)):
                if not visited[end_node_list[index]]:
                    prev[end_node_list[index]] = start
                    self.DFS_path_util(graph, end_node_list[index], end, visited, prev)

    def DFS_path(self, graph, start, end):
        # Mark all the vertices as not visited
        visited = [False] * self.total_vertices

        prev = [-1] * self.total_vertices
        self.DFS_path_util(graph, start, end, visited, prev)

        while True:
            if prev[end] == -1:
                print(end, end=" ")
                break
            print(end, end=" ")
            end = prev[end]
        print()
        return


def main():
    total_vertices = 7
    graph = Graph(total_vertices)
    graph.construct_directed_graph()
    graph.DFS_all(graph, 0)
    graph.DFS_path(graph, 1, 5)
    return


if __name__ == '__main__':
    main()

