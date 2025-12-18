# Example: Recursion Tree Method

## Given recurrence

\[
T(n) = 2T(n/2) + n
\]

This is a **classic divide & conquer** recurrence.

---

## Step 1️⃣ Understand the meaning (before drawing)

This says:

* One problem of size `n`
* Break it into **2 subproblems**, each of size `n/2`
* Do extra work = `n`

---

## Step 2️⃣ Draw the recursion tree (mentally)

### Level 0 (root)

```
            T(n)
           cost = n
```

---

### Level 1

Each `T(n)` creates **2** calls of size `n/2`:

```
        T(n/2)      T(n/2)
        cost n/2    cost n/2
```

Total cost at level 1:
\[
n/2 + n/2 = n
\]

---

### Level 2

Each `T(n/2)` creates **2** calls of size `n/4`
Total nodes = 4

```
T(n/4) T(n/4) T(n/4) T(n/4)
 cost n/4 each
```

Total cost:
\[
4 \times \frac{n}{4} = n
\]

---

### Level 3

Nodes = 8, each of size `n/8`

Total cost:
\[
8 \times \frac{n}{8} = n
\]

---

## Step 3️⃣ Observe the pattern (IMPORTANT)

👉 **Every level costs `n`**

So the tree looks like:

| Level | Total Cost |
| ----- | ---------- |
| 0     | n          |
| 1     | n          |
| 2     | n          |
| 3     | n          |
| …     | n          |

---

## Step 4️⃣ Count number of levels

Problem size keeps halving:

\[
n \rightarrow n/2 \rightarrow n/4 \rightarrow n/8 \rightarrow \dots
\]

We stop when size becomes **1**.

Number of levels:
\[
\log n
\]

---

## Step 5️⃣ Add total cost

\[
\text{Total} = n + n + n + \dots (\log n \text{ times})
\]

\[
\boxed{T(n) = n \log n}
\]

---

## Step 6️⃣ Final Answer

\[
\boxed{T(n) = \Theta(n \log n)}
\]

---

## Step 7️⃣ Intuition (MOST IMPORTANT)

* Work per level = **constant (`n`)**
* Number of levels = **log n**
* So total = **n log n**

---

## 🧠 Memory rule

> **Same work per level × log levels = n log n**