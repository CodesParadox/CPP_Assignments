#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <iterator>
#include <memory>
#include <algorithm>

template <typename T>
class Tree;

using namespace std;

// Pre-order traversal iterator for the Tree class
template <typename T> 
class PreOrderIterator {
public:
    // Constructor: initializes the stack with the root node if it exists
    explicit PreOrderIterator(Node<T>* root) {
        if(root){ 
            stack.push(root);
        }
    }

    // Inequality operator: checks if the iterator has more nodes to traverse
    bool operator!=(const PreOrderIterator& other) const {
        return !stack.empty();
    }

    // Prefix increment operator: advances the iterator to the next node
    PreOrderIterator& operator++() {
        if (stack.empty()) {
            return *this;
        }
        
        Node<T>* node = stack.top();
        stack.pop();
        // Iterate over children and push non-null children to the stack
        for (size_t i = node->getChildren().size(); i > 0; --i) {
            Node<T>* n = node->getChildren().at(i - 1);
            if (n != nullptr) { // Check if the child is non-null before pushing
                stack.push(n);
            }
        }
        return *this;
    }

    // Arrow operator: returns a pointer to the current node
    Node<T>* operator->() const {
        return stack.top();
    }

private:
    stack<Node<T>*> stack; // Stack to manage nodes during traversal
};

// In-order traversal iterator for the Tree class
template <typename T> 
class InOrderIterator {
public:
    // Constructor: initializes the stack by pushing all left children of the root
    explicit InOrderIterator(Node<T>* root) {
        pushLeft(root);
    }

    // Inequality operator: checks if the iterator has more nodes to traverse
    bool operator!=(const InOrderIterator& other) const {
        return !(*this == other);
    }

    // Equality operator: checks if two iterators are at the same position
    bool operator==(const InOrderIterator& other) const {
        return nodes == other.nodes;
    }

    // Dereference operator: returns a reference to the current node
    Node<T>& operator*() const {
        return *nodes.top();
    }

    // Prefix increment operator: advances the iterator to the next node
    InOrderIterator& operator++() {
        if (!nodes.empty()) {
            Node<T>* current = nodes.top();
            nodes.pop();
            if (!current->getChildren().empty()) {
                pushLeft(current->getChildren()[1]);
            }
        }
        return *this;
    }

    // Arrow operator: returns a pointer to the current node
    Node<T>* operator->() const {
        return nodes.top();
    }

private:
    stack<Node<T>*> nodes; // Stack to manage nodes during traversal

    // Helper function to push all left children of a node onto the stack
    void pushLeft(Node<T>* node) {
        while (node) {
            nodes.push(node);
            if (!node->getChildren().empty()) {
                node = node->getChildren()[0];
            } 
            else {
                break;
            }
        }
    }
};

// Post-order traversal iterator for the Tree class
template <typename T>
class PostOrderIterator {
public:
    // Constructor: initializes the iterator by finding the first leaf node
    explicit PostOrderIterator(Node<T>* root) {
        if (root) {
            findNextLeaf(root);
            fillStack();
        }
    }

    // Inequality operator: checks if the iterator has more nodes to traverse
    bool operator!=(const PostOrderIterator& other) const {
        return !(*this == other);
    }

    // Equality operator: checks if two iterators are at the same position
    bool operator==(const PostOrderIterator& other) const {
        return nodes == other.nodes;
    }

    // Arrow operator: returns a pointer to the current node
    Node<T>* operator->() const {
        return nodes.top();
    }

    // Dereference operator: returns a reference to the current node
    Node<T>& operator*() const {
        return *nodes.top();
    }

    // Prefix increment operator: advances the iterator to the next node
    PostOrderIterator& operator++() {
        if (!nodes.empty()) {
            nodes.pop();
        }
        return *this;
    }

private:
    stack<Node<T>*> nodes;      // Stack to manage nodes during traversal
    stack<Node<T>*> tempStack;  // Temporary stack used for reverse traversal

    // Helper function to find the next leaf node
    void findNextLeaf(Node<T>* node) {
        if (!node) {
            return;
        }
        nodes.push(node);
        vector<Node<T>*> children = node->getChildren();
        for (auto it = children.rbegin(); it != children.rend(); ++it) {
            findNextLeaf(*it);
        }
    }

    // Helper function to fill the main stack in reverse order
    void fillStack() {
        while (!nodes.empty()) {
            Node<T>* current = nodes.top();
            nodes.pop();
            tempStack.push(current);
        }
        while (!tempStack.empty()) {
            nodes.push(tempStack.top());
            tempStack.pop();
        }
    }
};

// Breadth-first search (BFS) traversal iterator for the Tree class
template <typename T> 
class BFSIterator {
public:
    // Constructor: initializes the queue with the root node if it exists
    explicit BFSIterator(Node<T>* root) {
        if (root) {
            nodes.push(root);
        }
    }

    // Arrow operator: returns a pointer to the current node
    Node<T>* operator->() const {
        return nodes.front();
    }

    // Dereference operator: returns a reference to the current node
    Node<T>& operator*() const {
        return *nodes.front();
    }

    // Inequality operator: checks if the iterator has more nodes to traverse
    bool operator!=(const BFSIterator& other) const {
        return !(*this == other);
    }

    // Equality operator: checks if two iterators are at the same position
    bool operator==(const BFSIterator& other) const {
        return nodes == other.nodes;
    }

    // Prefix increment operator: advances the iterator to the next node
    BFSIterator& operator++() {
        if (!nodes.empty()) {
            Node<T>* current = nodes.front();
            nodes.pop();
            for (auto& child : current->getChildren()) {
                if (child) {
                    nodes.push(child);
                }
            }
        }
        return *this;
    }

private:
    queue<Node<T>*> nodes; // Queue to manage nodes during traversal
};

// Depth-first search (DFS) traversal iterator for the Tree class
template <typename T>
class DFSIterator {
public:
    // Constructor: initializes the stack with the root node if it exists
    explicit DFSIterator(Node<T>* root) {
        if (root) {
            nodes.push(root);
        }
    }

    // Arrow operator: returns a pointer to the current node
    Node<T>* operator->() const {
        return nodes.top();
    }

    // Dereference operator: returns a reference to the current node
    Node<T>& operator*() const {
        return *nodes.top();
    }

    // Inequality operator: checks if the iterator has more nodes to traverse
    bool operator!=(const DFSIterator& other) const {
        return !(*this == other);
    }

    // Equality operator: checks if two iterators are at the same position
    bool operator==(const DFSIterator& other) const {
        return nodes == other.nodes;
    }

    // Prefix increment operator: advances the iterator to the next node
    DFSIterator& operator++() {
        if (!nodes.empty()) {
            Node<T>* current = nodes.top();
            nodes.pop();
            for (auto& child : current->getChildren()) {
                if (child) {
                    nodes.push(child);
                }
            }
        }
        return *this;
    }

private:
    stack<Node<T>*> nodes; // Stack to manage nodes during traversal
};

#endif // ITERATORS_HPP
