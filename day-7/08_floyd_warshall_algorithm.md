# 🌍 All-Pairs Shortest Path (APSP)

## 1️⃣ What does “All-Pairs Shortest Path” mean?

Simple meaning:

> Find the **shortest distance between EVERY pair of vertices** in a graph.

Not:

* From one source to all (that’s Dijkstra)

But:

* From **every city to every other city**

---

### Real-life example 🚍

Cities:

```
A, B, C, D
```

You want to know:

* Shortest A → B
* Shortest A → C
* Shortest B → A
* Shortest C → D
  👉 **All combinations**

---

## 2️⃣ When do we use Floyd–Warshall?

Use Floyd–Warshall when:

* Graph is **small or medium**
* You want **shortest paths between all pairs**
* Graph can have **negative edges**
* But **NO negative cycles**

---

## 3️⃣ Core idea (THIS IS THE CONCEPT)

Instead of finding paths one by one…

Floyd–Warshall asks a **simple question repeatedly**:

> “Is going **through this node** better than going directly?”

That’s it. That’s the whole algorithm.

---

## 4️⃣ Small Example Graph 🧩

Vertices:

```
A, B, C
```

Edges:

```
A → B = 4
A → C = 11
B → C = 2
```

---

### Step 1: Initial distance table

Think of a table:

| From\To | A | B | C  |
| ------- | - | - | -- |
| **A**   | 0 | 4 | 11 |
| **B**   | ∞ | 0 | 2  |
| **C**   | ∞ | ∞ | 0  |

(∞ means no direct road)

---

## 5️⃣ Floyd–Warshall thinking (VERY IMPORTANT)

We pick **one node at a time** as a **middle stop**.

### Question asked every time:

> Is
> `i → k → j`
> cheaper than
> `i → j`?

---

## 6️⃣ Iteration 1: Use A as middle

Check:

* B → A → C? ❌ (no B → A)
* A → A → C? no change

👉 Table unchanged

---

## 7️⃣ Iteration 2: Use B as middle

Check:

* A → B → C
  = 4 + 2 = **6**

Compare with:

* A → C = 11

✅ 6 is smaller → update

New table:

| From\To | A | B | C     |
| ------- | - | - | ----- |
| **A**   | 0 | 4 | **6** |
| **B**   | ∞ | 0 | 2     |
| **C**   | ∞ | ∞ | 0     |

---

## 8️⃣ Iteration 3: Use C as middle

No shorter paths found.

---

## 9️⃣ Final Result 🎉

Now table contains:

> Shortest distance between **every pair**

Example:

* A → C shortest = 6
* B → C shortest = 2

---

## 🔁 Why this works (intuition)

At each step:

* You allow one more city as a possible **middle stop**
* Gradually, all possible middle stops are allowed
* Finally, you get **optimal paths**

---

## 10️⃣ Formal Algorithm Idea

For each node `k`:

* For every pair `(i, j)`:

  * Check if going via `k` is shorter

---

## 11️⃣ Time Complexity (TC)

There are:

* 3 loops (i, j, k)

[
\boxed{TC = O(V^3)}
]

---

## 12️⃣ Space Complexity (SC)

Distance matrix:

[
\boxed{SC = O(V^2)}
]

---

## 13️⃣ Comparison with other algorithms

| Algorithm      | Type                           |
| -------------- | ------------------------------ |
| Dijkstra       | Single source                  |
| Bellman-Ford   | Single source (negative edges) |
| Floyd-Warshall | **All pairs**                  |

---

## 🔑 One-line intuition (MEMORIZE THIS)

> **Floyd–Warshall keeps checking whether using an intermediate vertex gives a shorter path between two vertices.**

---

## 📝 Exam-ready definition

> Floyd–Warshall is a dynamic programming algorithm used to find shortest paths between all pairs of vertices in a weighted graph.
