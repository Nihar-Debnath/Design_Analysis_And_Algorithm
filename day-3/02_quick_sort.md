# Quick Sort | Divide and Conquer | DAA

---

## 1️⃣ What is Quick Sort?

**Quick Sort** is a **sorting algorithm** based on the **Divide and Conquer technique**.

It sorts an array by:

* choosing a **pivot element**
* placing the pivot in its **correct position**
* ensuring:

  * elements smaller than pivot go to the **left**
  * elements larger than pivot go to the **right**

Then it repeats the same process on left and right parts.

---

## 2️⃣ Why is it called “Quick” Sort?

Because:

* In **average cases**, it is **very fast**
* It usually performs better than Merge Sort in practice
* It works **in-place** (no extra array)

---

## 3️⃣ Divide and Conquer in Quick Sort (VERY IMPORTANT)

Quick Sort perfectly follows the **3 steps of Divide and Conquer**:

### 🔹 1. Divide

Partition the array around a **pivot**
→ elements are divided into two parts

### 🔹 2. Conquer

Recursively apply Quick Sort on:

* left sub-array
* right sub-array

### 🔹 3. Combine

Nothing special to combine
👉 array is already sorted in place

---

## 4️⃣ The role of the Pivot (core concept)

A **pivot** is:

* any element chosen from the array
* its job is to go to the **correct sorted position**

Pivot can be:

* first element
* last element
* middle element
* random element

⚠️ Pivot choice affects performance (important for DAA).

---

## 5️⃣ How partitioning works (idea only)

Partitioning means:

* move all smaller elements to one side
* move all larger elements to the other side
* pivot ends up in between

After partition:

* pivot is in its **final position**
* it will never move again

---

## 6️⃣ Example (step-by-step, simple)

### Given array:

```
[10, 80, 30, 90, 40, 50, 70]
```

Assume **last element (70)** is pivot.

---

### Step 1: Partition

After partitioning around pivot 70:

```
[10, 30, 40, 50 | 70 | 80, 90]
```

* Pivot 70 is now in correct position
* Left part: smaller elements
* Right part: larger elements

---

### Step 2: Recursive calls

Apply Quick Sort on:

Left sub-array:

```
[10, 30, 40, 50]
```

Right sub-array:

```
[80, 90]
```

---

### Step 3: Continue until base case

* Sub-array of size 0 or 1 → already sorted
* Recursion stops

Final sorted array:

```
[10, 30, 40, 50, 70, 80, 90]
```

---

## 7️⃣ Recurrence Relation of Quick Sort (DAA view)

General form:
[
T(n) = T(k) + T(n-k-1) + cn
]

Where:

* `k` = number of elements smaller than pivot
* `cn` = partitioning cost

This shows Quick Sort is **divide and conquer**, but **not always balanced**.

---

## 8️⃣ Performance of Quick Sort (VERY IMPORTANT)

### 🔹 Best Case

Pivot divides array into **two equal halves** every time.

Recurrence:
[
T(n) = 2T(n/2) + cn
]

⏱ Time Complexity:
[
\boxed{O(n \log n)}
]

---

### 🔹 Average Case (most practical case)

Pivot divides array **reasonably well** (not perfect).

⏱ Time Complexity:
[
\boxed{O(n \log n)}
]

This is why Quick Sort is popular.

---

### 🔹 Worst Case (IMPORTANT FOR EXAMS)

Worst case happens when:

* pivot is always smallest or largest
* array is already sorted
* bad pivot selection

Recurrence:
[
T(n) = T(n-1) + cn
]

⏱ Time Complexity:
[
\boxed{O(n^2)}
]

---

## 9️⃣ Space Complexity

* Uses recursion stack
* Best / Average: **O(log n)**
* Worst case: **O(n)**

Quick Sort is **in-place**, unlike Merge Sort.

---

## 🔟 Advantages of Quick Sort

✅ Very fast in practice
✅ In-place sorting
✅ Cache-friendly
✅ Widely used

---

## 1️⃣1️⃣ Disadvantages of Quick Sort

