#pragma once
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <limits>
#include <string>


using namespace std;

namespace ariel
{class Graph {
    private:
        vector<vector<int>> matrix;

    public:
        void loadGraph(const vector<vector<int>>& input);
        void printGraph() const;
        const vector<vector<int>>& getMatrix() const;
    };

}


