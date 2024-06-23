# מטלה 1 - גרפים (Classes and Namespaces)

המטרה שלכם במטלה הזאת היא ליצור מחלקה שמייצגת גרף ולממש אלגוריתמים על הגרפים (זה הזמן להזכר בקורס אלגוריתמים 1).

במטלה הזאת הייצוג של הגרף שלכם יתבצע בעזרת מטריצת שכנויות - https://he.wikipedia.org/wiki/%D7%9E%D7%98%D7%A8%D7%99%D7%A6%D7%AA_%D7%A9%D7%9B%D7%A0%D7%95%D7%AA.

הגרף יכול להיות גרף מכוון ולא מכוון וגם גרף ממושקל. מטריצת השכנויות חייבת להיות מטריצה ריבועית.

עליכם לכתוב את הקבצים הבאים:

```
Graph.cpp
Algorithms.cpp
```

הקובץ `Graph.cpp` מכיל מחלקה המייצגת גרף.
המחלקה מכילה את הפעולות `loadGraph` המקבלת מטריצת שכנויות וטוענת אותה לתוך הגרף ו-`printGraph` שמדפיסה את הייצוג של הגרף (הפורמט לבחירתכם, ראו דוגמה ב-`Demo.cpp`).

הקובץ `Algorithms.cpp` מכיל מימושים לאלגוריתמים על גרפים. ביניהם:

- `isConnected(g)` - האלגוריתם מקבל גרף ומחזיר 1 אם הגרף קשיר (אחרת מחזיר 0).
- `shortestPath(g,start,end)` - האלגוריתם מקבל גרף, קודקוד התחלה וקודקוד סיום ומחזיר את המסלול הקל ביותר (במקרה שהגרף לא ממושקל - הקצר ביותר) בין שני הקודקודים. במידה ואין מסלול כזה, האלגוריתם יחזיר -1.
- `isContainsCycle(g)` - האלגוריתם מקבל גרף ומדפיס מעגל כלשהו. אם לא קיים מעגל בגרף, האלגוריתם יחזיר 0.
- `isBipartite(g)` - האלגוריתם מקבל גרף ומחזיר את החלוקה של הגרף לגרף דו-צדדי. אם אי אפשר לחלק את הגרף, האלגוריתם יחזיר 0.
- `negativeCycle(g)` - האלגוריתם מקבל גרף ומוצא מעגל שלילי (כלומר מעגל שסכום המשקלים של הצלעות שלילי). אם לא קיים מעגל כזה, האלגוריתם ידפיס שלא קיים מעגל שלילי.

הקובץ `Demo.cpp` מכיל דוגמאות של קלטים ופלטים.
עליכם לכתוב בתחילת כל קובץ את מספר תעודת הזהות שלכם ואת המייל. כמו כן, בנוסף לקבצים של המטלה אתם נדרשים להגיש גם קובץ README המתאר את אופן המימוש ואת החלוקה שביצעתם בקוד (סוג של מדריך משתמש). אי עמידה בהנחיות תגרור הפחתה בציון. בהצלחה!
  
# Graph Algorithms Project

This project is a C++ implementation of various graph algorithms. The project is divided into two main classes: `Graph` and `Algorithms`.

## Graph Class

The `Graph` class is used to represent a graph using an adjacency matrix. The adjacency matrix is a 2D vector of integers (`vector<vector<int>>`). The class provides several methods to interact with the graph:

- `loadGraph(const vector<vector<int>>& matrix)`: This method is used to initialize the graph with a given adjacency matrix. It checks if the input matrix is a square matrix (i.e., the number of rows is equal to the number of columns). If the matrix is not valid, it throws an `invalid_argument` exception. If the matrix is valid, it assigns the matrix to `adjacencyMatrix` and sets `numVertices` to the size of the matrix.

- `printGraph()`: This method prints the number of vertices and edges in the graph. It calculates the number of edges by counting the non-zero entries in the adjacency matrix. Since the graph is undirected, each edge is counted twice (once for each vertex), so the total count is divided by 2.

- `getAdjacentVertices(int vertex)`: This method returns a vector of vertices that are adjacent to a given vertex. It does this by iterating over the row corresponding to the given vertex in the adjacency matrix and adding the indices of the non-zero entries to the vector.

## Algorithms Class

The `Algorithms` class contains several static functions to perform operations on the graph:

- `isConnected(const Graph& g)`: This method checks if the graph is connected using a breadth-first search (BFS) traversal. It starts from the first vertex and marks it as visited. Then it adds all unvisited adjacent vertices to a queue. This process is repeated until all vertices have been visited. If all vertices are visited, the graph is connected.

- `shortestPath(const Graph& g, int start, int end)`: This method finds the shortest path between two vertices using BFS. It keeps track of the parent of each vertex during the traversal. After reaching the end vertex, it uses the parent information to construct the path from the start vertex to the end vertex.

- `isContainsCycle(const Graph& g)`: This method checks if the graph contains a cycle. It uses a depth-first search (DFS) traversal and keeps track of the vertices currently in the recursion stack (`inStack`). If it encounters a vertex that is in the current recursion stack, it means there is a cycle.

- `isBipartite(const Graph& g)`: This method checks if the graph is bipartite. It uses a BFS traversal and colors the vertices alternatively. If it encounters two adjacent vertices with the same color, it means the graph is not bipartite.

- `negativeCycle(const Graph& g)`: This method uses the Bellman-Ford algorithm to detect negative cycles in the graph.

## Building and Running the Project

The project uses a `Makefile` for building and running. The `Makefile` provides several targets:

- `run`: Runs the `demo` executable.
- `demo`: Builds the `demo` executable.
- `test`: Builds the `test` executable.
- `tidy`: Runs `clang-tidy` on the source files.
- `valgrind`: Runs `valgrind` on the `demo` and `test` executables to check for memory leaks.
- `clean`: Removes all generated files.

To build and run the project, use the following commands:

```bash

make run

# To run the tests
make test

# To run clang-tidy
make tidy

# To run valgrind for memory leaks
make valgrind

# To clean up generated files
make clean  
```

## Testing

The project includes a `test`  executable that runs a series of tests on the graph algorithms. The tests cover various scenarios, such as connected graphs, disconnected graphs, graphs with cycles, bipartite graphs, and graphs with negative cycles.

To run the tests, use the following command:

```bash
make test
```

