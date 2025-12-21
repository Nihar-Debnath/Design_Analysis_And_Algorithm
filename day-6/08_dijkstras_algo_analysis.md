# # 🚦 What Dijkstra’s Algorithm Does

Dijkstra’s Algorithm is used to find:

> **the shortest distance from one starting node to every other node in a graph**

(only works if edge weights are positive)

---

---

# # 🧠 Simple Idea Explained

Think like this:

* You start at a source (home).
* You want to go to every destination with **minimum cost** → distance.
* At every step, you choose the **closest unvisited place**.
* Then update its neighbors if you find a cheaper route.

This repeating process is Dijkstra.

---

---

# # 📦 Important Data Structures Used

### 1. **dist[] array**

Stores shortest distance found so far

### 2. **visited[] array**

Keep track of nodes already finalized

### 3. **priority queue (min heap)**

(optional but makes algorithm FAST)

---

---

# # 📌 Dijkstra PSEUDOCODE (VERY SIMPLE)

```sql
function dijkstra(graph, source):

    create array dist[]     // distance to every node
    set all dist = infinity
    dist[source] = 0

    create visited[] = false

    repeat until all nodes are visited:
        
        pick node u with smallest dist[] value
        mark u visited

        for each neighbor v of u:
            if dist[u] + weight(u,v) < dist[v]:
                dist[v] = dist[u] + weight(u,v)

    end
```

```c
Dijkstra(graph, source):

    dist[] = infinity
    dist[source] = 0

    visited[] = false

    repeat V-1 times:

        u = node with minimum dist[] AND not visited
        
        visited[u] = true

        for each neighbor v of u:
            
            if dist[u] + weight(u,v) < dist[v]:
                dist[v] = dist[u] + weight(u,v)
```

That’s the Dijkstra logic.

---

---

# # 🔑 KEY OPERATION → RELAXATION

Relaxation means:

\[
\text{if } dist[u] + w(u,v) < dist[v] \Rightarrow dist[v] = dist[u] + w(u,v)
\]

This is the *heart* of the algorithm.

---

---

# # 🚀 Time Complexity ANALYSIS (Beginner-friendly)

We analyze based on data structure used:

---

# ## ⏳ CASE 1 — Without Priority Queue

(using normal array)

We search minimum node using linear scan

### complexity:

Selecting min node = (O(V))

Repeating this for V nodes:

\[
O(V^2)
\]

👉 Best for small graphs
👉 worst for large graphs

---

---

# ## ⏳ CASE 2 — With Priority Queue (Min-Heap)

Finding smallest distance now becomes fast.

Operations:

* remove min → $(O(\log V))$
* update neighbor → $(O(\log V))$

Total complexity:

\[
O((V + E)\log V)
\]

Where:

* $( V = \text{number of vertices} )$
* $( E = \text{number of edges} )$

👉 this is the **optimal implementation**
👉 used in industry
👉 used in competitive programming

---

---

# ## 🔍 Why is PQ version faster?

Because instead of scanning every time to find minimum,
we pull the smallest quickly from a min-heap.

---

---

# # 📊 Space Complexity

\[
O(V)
\]

because:

* dist array needs V space
* visited array needs V space
* priority queue stores at most V nodes

---

---

# # 🟦 Summary Table

| Implementation | Time Complexity  |
| -------------- | ---------------- |
| Using array    | $(O(V^2))$         |
| Using min-heap | $(O((V+E)\log V))$ |
| Space          | $(O(V))$           |

---

---

# # ⭐ Why Dijkstra is Efficient?

Because it uses a **greedy strategy**:

Always expand the closest remaining unvisited node.

This avoids checking unnecessary paths.



---
---
---


<br>
<br>
<br>

---

# # ✨ FIRST — C CODE (VERY SIMPLE VERSION)

This version uses only arrays
(not priority queue, easier to understand)

