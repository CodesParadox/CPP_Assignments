#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "node.hpp"
#include "iterators.hpp"

using namespace sf;
using namespace std;

template <typename T> class Tree {
    public:
        // Constructor: initializes the tree with a maximum number of children per node (default is 2)
        Tree(int k = 2) : maxChildren(k), root(nullptr) {}

        // Adds a root node to the tree. Throws an exception if the tree already has a root.
        void add_root(Node<T>* node) {
            if (root) {
                throw runtime_error("Tree already has a root");
            } 
            else {
                root = node;
            }
        }
        // Returns the root node of the tree
        Node<T>* getRoot(){
            return root;
        } 

        void displayTree();

        void drawTree(sf::RenderWindow& window, Node<T>* node, const sf::Font& font, int x, int y, unsigned long level = 0);

        // Adds a child node to a parent node. Throws an exception if the parent already has the maximum number of children
        void add_sub_node(Node<T>& parent_node, Node<T>& child_node) {
            if(parent_node.getChildren().size() < maxChildren) {
                parent_node.addChild(&child_node);
                return;
            }
            throw runtime_error("Parent has the maximum number of children");
        }

        // Finds a node in the tree with the given value. Returns a pointer to the node or nullptr if not found
        Node<T>* find_node(Node<T>* node, T value);

        // Returns an iterator to the beginning of a pre-order traversal
        PreOrderIterator<T> begin_pre_order() {
            return PreOrderIterator<T>(root);
        }

        // Returns an iterator to the end of a pre-order traversal
        PreOrderIterator<T> end_pre_order() {
            return PreOrderIterator<T>(nullptr);
        }

        // Returns an iterator to the beginning of a post-order traversal
        PostOrderIterator<T> begin_post_order() {
            return PostOrderIterator<T>(root);
        }

        // Returns an iterator to the end of a post-order traversal
        PostOrderIterator<T> end_post_order() {
            return PostOrderIterator<T>(nullptr);
        }

        // Returns an iterator to the beginning of an in-order traversal
        InOrderIterator<T> begin_in_order() {
            return InOrderIterator<T>(root);
        }

        // Returns an iterator to the end of an in-order traversal
        InOrderIterator<T> end_in_order() {
            return InOrderIterator<T>(nullptr);
        }

        // Returns an iterator to the beginning of a breadth-first search (BFS) traversal
        BFSIterator<T> begin_bfs_scan() {
            return BFSIterator<T>(root);
        }

        // Returns an iterator to the end of a BFS traversal
        BFSIterator<T> end_bfs_scan() {
            return BFSIterator<T>(nullptr);
        }

        // Returns an iterator to the beginning of a depth-first search (DFS) traversal
        DFSIterator<T> begin_dfs_scan() { 
            return DFSIterator<T>(root); 
        }

        // Returns an iterator to the end of a DFS traversal
        DFSIterator<T> end_dfs_scan() { 
            return DFSIterator<T>(nullptr); 
        }

        // A method to perform heap operations on the tree nodes
        void myHeap(){
            if (!root) {
                return;
            }
            queue<Node<T>*> queue;
            queue.push(root);
            while(!queue.empty()){
                auto node = queue.front();
                queue.pop();
                heapify(node);
                for(auto child : node->getChildren()){
                    queue.push(child);
                }
            }
        }

        void heapify(Node<T>* node){
            if (!node) {
                return;
            }
            for(Node<T>* child : node->getChildren()){
                heapify(child);
                if(child->get_value() < node->get_value()){
                    std::swap(child->get_value(), node->get_value());
                }
            }
        }

    private:
        int maxChildren;  // The maximum number of children each node can have.
        Node<T>* root;    // Pointer to the root node of the tree.
};

#endif // TREE_HPP
