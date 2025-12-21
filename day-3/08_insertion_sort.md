# 🧩 Insertion Sort (DAA)

## 1️⃣ What is Insertion Sort?

**Insertion Sort** is a **comparison-based**, **in-place**, **stable** sorting algorithm that:

* Builds the sorted array **one element at a time**
* Inserts each new element into its **correct position** in the already sorted part

👉 Works exactly like **sorting playing cards in your hand**.

---

## 2️⃣ How Insertion Sort Works (Step-by-Step Example)

### Example Array

```text
A = [5, 3, 4, 1, 2]
```

Assume:

* First element is already sorted
* Remaining elements are inserted one by one

---

### 🔹 Pass 1 (Insert 3)

Sorted part: `[5]`

* Compare 3 with 5 → shift 5 right
* Insert 3 at position 0

```text
[3, 5, 4, 1, 2]
```

---

### 🔹 Pass 2 (Insert 4)

Sorted part: `[3, 5]`

* Compare 4 with 5 → shift 5
* Compare 4 with 3 → stop
* Insert 4

```text
[3, 4, 5, 1, 2]
```

---

### 🔹 Pass 3 (Insert 1)

Sorted part: `[3, 4, 5]`

Shifts:

* 5 → right
* 4 → right
* 3 → right

Insert 1 at start

```text
[1, 3, 4, 5, 2]
```

---

### 🔹 Pass 4 (Insert 2)

Sorted part: `[1, 3, 4, 5]`

Shifts:

* 5 → right
* 4 → right
* 3 → right

Insert 2 after 1

```text
[1, 2, 3, 4, 5]
```

✔ Array sorted

---

## 3️⃣ Insertion Sort Algorithm (Pseudocode)

```text
InsertionSort(A, n)
for i = 1 to n-1
    key = A[i]
    j = i - 1
    while j >= 0 and A[j] > key
        A[j+1] = A[j]
        j = j - 1
    A[j+1] = key
```

---

## 4️⃣ Time Complexity Analysis

Let ( n ) = number of elements

---

### 🔹 Best Case (Already Sorted)

* Only **1 comparison per element**
* No shifting

\[
T(n) = n - 1
\]

\[
\boxed{O(n)}
\]

---

### 🔹 Worst Case (Reverse Sorted)

* Each element compared with all previous elements

\[
T(n) = \sum_{i=1}^{n-1} i
= \frac{n(n-1)}{2}
\]

\[
\boxed{O(n^2)}
\]

---

### 🔹 Average Case

\[
\boxed{O(n^2)}
\]

---

## 5️⃣ Space Complexity

* Uses a constant variable `key`

\[
\boxed{O(1)}
\]

✔ **In-place sorting**

---

## 6️⃣ Why Insertion Sort is Stable? ⭐

Because:

* It **does NOT swap equal elements**
* It shifts elements only when:

```text
A[j] > key
```

Not `>=`

Example:

```text
[2a, 2b, 1]
```

Sorted:

```text
[1, 2a, 2b]
```

✔ Order preserved

---

## 7️⃣ Why Insertion Sort is In-Place?

* No extra array used
* Sorting done inside input array
* Only one extra variable (`key`)

---

## 8️⃣ Important Properties (Exam Table)

| Property         | Insertion Sort |
| ---------------- | -------------- |
| Stable           | ✅ Yes          |
| In-place         | ✅ Yes          |
| Adaptive         | ✅ Yes          |
| Recursive        | ❌ No           |
| Comparison-based | ✅ Yes          |

---

## 9️⃣ Comparison Count (DAA / GATE Important)

Worst-case comparisons:

\[
\frac{n(n-1)}{2}
\]

Best-case comparisons:

\[
n - 1
\]

---

## 🔟 When Insertion Sort is Preferred?

✅ Best choice when:

* Array is **almost sorted**
* Input size is **small**
* Used inside **Hybrid algorithms** (QuickSort, TimSort)

❌ Not good for:

* Large random datasets

---

## 1️⃣1️⃣ Insertion Sort vs Bubble Sort

| Feature         | Insertion | Bubble |
| --------------- | --------- | ------ |
| Best Case       | O(n)      | O(n)   |
| Worst Case      | O(n²)     | O(n²)  |
| Swaps/Shifts    | Fewer     | More   |
| Practical Speed | Faster    | Slower |

---

## 1️⃣2️⃣ One-Line Exam Answer

> Insertion sort builds a sorted list one element at a time by inserting each element into its correct position.

---

## 1️⃣3️⃣ GATE / DAA Trap Points ⚠️

* Insertion sort is **stable**
* Insertion sort is **adaptive**
* Worst case is **reverse sorted array**
* Faster than Bubble Sort in practice
