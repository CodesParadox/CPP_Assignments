#pragma once
#include "Graph.hpp"
#include <string>
#include <vector>

using namespace std;
namespace ariel{
    class Algorithms {
        // using operators functions to compare the graphs and return the result
    public:
        static bool isConnected(const Graph& g);
        static string shortestPath(const Graph& g, int start, int end);
        static bool isContainsCycle(const Graph& g);
        static string isBipartite(const Graph& g);
        static string negativeCycle(const Graph& g);



        // using the following functions to check if the graph contains a cycle or is bipartite
    private:
        static bool dfs(const Graph& g, int v, vector<bool>& visited);
        static bool hasCycle(const Graph& g, int v, vector<bool>& visited, int parent);
//        static bool isContainsCycleUtil(const Graph &g, size_t currVertex, vector<bool> &visited, int parent, string& cyclePath);
//        static bool isBipartiteUtil(const Graph& g, size_t currVertex, vector<int>& color);




    };

}


