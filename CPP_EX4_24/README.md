# Tree Class

## Description
The `Tree` class in C++ implements a tree data structure where each node can have multiple children. It supports various operations such as adding nodes, finding nodes, and iterating through the tree using different traversal methods.

## Class Structure

### Constructor
- `Tree(int k = 2)`: Constructs a tree with a maximum of `k` children per node. By default, `k` is set to 2.

### Public Methods

#### `void add_root(Node<T>* node)`
Adds a root node to the tree. If the tree already has a root, it prints an error message.

#### `Node<T>* getRoot()`
Returns the root node of the tree.

#### `void add_sub_node(Node<T>& parent_node, Node<T>& child_node)`
Adds a child node to a parent node in the tree. Throws a `runtime_error` if the parent node already has the maximum allowed children.

#### `Node<T>* find_node(Node<T>* node, T value)`
Searches for a node with the given value in the tree and returns it.

#### Iterators
The class provides iterators for different tree traversal methods:
- `begin_pre_order()`, `end_pre_order()`: Pre-order traversal iterators.
- `begin_post_order()`, `end_post_order()`: Post-order traversal iterators.
- `begin_in_order()`, `end_in_order()`: In-order traversal iterators.
- `begin_bfs_scan()`, `end_bfs_scan()`: Breadth-first search (BFS) scan iterators.
- `begin_dfs_scan()`, `end_dfs_scan()`: Depth-first search (DFS) scan iterators.

#### `void myHeap()`
Performs a heapification operation on the tree. It uses a queue-based approach to traverse the tree level by level and heapify each node.

### Private Members
- `int maxChildren`: Maximum number of children allowed per node in the tree.
- `Node<T>* root`: Pointer to the root node of the tree.

**

# Node Class

The `Node` class represents a node in a tree structure. Each node contains a value of type `T`, can have multiple children stored in a vector, and has a maximum limit on the number of children it can have (`maxChild`). This class provides basic functionalities to manipulate and access nodes in a tree.

## Overview

The `Node` class includes:
- **Data Members**:
  - `value`: Holds the data associated with the node.
  - `maxChild`: Specifies the maximum number of children the node can have.
  - `children`: A vector storing pointers to child nodes.

- **Constructor**:
  - `Node(T val, vector<Node<T>*> k = {}, int maxC = 2)`: Initializes a node with a value `val`, an optional vector of children `k`, and a maximum child limit `maxC`.

- **Member Functions**:
  - `get_value()`: Returns the value stored in the node.
  - `getChildren()`: Returns a vector of pointers to child nodes.
  - `addChild(Node<T>* node)`: Adds a child node to the current node's children vector.

**

# Tree Iterators

This C++ header file (`iterators.hpp`) provides various iterators for traversing a tree structure implemented using the `Node` class. The iterators support different traversal methods including pre-order, in-order, post-order, breadth-first search (BFS), and depth-first search (DFS).

## PreOrderIterator Class

### Description
- **Traversal Method**: Starts at the root and visits each node before its children.
- **Initialization**: Initializes with the root node using a stack for iterative traversal.

### Methods
- `operator!=`: Checks if the current iterator is not equal to another iterator.
- `operator++`: Moves the iterator to the next node in pre-order.
- `operator->`: Returns a pointer to the current node.

## InOrderIterator Class

### Description
- **Traversal Method**: Visits nodes in ascending order of keys (left to right).
- **Initialization**: Starts from the leftmost node and uses a stack for iterative traversal.

### Methods
- `operator!=`: Checks if the current iterator is not equal to another iterator.
- `operator++`: Moves the iterator to the next node in in-order.
- `operator->`: Returns a pointer to the current node.

## PostOrderIterator Class

### Description
- **Traversal Method**: Visits each node after all of its children have been visited.
- **Initialization**: Starts from the root and uses two stacks for iterative traversal.

### Methods
- `operator!=`: Checks if the current iterator is not equal to another iterator.
- `operator++`: Moves the iterator to the next node in post-order.
- `operator->`: Returns a pointer to the current node.

## BFSIterator Class

### Description
- **Traversal Method**: Visits nodes level by level, starting from the root.
- **Initialization**: Uses a queue for breadth-first traversal.

### Methods
- `operator!=`: Checks if the current iterator is not equal to another iterator.
- `operator++`: Moves the iterator to the next node in BFS.
- `operator->`: Returns a pointer to the current node.

## DFSIterator Class

### Description
- **Traversal Method**: Visits nodes depth by depth, starting from the root.
- **Initialization**: Uses a stack for depth-first traversal.

### Methods
- `operator!=`: Checks if the current iterator is not equal to another iterator.
- `operator++`: Moves the iterator to the next node in DFS.
- `operator->`: Returns a pointer to the current node.


**

# Tree Visualization with SFML

This C++ program visualizes tree structures using SFML (Simple and Fast Multimedia Library). It provides a graphical representation of trees with nodes and edges, demonstrating different tree structures and their visualization.

## Overview

The program includes functionalities to:
- Create and manipulate binary and 3-ary trees.
- Visualize tree structures using circles for nodes and lines for connections between parent and child nodes.
- Utilize SFML for graphical rendering and user interface.

## Dependencies

- SFML Library: Provides graphics rendering, event handling, and window management.
- `node.hpp`: Defines the `Node` class for tree nodes.
- `tree.hpp`: Implements the `Tree` class for tree operations.
- Font File: Uses a font file (`Roboto-Black.ttf`) for text rendering.

## How to Build and Run

1. **Install SFML**: Ensure SFML is installed on your system. If not, download and install it from [SFML Downloads](https://www.sfml-dev.org/download.php).

2. **Compile the Program**:
   - Use a C++ compiler that supports C++11 or later.
   - Link against SFML libraries (`sfml-graphics`, `sfml-window`, `sfml-system`).
   - Include necessary header files (`SFML/Graphics.hpp`, `iostream`, `vector`, `string`, etc.).

3. **Run the Program**:
   - Execute the compiled executable.
   - The program will open a window displaying the tree structure.
   - Close the window to exit the program.

## Functionality

### Tree Creation and Visualization

- **Binary Tree**:
  - Creates a binary tree structure with nodes containing double values.
  - Uses SFML to draw nodes as circles and connects them with lines.

- **3-ary Tree**:
  - Creates a 3-ary tree structure with nodes containing double values.
  - Visualizes the tree structure with SFML, allowing for easy traversal and visualization of nodes and connections.

### User Interface

- **Window Management**:
  - Opens an SFML window for graphical display.
  - Handles user events, such as window closing, through SFML event polling.



