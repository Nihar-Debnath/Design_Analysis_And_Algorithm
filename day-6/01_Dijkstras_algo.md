# # 🚗 **Imagine This Story**

You are standing at your home.

You want to find the **shortest and cheapest route** to go to every other place in your city.

There are roads between places.

Each road has a **distance** (cost).

Example:

* Home → Market = 4 km
* Home → Hospital = 2 km
* Hospital → Market = 1 km
* Market → School = 7 km
  etc.

You want to find:
**minimum distance to reach every place from home**

---

# # ⭐ **This is exactly what Dijkstra's Algorithm does**

It finds:

> **The shortest path from a single starting point to all other nodes in a graph where distances are non-negative.**

Graph = Points + roads
(or Nodes + edges)

---

---

# # 🎯 **Important Things**

✔ Works only for **positive weights** (NON-negative)
✔ Finds **shortest distance** from **one source** to **all vertices**
✔ Greedy approach

(Greedy means: we always choose the best smallest current option)

---

---

# # 🧠 **Core Idea**

Dijkstra keeps 2 things:

### 1️⃣ A distance array

`dist[]` = stores the minimum distance to each node

### 2️⃣ A visited set

to avoid repeating nodes

---

---

# # 🪜 **Step-by-step Working**

Imagine we start at Home.

### Step 0 — Initialization

We set:

\[
dist[\text{Home}] = 0
\]
because distance from Home to Home = 0

All others = infinity (∞)

because we don’t know yet

---

### Step 1 — Pick the nearest unvisited place

(Initially Home)

---

### Step 2 — Relax edges

Relax means:

Try to update distances of connected neighbors if cheaper path is found

Formula:

\[
\text{if } dist[u] + weight(u,v) < dist[v] \Rightarrow \text{ update dist[v]}
\]

---

### Step 3 — Mark u visited

---

### Step 4 — Repeat until all visited

---

---

# # 🏞 Small Visual Example

Graph:

```
A --2--> B
A --4--> C
B --1--> C
B --7--> D
C --3--> D
```

Source = A

| Node | dist |
| ---- | ---- |
| A    | 0    |
| B    | ∞    |
| C    | ∞    |
| D    | ∞    |

---

### After relaxing neighbors of A:

A→B = 2
A→C = 4

| Node | dist |
| ---- | ---- |
| A    | 0    |
| B    | 2    |
| C    | 4    |
| D    | ∞    |

Pick smallest: B

---

Relax neighbors of B:

Compare

B→C:
2 + 1 = 3 ✔ better than 4
update C

B→D:
2 + 7 = 9

| Node | dist |
| ---- | ---- |
| A    | 0    |
| B    | 2    |
| C    | 3    |
| D    | 9    |

Pick smallest: C

---

Relax neighbors of C:

C→D:
3 + 3 = 6 ✔ better than 9

| Node | dist |
| ---- | ---- |
| A    | 0    |
| B    | 2    |
| C    | 3    |
| D    | 6    |

Done 🎉

---

---

# # 🥇 **Final Answer**

Shortest distances from A:

* A → A = 0
* A → B = 2
* A → C = 3
* A → D = 6

---

---

# # 🧾 Summary (short)

### Dijkstra’s Algorithm:

* Finds shortest paths
* From a single source
* To every other node
* In a weighted graph
* Must have non-negative weights
* Uses greedy strategy
* Uses relaxation

---

---

# # 🔥 When to Use?

Use Dijkstra when:

✔ Graph is weighted
✔ All weights ≥ 0
✔ Need shortest path from one node to all nodes

Examples:

* Google Maps routing
* GPS Navigation
* Network routing
* Traffic optimization
* Delivery logistics



---
---
---




# # ✅ **What is Dijkstra’s Algorithm?**

Dijkstra’s Algorithm is a **single-source shortest path algorithm** used to find the **minimum cost (distance)** from a starting node to **every other node** in a weighted graph with **non-negative edge weights**.

---

---

# # 📌 **Where is it used?**

* Google Maps
* GPS navigation
* Network routing
* Delivery shortest route
* Internet packet routing
* Game pathfinding

---

---

# # 🧩 **Concepts Needed**

### ✔ Graph

consisting of:

* vertices (nodes)
* edges (roads)

### ✔ Weight

distance / cost between two nodes

---

---

# # 🗂 **Data Structures Used in Dijkstra**

| Variable                    | Meaning                                            |
| --------------------------- | -------------------------------------------------- |
| `dist[]`                    | stores shortest distance from source to every node |
| `visited[]`                 | stores which nodes are permanently processed       |
| priority queue (in optimal) | helps picking min-distance node fast               |

