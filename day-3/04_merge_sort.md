# How Merge Sort Works | Divide and Conquer | DAA

---

## 1️⃣ What is Merge Sort?

**Merge Sort** is a **sorting algorithm** that uses the **Divide and Conquer** strategy.

It sorts an array by:

1. **Dividing** the array into two halves
2. **Recursively sorting** each half
3. **Merging** the sorted halves into one sorted array

---

## 2️⃣ Why is it called “Merge” Sort?

Because the **main work** of the algorithm is done during the **merge step**,
where two **already sorted arrays** are combined into one sorted array.

---

## 3️⃣ Divide and Conquer in Merge Sort (VERY IMPORTANT)

Merge Sort follows the 3 steps **perfectly**:

### 🔹 Divide

Split the array into **two equal halves**

### 🔹 Conquer

Recursively sort both halves

### 🔹 Combine

Merge the two sorted halves

👉 Unlike Quick Sort, **Merge Sort always divides equally**.

---

## 4️⃣ Key characteristics (theory points)

* Uses **recursion**
* Always divides array into halves
* Uses **extra memory**
* Guarantees **O(n log n)** time
* Is a **stable sorting algorithm**

---

## 5️⃣ Algorithm idea (high level)

```text
MERGE-SORT(array):
    if array size ≤ 1:
        return array

    divide array into left and right halves
    left = MERGE-SORT(left half)
    right = MERGE-SORT(right half)
    return MERGE(left, right)
```

---

## 6️⃣ Let’s understand with a FULL example

### Given array:

```
38, 27, 43, 3, 9, 82, 10
```

---

## 7️⃣ Step 1: Divide (recursively)

### First division

```
[38, 27, 43, 3]     [9, 82, 10]
```

---

### Second division

```
[38, 27]   [43, 3]     [9, 82]   [10]
```

---

### Third division (base case)

```
[38] [27] [43] [3] [9] [82] [10]
```

Now every sub-array has **1 element**
👉 Single element is already sorted

---

## 8️⃣ Step 2: Conquer (start merging)

Now we **merge back** in reverse order.

---

### Merge [38] and [27]

```
Compare 38 and 27 → 27 is smaller
Result: [27, 38]
```

---

### Merge [43] and [3]

```
Compare 43 and 3 → 3 is smaller
Result: [3, 43]
```

---

### Merge [9] and [82]

```
Already sorted → [9, 82]
```

---

## 9️⃣ Step 3: Continue merging

### Merge [27, 38] and [3, 43]

```
Compare 27 and 3 → 3
Compare 27 and 43 → 27
Compare 38 and 43 → 38
Remaining → 43
```

Result:

```
[3, 27, 38, 43]
```

---

### Merge [9, 82] and [10]

```
Compare 9 and 10 → 9
Compare 82 and 10 → 10
Remaining → 82
```

Result:

```
[9, 10, 82]
```

---

## 🔟 Final merge (MOST IMPORTANT)

Merge:

```
[3, 27, 38, 43]  and  [9, 10, 82]
```

Step-by-step:

```
3 < 9  → 3
9 < 27 → 9
10 < 27 → 10
27 < 82 → 27
38 < 82 → 38
43 < 82 → 43
Remaining → 82
```

---

## ✅ Final Sorted Array

```
3, 9, 10, 27, 38, 43, 82
```

---

## 1️⃣1️⃣ Time Complexity Analysis (DAA)

### Recurrence relation:

\[
T(n) = 2T(n/2) + cn
\]

* Divide → constant
* Merge → O(n)
* Levels → log n

### Time complexity (all cases):

\[
\boxed{O(n \log n)}
\]

✅ Best case
✅ Average case
✅ Worst case
(all same)

---

## 1️⃣2️⃣ Space Complexity

* Uses extra array during merge
* Space complexity:
  \[
  \boxed{O(n)}
  \]

---

## 1️⃣3️⃣ Advantages of Merge Sort

✅ Guaranteed O(n log n)
✅ Stable sorting
✅ Good for linked lists
✅ Predictable performance

---

## 1️⃣4️⃣ Disadvantages of Merge Sort

❌ Uses extra memory
❌ Slower than Quick Sort in practice
❌ Not in-place

---

## 1️⃣5️⃣ Merge Sort vs Quick Sort (short)

| Merge Sort        | Quick Sort       |
| ----------------- | ---------------- |
| Always O(n log n) | Worst case O(n²) |
| Uses extra space  | In-place         |
| Stable            | Not stable       |
| Predictable       | Depends on pivot |

---

## 1️⃣6️⃣ One-line exam definition 📝

> **Merge Sort is a divide and conquer sorting algorithm that recursively divides the array into halves and merges them in sorted order.**

---

## 🧠 Memory Trick

> **Split → Split → Merge → Merge → Sorted**
