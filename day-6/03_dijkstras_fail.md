# ❓ Why does Dijkstra FAIL on Negative Weights?

Because the **core logic** of Dijkstra assumes something that is FALSE when negative weights exist.

That assumption is:

> 📌 **Once we pick the smallest distance node, that distance is FINAL and cannot improve later.**

This is TRUE only when all weights are **positive**

But…

If there is a negative weight later in the graph,

then a supposedly “final" shortest distance
can actually become **smaller later**, which breaks everything.

---

---

# ⭐ Key Idea

Dijkstra makes a *greedy decision*:

✔ pick lowest distance node
✔ never revisit it

But with negative edges,

you **might find a cheaper way later**,
after passing a negative edge.

Thus greedy logic collapses.

---

---

# 🔥 VERY SIMPLE Example

Graph:

```
A → B  (4)
A → C  (1)
C → B (-3)
```

We start at **A**

---

## **Step 1**: Initialization

| Node | dist |
| ---- | ---- |
| A    | 0    |
| B    | ∞    |
| C    | ∞    |

---

## **Step 2**: Relax neighbors of A

A → B = 4
A → C = 1

| Node | dist |
| ---- | ---- |
| A    | 0    |
| C    | 1    |
| B    | 4    |

Now smallest unvisited = **C**

---

## **Step 3**: Go to C

From C → B weight = −3

So new cost to B:

\[
1 + (-3) = -2
\]

So B becomes **−2**

| Node | dist |
| ---- | ---- |
| A    | 0    |
| C    | 1    |
| B    | -2   |

---

BUT WAIT…

Dijkstra **already "finalized" B earlier with 4**,
and will NOT fix it.

So Dijkstra gives WRONG result.

Correct shortest path:

A → C → B = -2

But Dijkstra wrongly gives:

A → B = 4

---

---

# 🎯 Why exactly did it fail?

Because:

Dijkstra assumed B’s shortest path was known
BEFORE checking the negative edge.

But negative edge changed everything later.

---

---

# 🧨 Deep Truth:

Dijkstra FAILS when:

✔ negative edges exist
✔ negative cycles exist

Bellman-Ford works
because it **revisits edges multiple times**,
NOT greedy.

---

---

# 🏁 Summary

| Algorithm      | Negative edges? | Works?  |
| -------------- | --------------- | ------- |
| Dijkstra       | ❌ No            | ❌ fails |
| Bellman–Ford   | ✔ Yes           | ✔ works |
| Floyd-Warshall | ✔ Yes           | ✔ works |
