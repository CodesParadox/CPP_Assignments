// Algorithms.cpp
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <queue>
#include <stack>
#include <limits>
#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

namespace ariel {

    bool Algorithms::isConnected(const Graph &g)
    {
        size_t numVertices = g.getMatrix().size();
        if (numVertices == 0)
            return false; // Empty graph is not connected
        vector<bool> visited(numVertices, false);
        queue<size_t> q;
        q.push(0); // Start from vertex 0
        visited[0] = true;
        size_t numVisited = 1;
        while (!q.empty())
        {
            size_t currVertex = q.front();
            q.pop();
            const vector<int> &neighbors = g.getMatrix()[currVertex];
            for (size_t neighbor = 0; neighbor < neighbors.size(); ++neighbor)
            {
                if (neighbors[neighbor] && !visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                    ++numVisited;
                }
            }
        }
        return numVisited == numVertices;
    }

    string Algorithms::shortestPath(const Graph &g, int start, int end)
    {
        size_t numVertices = g.getMatrix().size();
        if (start < 0 || start >= static_cast<int>(numVertices) || end < 0 || end >= static_cast<int>(numVertices))
        {
            return "Invalid start or end vertex";
        }
        vector<bool> visited(numVertices, false);
        queue<pair<int, string>> q;        // (vertex, path)
        q.push({start, to_string(start)}); // Start with the start vertex
        visited[static_cast<vector<bool>::size_type>(start)] = true;
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int currVertex = curr.first;
            string currPath = curr.second;
            if (currVertex == end)
            {
                return currPath; // Return the path if the end vertex is reached
            }
            const vector<int> &neighbors = g.getMatrix()[static_cast<vector<vector<int>>::size_type>(currVertex)];
            for (size_t neighbor = 0; neighbor < neighbors.size(); ++neighbor)
            {
                if (neighbors[neighbor] && !visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push({static_cast<int>(neighbor), currPath + "->" + to_string(neighbor)});
                }
            }
        }
        std::cout << "No path exists between " + to_string(start) + " and " + to_string(end) << endl;
        return "-1";
    }

    bool Algorithms::isContainsCycle(const Graph &g)
    {
        size_t numVertices = g.getMatrix().size();
        vector<bool> visited(numVertices, false);
        string cycle;
        for (size_t i = 0; i < numVertices; ++i)
        {
            if (!visited[i])
            {
                cycle = isContainsCycleUtil(g, i, visited, -1);
                if (!cycle.empty())
                {
                    cout << cycle << endl;
                    return true; // Return the first cycle found
                }
            }
        }
        return false; //"No cycle found in the graph";
    }

    string Algorithms::isContainsCycleUtil(const Graph &g, size_t currVertex, vector<bool> &visited, int parent)
    {
        visited[currVertex] = true;
        const vector<int> &neighbors = g.getMatrix()[currVertex];
        for (size_t neighbor = 0; neighbor < neighbors.size(); ++neighbor)
        {
            int isConnectedNeighbor = neighbors[neighbor];
            if (isConnectedNeighbor)
            {
                if (!visited[neighbor])
                {
                    string subCycle = isContainsCycleUtil(g, neighbor, visited, currVertex);
                    if (!subCycle.empty())
                    {
                        if (subCycle[0] != '-')
                        {
                            return to_string(currVertex) + "->" + subCycle; // Return the cycle path
                        }
                        else if (currVertex != stoi(subCycle.substr(subCycle.find_last_of("->") + 1)))
                        {
                            return to_string(currVertex) + "->" + subCycle; // Found a cycle including the current vertex
                        }
                    }
                }
                else if (neighbor != parent && (parent == -1 || neighbor != parent))
                {
                    return to_string(currVertex) + "->" + to_string(neighbor); // Found a cycle on undirective graph
                }
                else if (visited[neighbor] && neighbor != parent)
                {
                    return to_string(currVertex) + "->" + to_string(neighbor); // Found a cycle on directive graph
                }
            }
        }
        return ""; // No cycle found
    }

    string Algorithms::isBipartite(const Graph &g)
    {
        size_t numVertices = g.getMatrix().size();
        if (numVertices == 0)
            return "0"; // Empty graph is not Bipartite
        vector<int> color(numVertices, -1); // -1: not colored, 0: color 1, 1: color 2
        for (size_t i = 0; i < numVertices; ++i)
        {
            if (color[i] == -1)
            {
                if (!isBipartiteUtil(g, i, color))
                {
                    return "0";
                }
            }
        }
        string groupA = "{";
        string groupB = "{";
        for (size_t i = 0; i < numVertices; ++i)
        {
            if (color[i] == 0)
            {
                groupA += to_string(i) + ", ";
            }
            else
            {
                groupB += to_string(i) + ", ";
            }
        }
        groupA.pop_back();
        groupA.pop_back();
        groupB.pop_back();
        groupB.pop_back();
        groupA += "}";
        groupB += "}";
        return "The graph is bipartite: A=" + groupA + ", B=" + groupB;
    }

    bool Algorithms::isBipartiteUtil(const Graph &g, size_t currVertex, vector<int> &color)
    {
        queue<size_t> q;
        q.push(currVertex);
        color[currVertex] = 0; // Color the current vertex with color 0
        while (!q.empty())
        {
            size_t curr = q.front();
            q.pop();
            const vector<int> &neighbors = g.getMatrix()[curr];
            for (size_t neighbor = 0; neighbor < neighbors.size(); ++neighbor)
            {
                if (neighbors[neighbor])
                {
                    if (color[neighbor] == -1)
                    {
                        color[neighbor] = 1 - color[curr]; // Assign the opposite color to the neighbor
                        q.push(neighbor);
                    }
                    else if (color[neighbor] == color[curr])
                    {
                        return false; // Graph is not bipartite
                    }
                }
            }
        }
        return true;
    }

    string Algorithms::negativeCycle(const ariel::Graph &g)
    {
        // Get the number of vertices in the graph
        size_t numVertices = g.getMatrix().size();

        // Perform Bellman-Ford algorithm to detect negative cycles
        vector<int> dist(numVertices, INT_MAX);
        vector<int> parent(numVertices, -1);

        // Start from any vertex (0th vertex here)
        size_t source = 0;
        dist[source] = 0;

        // Relax edges repeatedly to find shortest distances
        for (std::size_t i = 0; i < numVertices - 1; ++i)
        {
            for (std::size_t u = 0; u < numVertices; ++u)
            {
                const vector<int> &neighbors = g.getMatrix()[u];
                for (std::size_t v = 0; v < numVertices; ++v)
                {
                    if (neighbors[v] != 0)
                    {
                        if (dist[u] != INT_MAX && dist[u] + neighbors[v] < dist[v])
                        {
                            dist[v] = dist[u] + neighbors[v];
                            parent[v] = u;
                        }
                    }
                }
            }
        }

        // Check for negative cycles
        for (std::size_t u = 0; u < numVertices; ++u)
        {
            const vector<int> &neighbors = g.getMatrix()[u];
            for (std::size_t v = 0; v < numVertices; ++v)
            {
                if (neighbors[v] != 0)
                {
                    if (dist[u] != INT_MAX && dist[u] + neighbors[v] < dist[v])
                    {
                        // Negative cycle detected, reconstruct the cycle
                        vector<int> cycle;
                        int vertex = static_cast<int>(v);
                        do
                        {
                            cycle.push_back(vertex);
                            vertex = parent[static_cast<std::vector<int>::size_type>(vertex)];
                        } while (vertex != static_cast<int>(v));

                        // Format the cycle string
                        string cycleString;
                        for (int i = cycle.size() - 1; i >= 0; --i)
                        {
                            cycleString += to_string(cycle[static_cast<std::vector<int>::size_type>(i)]);
                            if (i > 0)
                                cycleString += "->";
                        }
                        cycleString += "->" + to_string(cycle.back());

                        return "Negative cycle found: " + cycleString;
                    }
                }
            }
        }

        // No negative cycle found
        return "No negative cycle found in the graph";
    }

}