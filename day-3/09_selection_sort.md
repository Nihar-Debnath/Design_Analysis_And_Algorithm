# 🎯 Selection Sort (DAA)

## 1️⃣ What is Selection Sort?

**Selection Sort** is a **comparison-based** sorting algorithm in which:

* The array is divided into **sorted** and **unsorted** parts
* In each pass, the **minimum element** from the unsorted part is selected
* It is swapped with the **first element** of the unsorted part

👉 Idea: **Select the correct element and place it in the correct position**

---

## 2️⃣ How Selection Sort Works (Step-by-Step Example)

### Example Array

```text
A = [64, 25, 12, 22, 11]
```

---

### 🔹 Pass 1

Unsorted: `[64, 25, 12, 22, 11]`

* Minimum = **11**
* Swap 11 with first element (64)

```text
[11, 25, 12, 22, 64]
```

✔ First position fixed

---

### 🔹 Pass 2

Unsorted: `[25, 12, 22, 64]`

* Minimum = **12**
* Swap with 25

```text
[11, 12, 25, 22, 64]
```

---

### 🔹 Pass 3

Unsorted: `[25, 22, 64]`

* Minimum = **22**
* Swap with 25

```text
[11, 12, 22, 25, 64]
```

---

### 🔹 Pass 4

Unsorted: `[25, 64]`

* Minimum = **25**
* No swap needed

```text
[11, 12, 22, 25, 64]
```

✔ Array sorted

---

## 3️⃣ Selection Sort Algorithm (Pseudocode)

```text
SelectionSort(A, n)
for i = 0 to n-2
    minIndex = i
    for j = i+1 to n-1
        if A[j] < A[minIndex]
            minIndex = j
    swap(A[i], A[minIndex])
```

---

## 4️⃣ Time Complexity Analysis (Very Important)

Let ( n ) = number of elements

### 🔹 Number of Comparisons

Always:
\[
(n-1) + (n-2) + \dots + 1
= \frac{n(n-1)}{2}
\]

---

### 🔹 Best Case

Already sorted array
Comparisons still performed

\[
\boxed{O(n^2)}
\]

---

### 🔹 Average Case

\[
\boxed{O(n^2)}
\]

---

### 🔹 Worst Case

Reverse sorted array

\[
\boxed{O(n^2)}
\]

📌 **Key Point:**
Selection Sort time complexity is **input-independent**

---

## 5️⃣ Space Complexity

* Uses only a few variables
* No extra array

\[
\boxed{O(1)}
\]

✔ **In-place sorting**

---

## 6️⃣ Is Selection Sort Stable? ❌

### ❌ NO — Selection Sort is **NOT stable**

Because:

* It swaps **non-adjacent elements**
* This can change the relative order of equal elements

### Example:

```text
[2a, 1, 2b]
```

After sorting:

```text
[1, 2b, 2a]
```

❌ Order changed → **Not stable**

---

## 7️⃣ Is Selection Sort In-Place? ✅

✔ Yes, because:

* No extra memory required
* Sorting is done inside the original array

---

## 8️⃣ Important Properties (Exam Table)

| Property         | Selection Sort |
| ---------------- | -------------- |
| Stable           | ❌ No           |
| In-place         | ✅ Yes          |
| Adaptive         | ❌ No           |
| Recursive        | ❌ No           |
| Comparison-based | ✅ Yes          |

---

## 9️⃣ Swaps vs Comparisons (GATE Favorite)

* **Comparisons:**
  \[
  \frac{n(n-1)}{2}
  \]
* **Swaps:**
  At most **( n-1 )**

👉 Minimum swaps among simple sorts

---

## 🔟 When Selection Sort is Used?

✅ Used when:

* **Memory writes are costly**
* Swaps need to be minimized
* Small input size

❌ Not suitable for:

* Large datasets
* When stability is required

---

## 1️⃣1️⃣ Selection Sort vs Insertion Sort

| Feature  | Selection | Insertion |
| -------- | --------- | --------- |
| Time     | O(n²)     | O(n²)     |
| Stable   | ❌         | ✅         |
| Swaps    | Very few  | More      |
| Adaptive | ❌         | ✅         |

---

## 1️⃣2️⃣ One-Line Exam Answer

> Selection sort repeatedly selects the minimum element from the unsorted portion and places it at the beginning.

---

## 1️⃣3️⃣ GATE / DAA Trap Points ⚠️

* Best, average, worst cases are **same**
* Not stable
* Performs **minimum number of swaps**
* Time does **not** depend on input order
