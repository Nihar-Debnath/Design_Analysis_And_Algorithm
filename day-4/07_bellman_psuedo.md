# 🔹 Bellman-Ford Algorithm

**(Concept, Pseudocode & Time Complexity)**

### – SUPER Beginner Explanation –

---

---

# 🟦 What Bellman-Ford Does?

* Finds **shortest path** from **1 start/source node**
* Works even if graph has **negative weights**
* Detects **negative cycles**

---

---

# 🟦 Key Idea

We relax (update) every edge **again and again**.

We do this **V−1 times**
(where V = number of nodes)

Because shortest path can have **at most V−1 edges**.

---

---

---

# 🟦 Bellman-Ford PSEUDOCODE

(super simple version, no complexity brain melt)

```c
function BellmanFord(Graph, source):

    set distance of every node = infinity
    set distance[source] = 0

    repeat V-1 times:
        for every edge (u, v, w):
            if distance[u] + w < distance[v]:
                distance[v] = distance[u] + w

    // extra check:
    for every edge (u, v, w):
        if distance[u] + w < distance[v]:
            print "Negative cycle exists"
            exit

    print all distances
```

---

---

# 🟦 Explanation of Pseudocode

(beginner)

1. First we assume every node’s distance is **∞**
2. Source distance becomes **0**
3. We repeat UPDATE step V−1 times
4. Each time, we check every edge, to see if we got a shorter path
5. After V−1 rounds, distances must be final
6. Then we check ONCE MORE to detect negative cycle

---

---

# 🟦 WHY RELAX EDGES?

Relax means:

If going through **u** makes **v** shorter,
then update **v**.

Example:

```
distance[v] = min(distance[v], distance[u] + weight)
```

---

---

# 🟦 TIME COMPLEXITY (SUPER SIMPLE)

### Graph has:

* V = nodes
* E = edges

We run relaxation:

* across **every edge**
* **V−1 times**

So:

\[
O(V-1) * O(E)
= O(VE)
\]

---

---

# 🟥 FINAL TIME COMPLEXITY

| Operation            | Complexity   |
| -------------------- | ------------ |
| Main relaxation      | **O(V × E)** |
| Negative cycle check | **O(E)**     |

So total:

\[
\boxed{O(VE)}
\]

---

---

# 🟩 SPACE COMPLEXITY

\[
O(V)
\]

Just stores distance array.

---

---

# 🟦 Why slower than Dijkstra?

Because:

Dijkstra = **O(E log V)**

Bellman-Ford = **O(VE)** (much slower)

But Bellman-Ford can handle negative weights.

---

---

# ⭐ SUPER SIMPLE SUMMARY

| Feature                     | Bellman-Ford |
| --------------------------- | ------------ |
| Negative weights allowed    | ✔            |
| Negative cycle detect       | ✔            |
| Uses V−1 loops              | ✔            |
| Time complexity             | **O(VE)**    |
| Faster/slower than Dijkstra | slower       |
