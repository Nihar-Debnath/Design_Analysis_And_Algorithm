## Introduction to All-Pairs Shortest Path (Floyd–Warshall Algorithm)

### 1️⃣ What is the **All-Pairs Shortest Path (APSP)** problem?

The APSP problem asks:

> **What is the shortest distance between *every pair* of vertices in a graph?**

So instead of finding a path from **one source** to all others (like Dijkstra), we find shortest paths **between all possible pairs** of nodes.

---

### 2️⃣ Where does **Floyd–Warshall** fit?

The **Floyd–Warshall algorithm** is a classic solution to the APSP problem.

It is:

* **Dynamic Programming–based**
* Works on **weighted graphs**
* **Allows negative edge weights**
* **Does NOT allow negative cycles**

---

### 3️⃣ When should you use Floyd–Warshall?

Use it when:

* You need shortest paths between **all pairs**
* Number of vertices is **small to medium**
* Graph can be **dense**
* Simplicity is preferred over performance

Avoid it when:

* Graph is very large (because of high time complexity)

---

### 4️⃣ Core idea (very important 🔑)

Floyd–Warshall works by **gradually allowing more intermediate vertices** in the paths.

Think like this:

> “Is the shortest path from `i` to `j` better if I allow vertex `k` as an intermediate point?”

Mathematically:

[
dist[i][j] = \min(dist[i][j],; dist[i][k] + dist[k][j])
]

This single formula is the **heart** of the algorithm.

---

### 5️⃣ Step-by-step intuition (beginner friendly)

1. Start with a **distance matrix**

   * `dist[i][j]` = weight of edge from `i` to `j`
   * If no edge → ∞
   * `dist[i][i] = 0`

2. Pick an intermediate vertex `k`

3. For every pair `(i, j)`:

   * Check if going `i → k → j` is shorter than current `i → j`

4. Update the distance

5. Repeat for all vertices as `k`

---

### 6️⃣ Algorithm structure (loop order matters!)

```text
for k = 1 to V:
    for i = 1 to V:
        for j = 1 to V:
            dist[i][j] = min(dist[i][j],
                              dist[i][k] + dist[k][j])
```

👉 The outermost loop **must be `k`**, because we are *adding one allowed intermediate vertex at a time*.

---

### 7️⃣ Time & Space Complexity

| Metric           | Value     |
| ---------------- | --------- |
| Time Complexity  | **O(V³)** |
| Space Complexity | **O(V²)** |

That’s why it’s best for **small graphs**.

---

### 8️⃣ Graph types supported

✅ Directed graph
✅ Undirected graph
✅ Weighted graph
⚠️ Negative weights allowed
❌ Negative cycles not allowed

---

### 9️⃣ How to detect a negative cycle?

After running the algorithm:

* If **`dist[i][i] < 0`** for any vertex `i`
  👉 A **negative cycle exists**

---

### 🔟 Real-life analogy 🌍

Imagine cities and travel costs:

* You initially know only **direct roads**
* You then ask:

  > “Is it cheaper to go from City A to City C via City B?”
* You keep checking with **every city as a stopover**
* Finally, you know the **cheapest route between all cities**

---

### 1️⃣1️⃣ Floyd–Warshall vs other algorithms

| Algorithm          | Shortest Path Type                       |
| ------------------ | ---------------------------------------- |
| Dijkstra           | Single-source                            |
| Bellman–Ford       | Single-source (negative weights allowed) |
| **Floyd–Warshall** | **All-pairs**                            |

---

### 1️⃣2️⃣ Summary (remember this 💡)

* Floyd–Warshall solves **All-Pairs Shortest Path**
* Uses **dynamic programming**
* Simple but **O(V³)** time
* Allows negative edges
* Detects negative cycles
* Best for **small dense graphs**

---