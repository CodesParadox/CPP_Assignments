// Graph.cpp

#include <iostream>
#include <vector>
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <string>
#include <queue>
#include <stdexcept>

using namespace std;

namespace ariel{

    void Graph::loadGraph(const vector<vector<int>>& newMatrix) {
        // Check if the new matrix is square
        size_t numRows = newMatrix.size();
        for (const auto& row : newMatrix) {
            if (row.size() != numRows) {
                throw invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }
        matrix = newMatrix;
    }

    void Graph::printGraph() const {
        cout << "Graph with " << matrix.size() << " vertices and ";
        int edges = 0;
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] != 0) {
                    ++edges;
                }
            }
        }

        cout << edges << " edges." << endl;
    }

    const vector<vector<int>>& Graph::getMatrix() const {
        return matrix;
    }



}
