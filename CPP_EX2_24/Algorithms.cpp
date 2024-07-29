#include "Algorithms.hpp"
#include "Graph.hpp"
#include <queue>
#include <stack>
#include <limits>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>



using namespace std;


namespace ariel{

    bool Algorithms::isConnected(const Graph& g) {
        const auto& matrix = g.getMatrix();
        if (matrix.empty()) return true;
        vector<bool> visited(matrix.size(), false);
        dfs(g, 0, visited);
        return all_of(visited.begin(), visited.end(), [](bool v) { return v; });
    }

    bool Algorithms::dfs(const Graph& g, int v, vector<bool>& visited) {
        visited[v] = true;
        const auto& matrix = g.getMatrix();
        for (size_t i = 0; i < matrix[v].size(); ++i) {
            if (matrix[v][i] && !visited[i]) {
                dfs(g, i, visited);
            }
        }
        return true;
    }

    string Algorithms::shortestPath(const Graph& g, int start, int end) {
        const auto& matrix = g.getMatrix();
        vector<int> dist(matrix.size(), numeric_limits<int>::max());
        vector<int> prev(matrix.size(), -1);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == end) break;

            for (size_t v = 0; v < matrix[u].size(); ++v) {
                if (matrix[u][v] && dist[v] == numeric_limits<int>::max()) {
                    dist[v] = dist[u] + 1;
                    prev[v] = u;
                    q.push(v);
                }
            }
        }

        if (dist[end] == numeric_limits<int>::max()) {
            return "No path exists";
        }

        string path;
        for (int u = end; u != -1; u = prev[u]) {
            path = to_string(u) + (path.empty() ? "" : "->") + path;
        }
        return path;
    }

    bool Algorithms::isContainsCycle(const Graph& g) {
        const auto& matrix = g.getMatrix();
        vector<bool> visited(matrix.size(), false);
        for (size_t i = 0; i < matrix.size(); ++i) {
            if (!visited[i] && hasCycle(g, i, visited, -1)) {
                return true;
            }
        }
        return false;
    }

    bool Algorithms::hasCycle(const Graph& g, int v, vector<bool>& visited, int parent) {
        visited[v] = true;
        const auto& matrix = g.getMatrix();
        for (size_t i = 0; i < matrix[v].size(); ++i) {
            if (matrix[v][i]) {
                if (!visited[i]) {
                    if (hasCycle(g, i, visited, v)) {
                        return true;
                    }
                } else if (i != parent) {
                    return true;
                }
            }
        }
        return false;
    }

    string Algorithms::isBipartite(const Graph& g) {
        const auto& matrix = g.getMatrix();
        vector<int> color(matrix.size(), -1);
        queue<int> q;

        for (size_t start = 0; start < matrix.size(); ++start) {
            if (color[start] == -1) {
                color[start] = 0;
                q.push(start);

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (size_t v = 0; v < matrix[u].size(); ++v) {
                        if (matrix[u][v]) {
                            if (color[v] == -1) {
                                color[v] = 1 - color[u];
                                q.push(v);
                            } else if (color[v] == color[u]) {
                                return "Not bipartite";
                            }
                        }
                    }
                }
            }
        }

        string groupA = "Group A: ", groupB = "Group B: ";
        for (size_t i = 0; i < color.size(); ++i) {
            if (color[i] == 0) {
                groupA += to_string(i) + " ";
            } else {
                groupB += to_string(i) + " ";
            }
        }
        return "Bipartite\n" + groupA + "\n" + groupB;
    }

    string Algorithms::negativeCycle(const Graph& g) {
        const auto& matrix = g.getMatrix();
        vector<int> dist(matrix.size(), numeric_limits<int>::max());
        vector<int> parent(matrix.size(), -1);
        dist[0] = 0;

        for (size_t i = 0; i < matrix.size() - 1; ++i) {
            for (size_t u = 0; u < matrix.size(); ++u) {
                for (size_t v = 0; v < matrix[u].size(); ++v) {
                    if (matrix[u][v] && dist[u] != numeric_limits<int>::max() && dist[u] + matrix[u][v] < dist[v]) {
                        dist[v] = dist[u] + matrix[u][v];
                        parent[v] = u;
                    }
                }
            }
        }

        for (size_t u = 0; u < matrix.size(); ++u) {
            for (size_t v = 0; v < matrix[u].size(); ++v) {
                if (matrix[u][v] && dist[u] != numeric_limits<int>::max() && dist[u] + matrix[u][v] < dist[v]) {
                    string cycle;
                    vector<bool> visited(matrix.size(), false);
                    int curr = v;
                    while (!visited[curr]) {
                        visited[curr] = true;
                        cycle = to_string(curr) + "->" + cycle;
                        curr = parent[curr];
                    }
                    cycle = to_string(curr) + "->" + cycle + to_string(curr);
                    return "Negative cycle found: " + cycle;
                }
            }
        }

        return "No negative cycle found";
    }