❌ Worst-case O(n²)
❌ Performance depends on pivot choice
❌ Not stable (by default)

---

## 1️⃣2️⃣ Quick Sort vs Merge Sort (short)

| Quick Sort         | Merge Sort            |
| ------------------ | --------------------- |
| In-place           | Needs extra space     |
| Faster in practice | Guaranteed O(n log n) |
| Worst case O(n²)   | Always O(n log n)     |

---

## 1️⃣3️⃣ One-line exam definition 📝

> **Quick Sort is a divide and conquer sorting algorithm that partitions an array around a pivot and recursively sorts the sub-arrays.**

---

## 🧠 Memory Trick

> **Pick pivot → partition → recurse → sorted**



---
---
---
---


# Given array

```
35, 50, 15, 25, 80, 20, 90, 45, +∞
```

We will solve it using **Quick Sort (Divide & Conquer)**
Assume the **FIRST element is the pivot**
and we use the **Hoare-style partition idea** (common in theory).

---

## 1️⃣ Why is `+∞` written at the end? (VERY IMPORTANT)

Before sorting, understand this first 👇

### Purpose of `+∞` (sentinel)

* `+∞` is a **sentinel value**
* It is **not part of the data**
* It helps **avoid array bound checking**

In partition:

* One pointer moves from **left to right**
* One pointer moves from **right to left**
* `+∞` guarantees:

  * the right pointer **will always stop**
  * no “index out of bounds” error

👉 In theory/DAA, `+∞` simplifies explanation
👉 In real code, we usually **don’t add it explicitly**

---

## 2️⃣ Initial setup

Array:

```
35, 50, 15, 25, 80, 20, 90, 45, +∞
```

* **Pivot = 35** (first element)
* `i` starts from left
* `j` starts from right

Goal:

* elements < pivot → left
* elements > pivot → right

---

## 3️⃣ Partitioning step (main step)

### Step A: Move `i` to the right

Find element **greater than pivot (35)**

* 50 → stop (50 > 35)

### Step B: Move `j` to the left

Find element **smaller than pivot**

* 45 → not smaller
* 90 → not smaller
* 20 → stop (20 < 35)

### Step C: Swap 50 and 20

Array becomes:

```
35, 20, 15, 25, 80, 50, 90, 45, +∞
```

---

### Repeat scanning

Move `i`:

* 15 → ok
* 25 → ok
* 80 → stop (80 > 35)

Move `j`:

* 45 → no
* 90 → no
* 50 → no
* 25 → stop

Now `i > j` → stop partitioning

---

### Final pivot swap

Swap pivot with element at `j` (25):

```
25, 20, 15, 35, 80, 50, 90, 45, +∞
```

👉 Pivot **35 is now in correct position**

---

## 4️⃣ Divide step (Divide & Conquer)

Now Quick Sort is applied recursively to:

### Left sub-array

```
25, 20, 15
```

### Right sub-array

```
80, 50, 90, 45
```

(`+∞` stays at end only for theory)

---

## 5️⃣ Sorting the left sub-array `[25, 20, 15]`

Pivot = 25

After partition:

```
15, 20, 25
```

Left side sorted ✔

---

## 6️⃣ Sorting the right sub-array `[80, 50, 90, 45]`

Pivot = 80

After partition:

```
50, 45, 80, 90
```

Sort `[50, 45]`:

```
45, 50
```

---

## 7️⃣ Final sorted array

Remove `+∞` (it was never real data):

```
15, 20, 25, 35, 45, 50, 80, 90
```

---

## 8️⃣ Why `+∞` is written ONLY at the end (summary)

### In DAA theory:

* Acts as a **sentinel**
* Prevents pointer overflow
* Makes partition logic simpler
* Avoids extra boundary checks

### In real programming:

* Usually NOT added
* Handled using index conditions

---

## 9️⃣ One-line exam answer 📝

> **`+∞` is used as a sentinel value in Quick Sort to prevent index overflow during partitioning and simplify comparisons.**

---

## 🧠 Memory Trick

> **`+∞` = safety guard, not data**