```c
#include <stdio.h>
#define INF 999999

int main() {

    int n = 6;   // number of nodes

    int graph[7][7] = {

        // 0, 1,  2,  3,  4,  5,  6
        {0, 0,  0,  0,  0,  0,  0},   // 0 dummy
        {0, 0,  7,  9, INF, INF, 14},
        {0, 7,  0, 10, 15, INF, INF},
        {0, 9, 10,  0, 11, INF,  2},
        {0,INF, 15, 11, 0,  6, INF},
        {0,INF, INF, INF, 6,  0,  9},
        {0,14, INF,  2, INF,  9,  0}
    };

    int dist[7];
    int visited[7];

    // initialize dist[]
    for(int i=1;i<=n;i++){
        dist[i] = INF;
        visited[i] = 0;
    }

    int src = 1;
    dist[src] = 0;

    // MAIN loop
    for(int i=1;i<=n-1;i++){

        // find min unvisited
        int u = -1, min = INF;
        for(int j=1;j<=n;j++){
            if(visited[j]==0 && dist[j] < min){
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        // RELAX neighbors
        for(int v=1;v<=n;v++){
            if(graph[u][v] != INF && visited[v]==0){
                if(dist[u] + graph[u][v] < dist[v]){
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    printf("\nFinal Distances:\n");
    for(int i=1;i<=n;i++){
        printf("1 -> %d = %d\n", i, dist[i]);
    }
}
```

---

---

# # ⚙ Now understand the code:

### dist array

stores best known shortest path

example initial:

```
[∞ ∞ ∞ ∞ ∞ ∞]
```

change source to 0:

```
[0 ∞ ∞ ∞ ∞ ∞]
```

---

---

# # 🧠 visited array

stores yes/no
whether node is finalized

initially:

```
[0 0 0 0 0 0]
```

---

---

# # 🏁 MAIN LOOP (Very Important!)

```
for i = 1 to n-1
```

Why n-1?

Because we finalize **1 node per loop**
and in total only **n nodes**
so only (n-1) iterations needed.

This is the outer stopper.

---

Inside:

### STEP 1: pick smallest dist NOT visited

```
u
```

### STEP 2: mark visited[u] = 1

### STEP 3: relax its neighbors

---

---

# # 🔥 FULL DRY RUN (FROM CODE)

Graph = YOUR GRAPH

Source = 1

---

## INITIAL:

dist:

| node    | 1 | 2 | 3 | 4 | 5 | 6 |
| ------- | - | - | - | - | - | - |
| dist    | 0 | ∞ | ∞ | ∞ | ∞ | ∞ |
| visited | 0 | 0 | 0 | 0 | 0 | 0 |

---

---

# ITERATION-1

pick min → 1

visited[1]=1

neighbors relax:

1→2 = 7
1→3 = 9
1→6 = 14

dist becomes:

| node    | 1 | 2 | 3 | 4 | 5 | 6  |
| ------- | - | - | - | - | - | -- |
| dist    | 0 | 7 | 9 | ∞ | ∞ | 14 |
| visited | 1 | 0 | 0 | 0 | 0 | 0  |

---

---

# ITERATION-2

pick min unvisited → 2

visited[2]=1

neighbors relax:

2→3?   7+10 = 17 > 9   NO
2→4?   7+15 = 22  YES

dist becomes:

| node    | 1 | 2 | 3 | 4  | 5 | 6  |
| ------- | - | - | - | -- | - | -- |
| dist    | 0 | 7 | 9 | 22 | ∞ | 14 |
| visited | 1 | 1 | 0 | 0  | 0 | 0  |

---

---

# ITERATION-3

pick min unvisited → 3

visited[3]=1

neighbors relax:

3→4 = 9 + 11 = 20  YES
3→6 = 9 + 2 = 11   YES

dist:

| node  | 1 | 2 | 3 | 4  | 5 | 6  |
| ----- | - | - | - | -- | - | -- |
| dist  | 0 | 7 | 9 | 20 | ∞ | 11 |
| visit | 1 | 1 | 1 | 0  | 0 | 0  |

---

---

# ITERATION-4

pick min unvisited → 6

visited[6] = 1

neighbors relax:

6→5 = 11 + 9 = 20

dist:

| node  | 1 | 2 | 3 | 4  | 5  | 6  |
| ----- | - | - | - | -- | -- | -- |
| dist  | 0 | 7 | 9 | 20 | 20 | 11 |
| visit | 1 | 1 | 1 | 0  | 1  | 1  |

---

---

# ITERATION-5

pick min unvisited → 4

visited[4]=1

(no changes)

done.

---

---

# FINAL DISTANCES:

| from 1 → | distance |
| -------- | -------- |
| 1        | 0        |
| 2        | 7        |
| 3        | 9        |
| 4        | 20       |
| 5        | 20       |
| 6        | 11       |

---

---

# # 🟦 WHY LOOP STOPS

### Outer loop stops after n-1 = 5 times

because:

every iteration marks 1 node as visited

after 5 iterations → 5 nodes locked

only 1 left

no need last iteration

---

### Inner loop stops

because it checks all neighbors 1…n

---

### relax stops

because when no better path found → nothing updates
