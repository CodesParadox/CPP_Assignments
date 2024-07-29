#include "Graph.hpp"
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <limits>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <climits>
#include <sstream>

using namespace std;
//we added the following operators to the algorithms class:
//1. operator+=
//2. operator-=
//3. operator*
//4. operator<<
//5. operator>>
//6. operator bool
//7. operator==
namespace ariel {
    Graph::Graph() {
        matrix = vector<vector<int>>();
    }

    void Graph::loadGraph(const vector<vector<int>>& input) {
        matrix = input;
    }

    string Graph::printGraph() const {
        stringstream ss;
        for (const auto& row : matrix) {
            ss << "[";
            for (size_t i = 0; i < row.size(); ++i) {
                ss << row[i];
                if (i < row.size() - 1) ss << ", ";
            }
            ss << "]\n";
        }
        return ss.str();
    }

    const vector<vector<int>>& Graph::getMatrix() const {
        return matrix;
    }

    Graph Graph::operator+(const Graph& other) const {
        if (matrix.size() != other.matrix.size() || matrix[0].size() != other.matrix[0].size()) {
            throw invalid_argument("Matrices must have the same dimensions");
        }
        Graph result;
        result.matrix = matrix;
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[i].size(); ++j) {
                result.matrix[i][j] += other.matrix[i][j];
            }
        }
        return result;
    }

    Graph& Graph::operator+=(const Graph& other) {
        *this = *this + other;
        return *this;
    }

    Graph Graph::operator-() const {
        Graph result;
        result.matrix = matrix;
        for (auto& row : result.matrix) {
            for (auto& elem : row) {
                elem = -elem;
            }
        }
        return result;
    }

    Graph Graph::operator-(const Graph& other) const {
        return *this + (-other);
    }

    Graph& Graph::operator-=(const Graph& other) {
        *this = *this - other;
        return *this;
    }

    bool Graph::operator==(const Graph& other) const {
        return matrix == other.matrix;
    }

    bool Graph::operator!=(const Graph& other) const {
        return !(*this == other);
    }

    bool Graph::operator<(const Graph& other) const {
        if (matrix.size() != other.matrix.size()) {
            return matrix.size() < other.matrix.size();
        }
        return matrix < other.matrix;
    }

    bool Graph::operator<=(const Graph& other) const {
        return *this < other || *this == other;
    }

    bool Graph::operator>(const Graph& other) const {
        return !(*this <= other);
    }

    bool Graph::operator>=(const Graph& other) const {
        return !(*this < other);
    }

    Graph& Graph::operator++() {
        for (auto& row : matrix) {
            for (auto& elem : row) {
                ++elem;
            }
        }
        return *this;
    }

    Graph Graph::operator++(int) {
        Graph temp = *this;
        ++(*this);
        return temp;
    }

    Graph& Graph::operator--() {
        for (auto& row : matrix) {
            for (auto& elem : row) {
                --elem;
            }
        }
        return *this;
    }

    Graph Graph::operator--(int) {
        Graph temp = *this;
        --(*this);
        return temp;
    }

    Graph Graph::operator*(int scalar) const {
        Graph result;
        result.matrix = matrix;
        for (auto& row : result.matrix) {
            for (auto& elem : row) {
                elem *= scalar;
            }
        }
        return result;
    }

    Graph& Graph::operator*=(int scalar) {
        *this = *this * scalar;
        return *this;
    }

    Graph Graph::operator/(int scalar) const {
        if (scalar == 0) {
            throw invalid_argument("Division by zero");
        }
        Graph result;
        result.matrix = matrix;
        for (auto& row : result.matrix) {
            for (auto& elem : row) {
                elem /= scalar;
            }
        }
        return result;
    }

    Graph& Graph::operator/=(int scalar) {
        *this = *this / scalar;
        return *this;
    }

    Graph Graph::operator*(const Graph& other) const {
        if (matrix[0].size() != other.matrix.size()) {
            throw invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
        }
        Graph result;
        result.matrix = vector<vector<int>>(matrix.size(), vector<int>(other.matrix[0].size(), 0));
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < other.matrix[0].size(); ++j) {
                for (size_t k = 0; k < matrix[0].size(); ++k) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return result;
    }

    Graph& Graph::operator*=(const Graph& other) {
        *this = *this * other;
        return *this;
    }

    ostream& operator<<(ostream& os, const Graph& graph) {
        for (const auto& row : graph.matrix) {
            for (const auto& elem : row) {
                os << elem << " ";
            }
            os << endl;
        }
        return os;
    }

    istream& operator>>(istream& is, Graph& graph) {
        vector<vector<int>> newMatrix;
        string line;
        while (getline(is, line)) {
            istringstream iss(line);
            vector<int> row;
            int elem;
            while (iss >> elem) {
                row.push_back(elem);
            }
            newMatrix.push_back(row);
        }
        graph.loadGraph(newMatrix);
        return is;
    }

}
