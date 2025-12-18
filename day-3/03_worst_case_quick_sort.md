# Performance of Quick Sort

## Worst Case Time Complexity (DAA)

---

## 1️⃣ Quick Sort performance overview

Quick Sort’s performance depends on **how the pivot divides the array**.

| Case         | Pivot behavior                       | Time Complexity |
| ------------ | ------------------------------------ | --------------- |
| Best Case    | Pivot splits array into equal halves | **O(n log n)**  |
| Average Case | Reasonably balanced splits           | **O(n log n)**  |
| ❌ Worst Case | Pivot always smallest or largest     | **O(n²)**       |

---

## 2️⃣ When does the Worst Case occur?

Worst case happens when:

* Pivot is **always the smallest or largest element**
* Array is **already sorted** (ascending or descending)
* Poor pivot choice (e.g., always choosing first or last element)

👉 Result: **extremely unbalanced partition**

---

## 3️⃣ Why Worst Case is slow (intuition)

Instead of dividing the array into two halves:

```
n → n/2 + n/2
```

Worst case divides it like:

```
n → (n−1) + 0
```

So:

* One subproblem is almost as big as the original
* Recursion becomes **deep (n levels)**

---

## 4️⃣ Worst Case example (step-by-step)

### Given array (already sorted):

```
10, 20, 30, 40, 50
```

Assume:

* Pivot = **first element**

---

### Step 1: First call

Pivot = 10
Partition result:

```
10 | 20, 30, 40, 50
```

Subarrays:

* Left: empty
* Right: size = 4

---

### Step 2: Second call (right subarray)

Pivot = 20

```
20 | 30, 40, 50
```

Subarrays:

* Left: empty
* Right: size = 3

---

### Step 3: Continue…

```
30 | 40, 50
40 | 50
50
```

---

## 5️⃣ Recursion tree (worst case shape)

Instead of a balanced tree, we get a **skewed tree**:

```
T(n)
 |
T(n−1)
 |
T(n−2)
 |
...
 |
T(1)
```

Height of tree = **n**

---

## 6️⃣ Cost at each level

At each level:

* Partition cost = **O(n)**

Total cost:
\[
n + (n-1) + (n-2) + \dots + 1
\]

This sum equals:
\[
\frac{n(n+1)}{2}
\]

---

## 7️⃣ Worst Case Time Complexity

\[
\boxed{O(n^2)}
\]

---

## 8️⃣ Worst Case recurrence relation

\[
T(n) = T(n-1) + cn
\]

This recurrence clearly leads to **quadratic time**.

---

## 9️⃣ Algorithm view (Quick Sort – pivot = first element)

```text
QUICKSORT(A, low, high):
    if low < high:
        p = PARTITION(A, low, high)
        QUICKSORT(A, low, p-1)
        QUICKSORT(A, p+1, high)
```

Worst case happens when:

* `p = low` or `p = high` every time

---

## 🔟 Space Complexity in Worst Case

* Recursion depth = **n**
* Space complexity = **O(n)** (call stack)

---

## 1️⃣1️⃣ How to avoid the Worst Case (theory point)

* Choose **random pivot**
* Use **median-of-three** method
* Avoid fixed pivot selection

---

## 1️⃣2️⃣ One-line exam definition 📝

> **The worst case time complexity of Quick Sort is O(n²), which occurs when the pivot always produces highly unbalanced partitions, such as in already sorted arrays.**

---

## 🧠 Memory Trick

> **Quick Sort worst case = long chain + n work each level = n²**



---
---
---
---
---
---
---
---
---
---
---
---

## Correct understanding (important)

A **sorted array causes worst case ONLY IF the pivot choice is bad**
(e.g., always picking **first** or **last** element).

So the real reason for worst case is:

> ❌ **Bad pivot selection**,
> not “sorted array” itself.

---

## Case-by-case explanation

### 1️⃣ Sorted array + bad pivot → ❌ Worst case

Example:

```
Array: 10 20 30 40 50
Pivot chosen: first element
```

Partition result every time:

```
10 | 20 30 40 50
```

Splits:

```
0 elements + (n−1) elements
```

👉 This repeats → **O(n²)**

So yes:

* **Sorted array**
* **First/last pivot**
  ➡ **Worst case**

---

### 2️⃣ Sorted array + good pivot → ✅ NOT worst case

Same array:

```
10 20 30 40 50
```

If pivot is chosen as:

* middle element (30), or
* random element

Partition becomes:

```
10 20 | 30 | 40 50
```

Splits:

```
n/2 + n/2
```

👉 Time complexity = **O(n log n)**

So:

* Sorted array alone ❌
* Sorted array + smart pivot ✅

---

### 3️⃣ Unsorted array can ALSO give worst case

Example:

```
30, 10, 20, 40, 50
```

If pivot is always chosen badly (smallest/largest each time):

Splits again become:

```
0 + (n−1)
```

👉 **Worst case**, even though array was NOT sorted.

---

## So what ACTUALLY causes worst case?

### ✅ Real cause (memorize this):

> **Worst case occurs when partitioning is extremely unbalanced at every recursive step.**

Sorted input is **just one common example**, not the only one.

---

## Exam-ready statement 📝 (VERY IMPORTANT)

You can write this exactly:

> **A sorted array leads to the worst case of Quick Sort only when a poor pivot selection strategy (such as choosing the first or last element) is used.**

This sentence gets **full marks**.

---

## One-line memory rule 🧠

> **Worst case = bad pivot, not bad input**

---

## Extra (good to know, not mandatory)

That’s why:

* Practical Quick Sort uses **random pivot**
* Or **median-of-three**
* Or **intro sort** (switches algorithm)
