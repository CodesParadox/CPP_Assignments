#include <iostream>
#include <vector>
#ifndef NODE_HPP
#define NODE_HPP
using namespace std;


template<typename T> class Node {
    private:
        T value; // the data of the node
        int maxChild; // max number of children
        vector<Node<T>*> children; // a vector of the node children
    public:
        // Constructor to initialize the node with a value
        explicit Node(T val, vector<Node<T>*> k = {},int maxC = 2) : value(val), children(k), maxChild(maxC) {}

        T get_value(){
            return value;
        }

        vector<Node<T>*> getChildren(){
            return children;
        }

        // Function to add a child node to the current node
        void addChild(Node<T>* node){
            children.push_back(node); 
        }
};

#endif // NODE_HPP