"""
Simple Djakstra's algo
"""

# -*- encoding: utf-8 *-*

import sys
import json

class Node():
    def __init__(self, data):
        self.data = data

class Graph():
    def __init__(self):
        self.adj = {}
        self.total_vertices = 7

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

    def construct_directed_graph(self):
        #    1   2   3
        #  4/|
        #  / |
        # 0  |11      8       4
        #  \ |
        #  8\|
        #    7   6   5
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

    def min_distance(self, dist, sptSet):
        min_dist_index = -1
        min = sys.maxint

        for i in range(len(dist)):
            if dist[i] <= min and sptSet[i] == False:
                min_dist_index = i
                min = dist[i]

        return min_dist_index

    def djakstra(self, graph, src):
        # dist[i] will hold the shortest distance from src to i
        dist = [sys.maxint] * self.total_vertices
        dist[src] = 0

        # sptSet[i] will be True if vertex i is included in shortest
        # path tree or shortest distance from src to i is finalized
        sptSet = [False] * self.total_vertices

        for i in range(self.total_vertices - 1):
            # Pick the minimum distance vertex from the set of vertices not
            # yet processed. u is always equal to src in the first iteration
            u = self.min_distance(dist, sptSet)

            # Mark the current node as processed
            sptSet[u] = True

            # update distance of adjacent vertices
            if u in self.adj:
                adjacent_vertices = self.adj[u]
                for idx in range(len(adjacent_vertices)):
                    neighbor = adjacent_vertices[idx]
                    if (not sptSet[neighbor]) and (dist[neighbor] != max) and (dist[u] + neighbor < dist[neighbor]):
                        dist[neighbor] = dist[u] + neighbor


        for idx in range(len(dist)):
            print(idx, " ", dist[idx])

        return


def main():
    graph = Graph()
    graph.construct_directed_graph()
    graph.djakstra(graph, 0)
    return

if __name__ == '__main__':
    main()

