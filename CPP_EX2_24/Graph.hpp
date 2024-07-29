#pragma once
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <limits>
#include <string>
#include <iostream>


using namespace std;

namespace ariel
{
    class Graph {
     private:
        vector<vector<int>> matrix;

     public:
        Graph(); // Default constructor
        void loadGraph(const vector<vector<int>>& input);
        string printGraph() const; // change the graph to string and return it
        const vector<vector<int>>& getMatrix() const;



        //Arithmetic operators
        Graph operator+(const Graph& other) const; // Binary plus => graph1 + graph2
        Graph& operator+=(const Graph& other); // graph1 += graph2
        Graph operator+() const; // Unary plus
        Graph operator-() const; // Unary minus
        Graph operator-(const Graph& other) const;
        Graph& operator-=(const Graph& other);



        // Comparison operators
        bool operator==(const Graph& other) const;
        bool operator!=(const Graph& other) const;
        bool operator<(const Graph& other) const;
        bool operator<=(const Graph& other) const;
        bool operator>(const Graph& other) const;
        bool operator>=(const Graph& other) const;

        // Increment and decrement operators
        Graph& operator++();    // Prefix increment
        Graph operator++(int);  // Postfix increment
        Graph& operator--();    // Prefix decrement
        Graph operator--(int);  // Postfix decrement

         // Scalar multiplication
         Graph operator*(int scalar) const; // graph * int number
         Graph& operator*=(int scalar); // graph *= int number
         Graph operator/(int scalar) const;
         Graph& operator/=(int scalar);

         // Graph multiplication
         Graph operator*(const Graph& other) const; // graph * graph
         Graph& operator*=(const Graph& other); // graph1 *= graph2


         // Output operator
         friend ostream& operator<<(ostream& os, const Graph& graph); // print the graph
         friend istream& operator>>(istream& is, Graph& graph); // read the graph
};

}


