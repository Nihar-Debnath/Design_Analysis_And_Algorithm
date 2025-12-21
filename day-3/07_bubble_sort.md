# 🫧 Bubble Sort (DAA)

## 1️⃣ What is Bubble Sort?

**Bubble Sort** is a **comparison-based**, **in-place**, **stable** sorting algorithm in which:

* Adjacent elements are compared
* Swapped if they are in the wrong order
* Largest element “bubbles up” to the end in each pass

---

## 2️⃣ How Bubble Sort Works (Step-by-Step Example)

### Example Array

```text
A = [5, 1, 4, 2, 8]
```

---

### 🔁 Pass 1

Compare adjacent elements:

| Comparison | Action  | Array           |
| ---------- | ------- | --------------- |
| 5 vs 1     | swap    | [1, 5, 4, 2, 8] |
| 5 vs 4     | swap    | [1, 4, 5, 2, 8] |
| 5 vs 2     | swap    | [1, 4, 2, 5, 8] |
| 5 vs 8     | no swap | [1, 4, 2, 5, 8] |

✔ Largest element **8** is at correct position

---

### 🔁 Pass 2

```text
[1, 4, 2, 5, 8]
```

| Comparison | Action  |
| ---------- | ------- |
| 1 vs 4     | no swap |
| 4 vs 2     | swap    |
| 4 vs 5     | no swap |

Array → `[1, 2, 4, 5, 8]`

---

### 🔁 Pass 3

No swaps → **array is sorted**

---

## 3️⃣ Bubble Sort Algorithm (Pseudocode)

```text
BubbleSort(A, n)
for i = 0 to n-2
    swapped = false
    for j = 0 to n-i-2
        if A[j] > A[j+1]
            swap(A[j], A[j+1])
            swapped = true
    if swapped == false
        break
```

---

## 4️⃣ Performance of Bubble Sort (Time Complexity)

Let ( n ) = number of elements

### 🔹 Worst Case (Reverse Sorted)

\[
T(n) = \sum_{i=1}^{n-1} (n-i) = \frac{n(n-1)}{2}
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

### 🔹 Best Case (Already Sorted, with optimization)

Only **1 pass**, no swaps

\[
\boxed{O(n)}
\]

⚠️ Without optimization → still (O(n^2))

---

## 5️⃣ Space Complexity

* Uses only a **constant extra variable**
  \[
  \boxed{O(1)}
  \]

---

## 6️⃣ Important Properties (VERY IMPORTANT FOR EXAMS)

| Property         | Bubble Sort               |
| ---------------- | ------------------------- |
| Stable           | ✅ Yes                     |
| In-place         | ✅ Yes                     |
| Adaptive         | ✅ Yes (with swapped flag) |
| Recursive        | ❌ No                      |
| Comparison-based | ✅ Yes                     |

---

## 7️⃣ Why Bubble Sort is Stable?

Because:

* It swaps **only adjacent elements**
* Equal elements are **never swapped**

Example:

```text
(2a, 2b, 1)
```

After sorting:

```text
(1, 2a, 2b)
```

Order of equal elements preserved ✔

---

## 8️⃣ Why Bubble Sort is Adaptive?

If the array is **already sorted**:

* No swaps in first pass
* Algorithm terminates early

---

## 9️⃣ Comparison Count (Important for DAA / GATE)

Total comparisons in worst case:
\[
\frac{n(n-1)}{2}
\]

---

## 🔟 When Bubble Sort is Used (Real Meaning)

### ❌ Not used for large inputs

* Too slow (O(n^2))

### ✅ Used for:

* Teaching sorting concepts
* Very small datasets
* Checking if array is already sorted

---

## 1️⃣1️⃣ Bubble Sort vs Selection Sort (Quick View)

| Feature  | Bubble Sort | Selection Sort |
| -------- | ----------- | -------------- |
| Time     | (O(n^2))    | (O(n^2))       |
| Stable   | ✅ Yes       | ❌ No           |
| Swaps    | Many        | Few            |
| Adaptive | ✅           | ❌              |

---

## 1️⃣2️⃣ One-Line Exam Answer

> Bubble sort repeatedly compares adjacent elements and swaps them if out of order, causing the largest element to move to the end in each pass.

---

## 1️⃣3️⃣ GATE / DAA Trap Points ⚠️

* Best case is **O(n)** only **with swapped flag**
* Worst & average are **always (O(n^2))**
* Bubble sort is **stable**
* It performs **maximum swaps among simple sorts**
