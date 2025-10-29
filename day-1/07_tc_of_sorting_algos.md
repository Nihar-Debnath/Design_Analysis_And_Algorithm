**Time complexities of popular algorithms** (searching, sorting, heap, and graph algorithms).

## 🧠 **Searching and Sorting Algorithms**

| Algorithm                      | Time Complexity                           | Notes / Explanation                                           |
| ------------------------------ | ----------------------------------------- | ------------------------------------------------------------- |
| **Binary Search**              | **O(log₂n)**                              | Efficient search in **sorted array** (divide by 2 each time). |
| **Sequential (Linear) Search** | **O(n)**                                  | Checks elements one by one (unsorted array).                  |
| **Quick Sort**                 | **Average: O(n log n)**, **Worst: O(n²)** | Fast in practice, but depends on pivot choice.                |
| **Merge Sort**                 | **O(n log n)**                            | Always stable and predictable time.                           |
| **Insertion Sort**             | **Average/Worst: O(n²)**, **Best: O(n)**  | Best for small or nearly sorted arrays.                       |
| **Bubble Sort**                | **O(n²)**                                 | Very inefficient; mainly for teaching purposes.               |
| **Heap Sort**                  | **O(n log n)**                            | Based on heap data structure.                                 |
| **Selection Sort**             | **O(n²)**                                 | Simple but inefficient; always O(n²).                         |

---

## ⚙️ **Heap and Graph Algorithms**

| Concept / Algorithm                      | Time Complexity               | Explanation                                                                    |
| ---------------------------------------- | ----------------------------- | ------------------------------------------------------------------------------ |
| **Height of CBT (Complete Binary Tree)** | **O(log n)**                  | Each level doubles number of nodes, so height grows logarithmically.           |
| **Insertion in Heap**                    | **O(log n)**                  | Adjusts heap property by percolating up.                                       |
| **Construct Heap**                       | **O(n)**  | Building heap from array using **heapify** is O(n). (Common mistake in notes.) |
| **Delete from Heap**                     | **O(log n)**                  | Percolate down to restore heap property.                                       |
| **Huffman Coding**                       | **O(n log n)**                | Sorting or using min-heap to build Huffman tree.                               |

---

## 🌐 **Graph Algorithms**

| Algorithm                                    | Time Complexity                                   | Notes                                     |
| -------------------------------------------- | ------------------------------------------------- | ----------------------------------------- |
| **Prim’s Algorithm (Adjacency Matrix)**      | **O(n²)**                                         | For dense graphs (matrix representation). |
| **Prim’s (using Min-Heap + Adjacency List)** | **O((V + E) log V)**                              | For sparse graphs.                        |
| **Kruskal’s Algorithm**                      | **O(E log E)** or **O(E log V)**                  | Sorting edges dominates runtime.          |
| **DFS / BFS**                                | **O(V + E)**                                      | Linear in number of vertices and edges.   |
| **All-Pairs Shortest Path (Floyd–Warshall)** | **O(n³)**                                         | Dynamic programming approach.             |
| **Dijkstra’s Algorithm**                     | **O(V²)** (matrix) or **O((V + E) log V)** (heap) | Depends on implementation type.           |

---

## 🧩 **Modernized Summary**

### 🔍 **Searching Algorithms**

| Algorithm         | Time Complexity |
| ----------------- | --------------- |
| Sequential Search | O(n)            |
| Binary Search     | O(log n)        |

---

### 🔄 **Sorting Algorithms**

| Algorithm      | Best       | Average    | Worst      |
| -------------- | ---------- | ---------- | ---------- |
| Bubble Sort    | O(n)       | O(n²)      | O(n²)      |
| Insertion Sort | O(n)       | O(n²)      | O(n²)      |
| Selection Sort | O(n²)      | O(n²)      | O(n²)      |
| Merge Sort     | O(n log n) | O(n log n) | O(n log n) |
| Quick Sort     | O(n log n) | O(n log n) | O(n²)      |
| Heap Sort      | O(n log n) | O(n log n) | O(n log n) |

---

### 🏗️ **Heap Operations**

| Operation              | Time Complexity |
| ---------------------- | --------------- |
| Height of Heap         | O(log n)        |
| Insertion              | O(log n)        |
| Delete                 | O(log n)        |
| Build (Construct) Heap | O(n)            |

---

### 🌲 **Graph Algorithms**

| Algorithm                                | Time Complexity  |
| ---------------------------------------- | ---------------- |
| DFS / BFS                                | O(V + E)         |
| Prim’s (Matrix)                          | O(V²)            |
| Prim’s (Heap/List)                       | O((V + E) log V) |
| Kruskal’s                                | O(E log E)       |
| Dijkstra’s (Matrix)                      | O(V²)            |
| Dijkstra’s (Heap)                        | O((V + E) log V) |
| Floyd–Warshall (All-Pairs Shortest Path) | O(V³)            |
| Huffman Coding                           | O(n log n)       |
