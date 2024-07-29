#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>

using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    cout << "Graph addition: " << g3.printGraph() << endl;
    CHECK(g3.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");
}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    cout << "Graph multiplication result:\n" << g4.printGraph();
    CHECK(g4.printGraph() == "[0, 0, 2]\n[1, 0, 1]\n[1, 0, 0]");
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    cout << "Attempting invalid multiplication:\n";
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    cout << "Attempting invalid addition:\n";
    CHECK_THROWS(g1 + g6);
}

//  ~~~~~~~~ My tests ~~~~~~~~~~~~~
// *__*

// My tests
TEST_CASE("Graph addition with empty graph")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> emptyGraph = {};
    g2.loadGraph(emptyGraph);
    ariel::Graph g3 = g1 + g2;
    cout << "Graph addition with empty graph result:\n" << g3.printGraph();
    CHECK(g3.printGraph() == "0 1 0\n1 0 1\n0 1 0\n");
}

TEST_CASE("Graph multiplication with identity matrix")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> identityMatrix = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}};
    g2.loadGraph(identityMatrix);
    ariel::Graph g4 = g1 * g2;
    cout << "Graph multiplication with identity matrix result:\n" << g4.printGraph();
    CHECK(g4.printGraph() == "0 1 0\n1 0 1\n0 1 0\n");
}

TEST_CASE("Graph addition with negative weights")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, -1, 0},
            {-1, 0, -1},
            {0, -1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    cout << "Graph addition with negative weights result:\n" << g3.printGraph();
    CHECK(g3.printGraph() == "0 0 1\n0 0 1\n1 1 0\n");
}

TEST_CASE("Graph multiplication with zero matrix")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> zeroMatrix = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};
    g2.loadGraph(zeroMatrix);
    ariel::Graph g4 = g1 * g2;
    cout << "Graph multiplication with zero matrix result:\n" << g4.printGraph();
    CHECK(g4.printGraph() == "0 0 0\n0 0 0\n0 0 0\n");
}

TEST_CASE("Graph addition with different dimensions")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 1},
            {1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    cout << "Attempting addition with different dimensions:\n";
    CHECK_THROWS(g1 + g2);
}