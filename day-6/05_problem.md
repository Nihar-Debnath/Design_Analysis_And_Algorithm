![](./images/image.png)

---

## Graph (written)

* Nodes: A (source), B, C
* Edges:

  * A → B  weight = **10**
  * B → C  weight = **20**
  * C → B  weight = **−30**

Notice B↔C forms a cycle whose total weight is (20 + (-30) = -10). That is a **negative cycle**.

---

## Question: shortest paths from source A?

We run **Bellman–Ford** (because it handles negative weights and detects negative cycles).

Let `dist[A]=0`, `dist[B]=∞`, `dist[C]=∞`.
There are (V=3) vertices, so we will do (V-1=2) relax iterations, then do one extra to check for negative cycle.

---

# 🌟 Our Graph

From image:

```
A --10--> B --20--> C
            ^     |
            |     |
            \-- -30 /
```

Edges:

| From | To | Weight |
| ---- | -- | ------ |
| A    | B  | +10    |
| B    | C  | +20    |
| C    | B  | −30    |

Source = **A**

---

# ❓ What are we trying to do?

We want shortest distance from A to all other nodes.

We use **Bellman-Ford**.

Because:
✔ It supports negative weights
✔ It detects negative cycles

---

# 👶 Step-0: Start

distances initially:

```
A = 0
B = ∞
C = ∞
```

(∞ means we don’t know yet)

### Why A=0?

Because we start from A.

---

# ❗Important Rule of Bellman-Ford

We update ALL EDGES again and again.

We repeat this **V−1 times**.

Here:

* V = 3 (A,B,C)
* So V−1 = **2**

So we do **2 rounds**.

---

---

# 🟦 ROUND-1 (first full relaxation)

Edges in order:
A→B
B→C
C→B

### Edge A→B

A=0
0 + 10 = **10**
so B becomes 10

```
A=0 B=10 C=∞
```

### Edge B→C

10 + 20 = **30**
so C becomes 30

```
A=0 B=10 C=30
```

### Edge C→B

30 + (-30) = **0**
so B becomes **0**

```
A=0 B=0 C=30
```

✨ End of Round-1

---

---

# 🟦 ROUND-2

Again edges:
A→B
B→C
C→B

### Edge A→B

0 + 10 = 10 → no improvement
so B stays 0

```
A=0 B=0 C=30
```

### Edge B→C

0 + 20 = **20**
so C becomes 20

```
A=0 B=0 C=20
```

### Edge C→B

20 + (-30) = **-10**
so B becomes −10

```
A=0 B=−10 C=20
```

✨ End of Round-2

---

---

# 🔥 IMPORTANT PART

We have completed V−1 = **2** rounds

Distances now:

```
A = 0
B = −10
C = 20
```

BUT…

Bellman-Ford does **1 more round (3rd round)** to test for negative cycle.

---

---

# 🟥 ROUND-3 (check)

Try relaxing edges again.

### Edge B→C:

−10 + 20 = **10**
This IMPROVES C (20 → 10)

👉 That means:
**values are still decreasing**

Which means:

# 🚨 NEGATIVE CYCLE DETECTED

---

---

# 💣 WHY NEGATIVE CYCLE??

Look:

B → C → B

weights = `+20 + (-30)` = **−10**

Every time you go around this cycle,

distance REDUCES more and more:

Round 1 → B = 0
Round 2 → B = −10
Round 3 → B = −20
Round 4 → B = −30
…

it never stops.

so…

**Shortest distance = DOES NOT EXIST**

It goes to **−∞**

---

---

# 🟡 FINAL RESULT

Bellman-Ford says:

There is a **negative cycle reachable from A**.

So shortest distances are not valid.

---

---

# ☑ SUMMARY (SUPER SIMPLE)

* Bellman-Ford tries improving distances
* It improves many times
* After V−1 rounds, we test again
* If distances still improve → negative cycle
* Our graph improves again → negative cycle
* So final answer: **negative cycle exists**
