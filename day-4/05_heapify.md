
# 🔷 Build Heap in **O(n)** Time

### (Heapify Method / Bottom-Up Heap Construction)

---

## 1️⃣ WHAT IS BUILD-HEAP (HEAPIFY METHOD)?

> **Build-Heap** means:
>
> * You already have **all elements in an array**
> * You convert it into a **Max Heap**
> * WITHOUT inserting one-by-one

This is also called:

* **Heapify method**
* **Bottom-Up heap construction**

---

## 2️⃣ WHY “BOTTOM-UP”?

Because:

* **Leaf nodes are already heaps**
* We fix only **internal nodes**
* We go from **last non-leaf node → root**

---

## 3️⃣ LAST NON-LEAF NODE (VERY IMPORTANT)

For array of size `n` (0-based index):

\[
\text{Last non-leaf index} = \left\lfloor \frac{n}{2} \right\rfloor - 1
\]

Why?

* Nodes after this index have **no children**

---

## 4️⃣ ALGORITHM (MAX HEAP)

### 🔹 Build-Heap Steps

1. Find last non-leaf node
2. Call **heapify-down** on each node
3. Move **towards root**

---

### 🔹 Pseudocode (MAX-HEAP)

```text
BUILD_MAX_HEAP(A, n):
    for i = (n/2 - 1) downto 0:
        MAX_HEAPIFY(A, i, n)

MAX_HEAPIFY(A, i, n):
    largest = i
    left = 2*i + 1
    right = 2*i + 2

    if left < n and A[left] > A[largest]:
        largest = left

    if right < n and A[right] > A[largest]:
        largest = right

    if largest != i:
        swap A[i] and A[largest]
        MAX_HEAPIFY(A, largest, n)
```

---

## 5️⃣ FULL EXAMPLE (STEP-BY-STEP)

### Given Array:

```
A = [4, 10, 3, 5, 1]
n = 5
```

### Step 1: Find last non-leaf index

\[
\left\lfloor \frac{5}{2} \right\rfloor - 1 = 1
\]

So we heapify:

```
i = 1 → then i = 0
```

---

## 🔹 Heapify at index 1

```
        4
       / \
     10   3
     / \
    5   1
```

* Node = 10
* Children = 5, 1
* Already MAX heap ✔

Array unchanged:

```
[4, 10, 3, 5, 1]
```

---

## 🔹 Heapify at index 0

```
        4
       / \
     10   3
     / \
    5   1
```

* Largest child = 10
* Swap 4 and 10

```
[10, 4, 3, 5, 1]
```

Now heapify at index 1:

* Children = 5, 1
* Largest = 5
* Swap 4 and 5

```
[10, 5, 3, 4, 1]
```

---

### ✅ Final Max Heap

```
[10, 5, 3, 4, 1]
```

---

## 6️⃣ WHY BUILD-HEAP IS **O(n)**

(This is the MOST important part)

Most students think:

> “Heapify takes O(log n) and runs n times → O(n log n)”

❌ **WRONG**

Because:

* **Not all nodes take O(log n)**

---

## 7️⃣ HEIGHT-WISE ANALYSIS (KEY IDEA)

| Node Level  | Height | Number of Nodes | Cost per node |
| ----------- | ------ | --------------- | ------------- |
| Leaves      | 0      | n/2             | O(1)          |
| Level above | 1      | n/4             | O(1)          |
| Next level  | 2      | n/8             | O(2)          |
| ...         | ...    | ...             | ...           |
| Root        | log n  | 1               | O(log n)      |

---

## 8️⃣ MATHEMATICAL DERIVATION

Total cost:

\[
T(n) = \sum_{h=0}^{\log n} \left(\frac{n}{2^{h+1}} \times h\right)
\]

This sum evaluates to:

\[
T(n) = O(n)
\]

✔ Because:

* Many nodes are **low height**
* Very few nodes go to height `log n`

---

## 9️⃣ INTUITION (EASIEST WAY)

> 🔹 Half the nodes do **zero work**
> 🔹 One-quarter do **1 step**
> 🔹 One-eighth do **2 steps**
> 🔹 Only **one node** does `log n` work

