```markdown
# Graph Algorithms Assignment

## Overview

This project implements various graph algorithms and operations using C++. The primary components include:

1. **Graph Class**: Represents a graph using an adjacency matrix.
2. **Algorithms Class**: Implements various graph algorithms such as checking connectivity, finding shortest paths, detecting cycles, and more.
3. **Unit Tests**: Uses the `doctest` framework to test the functionality of the graph operations and algorithms.

## Files

- `Graph.hpp`: Header file for the `Graph` class.
- `Graph.cpp`: Implementation file for the `Graph` class.
- `Algorithms.hpp`: Header file for the `Algorithms` class.
- `Algorithms.cpp`: Implementation file for the `Algorithms` class.
- `Test.cpp`: Contains unit tests for the graph operations and algorithms.
- `Makefile`: Build script to compile the project.

## Graph Class

The `Graph` class provides the following functionalities:

- **Loading a Graph**: Load a graph from a 2D vector.
- **Printing a Graph**: Convert the graph to a string representation.
- **Arithmetic Operations**: Add, subtract, and multiply graphs.
- **Comparison Operations**: Compare graphs for equality and inequality.
- **Increment/Decrement Operations**: Increment and decrement the values in the graph.
- **Scalar Multiplication**: Multiply the graph by a scalar value.
- **Graph Multiplication**: Multiply two graphs.
- **Input/Output Operations**: Read and write graphs using streams.

## Algorithms Class

The `Algorithms` class provides the following functionalities:

- **isConnected**: Check if the graph is connected.
- **shortestPath**: Find the shortest path between two vertices.
- **isContainsCycle**: Check if the graph contains a cycle.
- **isBipartite**: Check if the graph is bipartite.
- **negativeCycle**: Detect if the graph contains a negative cycle.

## Unit Tests

The unit tests are written using the `doctest` framework and cover various scenarios for graph operations and algorithms. The tests are located in the `Test.cpp` file.

## Building the Project

To build the project, use the provided `Makefile`. The `Makefile` includes targets for compiling the source files, running the tests, and cleaning up the build artifacts.

### Makefile Targets

- **run**: Build and run the main executable.
- **demo**: Build the demo executable.
- **test**: Build and run the unit tests.
- **tidy**: Run code tidying tools.
- **valgrind**: Run the executables with Valgrind for memory checking.
- **clean**: Remove the build artifacts.

### Example Usage

To build and run the project, use the following commands:

```sh
make run
```

To run the unit tests:

```sh
make test
```

To clean the build artifacts:

```sh
make clean
```

## Dependencies

- **C++ Compiler**: The project uses `clang` with C++11 standard.
- **doctest**: A lightweight C++ testing framework.
- **Valgrind**: A tool for memory debugging, memory leak detection, and profiling.