//    bool Algorithms::isConnected(const Graph &g) {
//        const auto& matrix = g.getMatrix();
//        if (matrix.empty()) return false;
//        vector<bool> visited(matrix.size(), false);
//        queue<size_t> q;
//        q.push(0);
//        visited[0] = true;
//        size_t numVisited = 1;
//        while (!q.empty()) {
//            size_t curr = q.front(); q.pop();
//            for (size_t neighbor = 0; neighbor < matrix[curr].size(); ++neighbor) {
//                if (matrix[curr][neighbor] && !visited[neighbor]) {
//                    visited[neighbor] = true;
//                    q.push(neighbor);
//                    ++numVisited;
//                }
//            }
//        }
//        return numVisited == matrix.size();
//    }
//
//    string Algorithms::shortestPath(const Graph &g, int start, int end) {
//        const auto& matrix = g.getMatrix();
//        if (start < 0 || static_cast<size_t>(start) >= matrix.size() || end < 0 || static_cast<size_t>(end) >= matrix.size()) {
//            return "Invalid start or end vertex";
//        }
//        vector<bool> visited(matrix.size(), false);
//        queue<pair<int, string>> q;
//        q.push({start, to_string(start)});
//        visited[static_cast<size_t>(start)] = true; // Cast to size_t to avoid signedness conversion warning
//        while (!q.empty()) {
//            pair<int, string> front = q.front(); q.pop();
//            size_t currVertex = static_cast<size_t>(front.first); // Cast to size_t to avoid signedness conversion warning
//            string& currPath = front.second;
//            if (currVertex == static_cast<size_t>(end)) return currPath; // Cast end to size_t
//            for (size_t neighbor = 0; neighbor < matrix[currVertex].size(); ++neighbor) {
//                if (matrix[currVertex][neighbor] && !visited[neighbor]) {
//                    visited[neighbor] = true;
//                    q.push({static_cast<int>(neighbor), currPath + "->" + to_string(neighbor)});
//                }
//            }
//        }
//        cout << "No path exists between " + to_string(start) + " and " + to_string(end) << endl;
//        return "-1";
//    }
//
//    // Adjusted isContainsCycle to use the revised isContainsCycleUtil
//    bool Algorithms::isContainsCycle(const Graph &g) {
//        const auto& matrix = g.getMatrix();
//        vector<bool> visited(matrix.size(), false);
//        string cyclePath; // To store the cycle path if found
//        for (size_t i = 0; i < matrix.size(); ++i) {
//            if (!visited[i]) {
//                if (isContainsCycleUtil(g, i, visited, -1, cyclePath)) {
//                    cout << "Cycle found: " << cyclePath << endl; // Optional: Print the cycle path
//                    return true;
//                }
//            }
//        }
//        return false;
//    }
//
//// Revised isContainsCycleUtil with a bool return type and an additional string reference parameter for the cycle path
//    bool Algorithms::isContainsCycleUtil(const Graph &g, size_t currVertex, vector<bool> &visited, int parent, string& cyclePath) {
//        visited[currVertex] = true;
//        const auto& matrix = g.getMatrix();
//        for (size_t neighbor = 0; neighbor < matrix[currVertex].size(); ++neighbor) {
//            if (matrix[currVertex][neighbor]) {
//                if (!visited[neighbor]) {
//                    cyclePath += to_string(currVertex) + "->" + to_string(neighbor) + ", ";
//                    if (isContainsCycleUtil(g, neighbor, visited, currVertex, cyclePath)) {
//                        return true;
//                    }
//                    // Remove the last part of the path if it leads to a dead end
//                    cyclePath = cyclePath.substr(0, cyclePath.rfind(to_string(currVertex) + "->" + to_string(neighbor)));
//                } else if (neighbor != parent) {
//                    cyclePath += to_string(currVertex) + "->" + to_string(neighbor);
//                    return true; // Cycle detected
//                }
//            }
//        }
//        return false; // No cycle found
//    }
//
//
//    string Algorithms::isBipartite(const Graph &g) {
//        size_t numVertices = g.getMatrix().size();
//        if (numVertices == 0) {
//            return "Graph is empty, cannot determine if it's bipartite.";
//        }
//        vector<int> color(numVertices, -1); // -1: not colored, 0: color 1, 1: color 2
//
//        for (size_t i = 0; i < numVertices; ++i) {
//            if (color[i] == -1) {
//                queue<size_t> q;
//                q.push(i);
//                color[i] = 0; // Start coloring with color 0
//                while (!q.empty()) {
//                    size_t curr = q.front(); q.pop();
//                    for (size_t neighbor = 0; neighbor < g.getMatrix()[curr].size(); ++neighbor) {
//                        if (g.getMatrix()[curr][neighbor]) { // If there's an edge
//                            if (color[neighbor] == -1) { // If not colored, color with opposite color
//                                color[neighbor] = 1 - color[curr];
//                                q.push(neighbor);
//                            } else if (color[neighbor] == color[curr]) { // If neighbor has the same color, not bipartite
//                                cout<< "Graph is not bipartite."<<endl;
//                                return "0";
//                            }
//                        }
//                    }
//                }
//            }
//        }
//
//        // If the graph is bipartite, construct the groups
//        string groupA = "Group A: {", groupB = "Group B: {";
//        for (size_t i = 0; i < numVertices; ++i) {
//            if (color[i] == 0) {
//                groupA += to_string(i) + ", ";
//            } else {
//                groupB += to_string(i) + ", ";
//            }
//        }
//        // Remove trailing comma and space, then close the braces
//        if (!groupA.empty()) groupA.erase(groupA.length() - 2, 2);
//        if (!groupB.empty()) groupB.erase(groupB.length() - 2, 2);
//        groupA += "}";
//        groupB += "}";
//
//        return "Graph is bipartite.\n" + groupA + "\n" + groupB;
//    }
//
//    bool Algorithms::isBipartiteUtil(const Graph &g, size_t currVertex, vector<int> &color) {
//        if (color[currVertex] == -1) color[currVertex] = 0; // Start coloring with 0 if not already colored
//
//        queue<size_t> q;
//        q.push(currVertex);
//
//        while (!q.empty()) {
//            size_t u = q.front(); q.pop();
//
//            // Checking all adjacent vertices
//            for (size_t v = 0; v < g.getMatrix()[u].size(); ++v) {
//                if (g.getMatrix()[u][v]) { // If u and v are connected
//                    if (color[v] == -1) { // If v is not colored
//                        color[v] = 1 - color[u]; // Assign opposite color to adjacent vertex
//                        q.push(v);
//                    } else if (color[v] == color[u]) { // If adjacent vertices have the same color
//                        return false; // Graph is not bipartite
//                    }
//                }
//            }
//        }
//        return true;
//    }
//
//
//    string Algorithms::negativeCycle(const ariel::Graph &g) {
//        // Get the number of vertices in the graph
//        size_t numVertices = g.getMatrix().size();
//
//        // Perform Bellman-Ford algorithm to detect negative cycles
//        vector<int> dist(numVertices, INT_MAX);
//        vector<int> parent(numVertices, -1);
//        dist[0] = 0; //assuming 0 as the starting vertex of the graph
//
//        // Relax edges repeatedly to find shortest distances
//        for (size_t i = 0; i < numVertices - 1; ++i) {
//            for (size_t u = 0; u < numVertices; ++u) {
//                for (size_t v = 0; v < g.getMatrix()[u].size(); ++v) {
//                    if (g.getMatrix()[u][v] && dist[u] != INT_MAX && dist[u] + g.getMatrix()[u][v] < dist[v]) {
//                        dist[v] = dist[u] + g.getMatrix()[u][v];
//                        parent[v] = u;
//                    }
//                }
//            }
//        }
//
//        // Check for negative cycles
//        for (size_t u = 0; u < numVertices; ++u) {
//            const vector<int> &neighbors = g.getMatrix()[u];
//            for (size_t v = 0; v < numVertices; ++v) {
//                if (neighbors[v] != 0) {
//                    if (dist[u] != INT_MAX && dist[u] + neighbors[v] < dist[v]) {
//                        // Negative cycle detected, reconstruct the cycle
//                        vector<int> cycle;
//                        int vertex = static_cast<int>(v);
//                        do {
//                            cycle.push_back(vertex);
//                            vertex = parent[static_cast<vector<int>::size_type>(vertex)];
//                        } while (vertex != static_cast<int>(v));
//
//                        // Format the cycle string
//                        string cycleString;
//                        for (int i = cycle.size() - 1; i >= 0; --i) {
//                            cycleString += to_string(cycle[static_cast<vector<int>::size_type>(i)]);
//                            if (i > 0)
//                                cycleString += "->";
//                        }
//                        cycleString += "->" + to_string(cycle.back());
//
//                        return "Negative cycle found: " + cycleString;
//                    }
//                }
//            }
//        }
//
//        // No negative cycle found
//        return "No negative cycle found in the graph";
//    }



}
