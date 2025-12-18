# Given Recurrence

\[
T(n) = 3T(n/4) + c n^2
\]

---

## Step 1️⃣ What happens at each recursive call?

From **one problem of size `n`**:

* It creates **3 subproblems**
* Each subproblem has size **n/4**
* Extra (non-recursive) work = **c n²**

---

## Step 2️⃣ Level 0 (Root level)

```
                T(n)
             cost = c n²
```

* Number of nodes = 1
* Cost per node = (c n^2)

👉 **Total cost at Level 0**:
\[
c n^2
\]

---

## Step 3️⃣ Level 1

Each `T(n)` creates **3 calls of size n/4**:

```
      T(n/4)     T(n/4)     T(n/4)
    cost = c(n/4)²  each
```

* Number of nodes = 3
* Cost per node = (c (n/4)^2)

👉 **Total cost at Level 1**:
\[
3 \times c \left(\frac{n}{4}\right)^2
= \frac{3c n^2}{16}
\]

---

## Step 4️⃣ Level 2

Each node again creates **3 children**.

* Number of nodes = (3^2 = 9)
* Size of each problem = (n/4^2 = n/16)
* Cost per node = (c (n/16)^2)

👉 **Total cost at Level 2**:
\[
9 \times c \left(\frac{n}{16}\right)^2
= \frac{9c n^2}{256}
\]

---

## Step 5️⃣ Level 3 (pattern continues)

* Nodes = (3^3 = 27)
* Size = (n/4^3)
* Cost per node = (c (n/4^3)^2)

👉 **Total cost**:
\[
27 \times c \frac{n^2}{4^6}
\]

---

## Step 6️⃣ General Level `i` (MOST IMPORTANT)

At **level `i`**:

| Quantity        | Value         |
| --------------- | ------------- |
| Number of nodes | (3^i)         |
| Problem size    | (n/4^i)       |
| Cost per node   | (c (n/4^i)^2) |

👉 **Total cost at level `i`**:
\[
3^i \cdot c \cdot \frac{n^2}{4^{2i}}
= c n^2 \left(\frac{3}{16}\right)^i
\]

---

## Step 7️⃣ What does this tell us about levels?

* Each deeper level costs **less than the previous one**
* Cost shrinks by factor **3/16**
* So **top levels dominate**

This is the key insight.

---

## Step 8️⃣ How many levels are there?

Problem size reduces like:
\[
n \rightarrow \frac{n}{4} \rightarrow \frac{n}{16} \rightarrow \dots
\]

Stop when:
\[
\frac{n}{4^k} = 1
\]

\[
k = \log_4 n
\]

So total levels = **log₄ n**

---

## 🧠 Memory Summary

* Level 0 has **highest cost**
* Each level costs **much less**
* Tree depth = **log₄ n**
* Total work is dominated by **top level(s)**