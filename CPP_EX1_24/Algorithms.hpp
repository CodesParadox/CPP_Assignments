#pragma once
#include "Graph.hpp"
#include <string>
#include <vector>

using namespace std;
namespace ariel{

    class Algorithms {
    public:
        static bool isConnected(const Graph& g);
        static string shortestPath(const Graph& g, int start, int end);
        static bool isContainsCycle(const Graph& g);
        static string isBipartite(const Graph& g);
        static string negativeCycle(const Graph& g);


    private:
        static bool isContainsCycleUtil(const Graph &g, size_t currVertex, vector<bool> &visited, int parent, string& cyclePath);
        static bool isBipartiteUtil(const Graph& g, size_t currVertex, vector<int>& color);
    };

}