---

---

# # ⭐ **Algorithm Logic (Formal)**

Dijkstra maintains a distance array:

Initially:

\[
dist[s] = 0
\]

\[
dist[v] = \infty \quad \forall v \ne s
\]

where:

* ( s ) = source vertex
* ( v ) = any vertex

---

Then repeatedly do:

### **Step 1:** pick the **unvisited vertex** with **minimum dist[]**

(call this node ( u ))

### **Step 2:** Mark ( u ) as visited

### **Step 3:** Relax all neighbors ( v ) of ( u )

Relaxation formula:

\[
\text{if } dist[u] + w(u,v) < dist[v] \text{ then update } dist[v]
\]

---

Repeat until all vertices are visited.

---

---

# # 🔁 **Pseudo Code (Simple)**

```text
Dijkstra(G, source):

1) dist[] = INF
2) dist[source] = 0
3) visited[] = false

repeat (V - 1) times:
    pick u with smallest dist[] and not visited
    visited[u] = true
    
    for each neighbor v of u:
        if dist[u] + weight(u, v) < dist[v]:
            dist[v] = dist[u] + weight(u,v)
```

---

---

# # 🧠 Key Idea Simplified

* Take the nearest available node
* Lock it (visited)
* Try to improve distances of its neighbors
* Repeat

Dijkstra is **greedy** because it always picks the lowest distance node available at the moment.

---

---

# # 📦 **Time Complexity**

### Using simple array:

\[
O(V^2)
\]

### Using Min-Heap / Priority Queue:

\[
O((V + E)\log V)
\]

where
( V = \text{number of nodes} )
( E = \text{number of edges} )

---

---

# # ⚠ Important Rule

Dijkstra **does not work** with negative weights.

Why?

Because the greedy choice becomes wrong if negative edges exist.

---

---

# # 🔍 Final Output of Dijkstra

At the end,

`dist[i]` gives the shortest cost from source → i

---

---

# # 📘 Example Output Table

If source is A:

| Node | Shortest Distance |
| ---- | ----------------- |
| A    | 0                 |
| B    | 2                 |
| C    | 3                 |
| D    | 6                 |

---

---

# # 🎯 Key Benefits

✔ Fast
✔ Efficient
✔ Predictable
✔ Perfect for route finding
✔ Easy to implement

---

---

# # ⭐ Summary (Very Short)

```
Dijkstra’s Algorithm finds the shortest distance
from a start node to all other nodes,
in a positive-weight graph,
using greedy relaxation.
```


---
---
---


Let’s take a **very simple example** and walk through Dijkstra’s Algorithm step-by-step


# # 🗺 Example Graph

We have 4 nodes:

A, B, C, D

Connections (with weights):

```
A --4--> C
A --2--> B
B --1--> C
C --3--> D
B --7--> D
```

---

# # 🎯 Source Node = **A**

We want shortest distance from A to all nodes.

---

---

# # 📌 Step 0 — Initialize

| Node | dist |
| ---- | ---- |
| A    | 0    |
| B    | ∞    |
| C    | ∞    |
| D    | ∞    |

---

---

# # 📌 Step 1 — Pick smallest unvisited

= **A**

Neighbors:

A → B = 2
A → C = 4

Update:

| Node | dist |
| ---- | ---- |
| A    | 0    |
| B    | 2    |
| C    | 4    |
| D    | ∞    |

Mark A visited.

---

---

# # 📌 Step 2 — Pick smallest unvisited

= **B** (2)

Neighbors:

B → C = 2 + 1 = 3 ✔ BETTER
B → D = 2 + 7 = 9

Update:

| Node | dist |
| ---- | ---- |
| A    | 0    |
| B    | 2    |
| C    | 3    |
| D    | 9    |

Mark B visited.

---

---

# # 📌 Step 3 — Pick smallest unvisited

= **C** (3)

Neighbors:

C → D = 3 + 3 = 6 ✔ BETTER than 9

Update:

| Node | dist |
| ---- | ---- |
| A    | 0    |
| B    | 2    |
| C    | 3    |
| D    | 6    |

Mark C visited.

---

---

# # 📌 Step 4 — Pick smallest unvisited

= **D**

No updates left.

Mark D visited.

---

---

# # 🏁 FINAL ANSWER

Shortest distances from A:

| Node | dist |
| ---- | ---- |
| A    | 0    |
| B    | 2    |
| C    | 3    |
| D    | 6    |

---

---

# # ⭐ Interpretation

✔ A → B costs **2**

✔ A → C costs **3**
(path = A → B → C)

✔ A → D costs **6**
(path = A → B → C → D)