So total work grows **linearly**

---

## 🔟 COMPARISON WITH INSERTION METHOD

| Method               | Time       |
| -------------------- | ---------- |
| Insert one-by-one    | O(n log n) |
| Build-Heap (heapify) | ✅ **O(n)** |

---

## 🧠 ONE-LINE EXAM STATEMENT

> **Build-Heap runs in O(n) time because most heapify calls occur at low heights.**

---

## ✅ FINAL TAKEAWAY

✔ Heapify ≠ insertion
✔ Bottom-up fixing
✔ Uses heapify-down
✔ Time complexity = **O(n)**
✔ VERY IMPORTANT for **GATE / DAA**


---
---
---


# PART 7

## Height-wise Analysis — BEGINNER EXPLANATION

### First: what is **height**?

👉 **Height of a node** =
“How many levels it can go **down** until it reaches a leaf”

Example:

```
        A        ← height = 2
       / \
      B   C      ← height = 1
     / \
    D   E        ← height = 0 (leaf)
```

* Leaves → height **0**
* Their parent → height **1**
* Root → highest height

---

## Now think about a heap (very important picture in your mind)

A **heap is a complete binary tree**, so:

* Bottom level is **full or almost full**
* Upper levels have **very few nodes**

---

## Let total elements = `n`

### 🔹 Leaves (bottom level)

* About **n/2 nodes**
* Height = **0**
* Heapify does **nothing** (no children)

👉 Cost per node = `O(1)`

---

### 🔹 One level above leaves

* About **n/4 nodes**
* Height = **1**
* Can move **at most 1 step down**

👉 Cost per node = `O(1)`

---

### 🔹 Next level

* About **n/8 nodes**
* Height = **2**
* Can move **at most 2 steps down**

👉 Cost per node = `O(2)`

---

### 🔹 Continue like this…

| Level  | Nodes | Height | Work per node |
| ------ | ----- | ------ | ------------- |
| Bottom | n/2   | 0      | 0             |
| Above  | n/4   | 1      | 1             |
| Above  | n/8   | 2      | 2             |
| ...    | ...   | ...    | ...           |
| Root   | 1     | log n  | log n         |

---

## 🔑 IMPORTANT INTUITION

> ❗ **Most nodes are near the bottom**
> ❗ Bottom nodes do **almost no work**
> ❗ Only **few nodes** go high

This is why total time is **NOT n log n**

---

# PART 8

## Mathematical Derivation — BEGINNER WAY

Don’t fear the formula 😄
We’ll build it **step by step**

---

## Step 1: Total Work = sum of (work at each level)

For **each height `h`**:

* Number of nodes = `n / 2^(h+1)`
* Work per node = `h`

So work at height `h`:

\[
\text{Work} = \frac{n}{2^{h+1}} \times h
\]

---

## Step 2: Add work from all heights

Heights go from:

```
0 → log n
```

So total work:

\[
T(n) = \sum_{h=0}^{\log n} \left(\frac{n}{2^{h+1}} \times h\right)
\]

---

## Step 3: Pull out `n` (constant factor)

\[
T(n) = n \sum_{h=0}^{\log n} \frac{h}{2^{h+1}}
\]

Now focus only on:

\[
\sum \frac{h}{2^{h}}
\]

---

## Step 4: VERY IMPORTANT FACT (you must remember)

\[
\sum_{h=0}^{\infty} \frac{h}{2^{h}} = 2
\]

✔ This sum is **constant**
✔ It does **not depend on n**

---

## Step 5: Final Result

\[
T(n) = n \times constant = O(n)
\]

---

# 🧠 SIMPLE REAL-LIFE ANALOGY

Think of a **pyramid**:

* Bottom has **many people**, but they walk **1 step**
* Top has **1 person**, but walks **many steps**

Total walking = **linear**, not quadratic

---

# 🧠 ONE-LINE MEMORY TRICK (VERY IMPORTANT)

> **Heapify is O(n) because most nodes are leaves and do almost no work.**