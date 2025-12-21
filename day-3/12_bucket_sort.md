# 📦 Bucket Sort (Beginner-Friendly Explanation)

## 🔹 What is Bucket Sort?

**Bucket Sort** is a **sorting algorithm** that:

* **Distributes elements into different “buckets”**
* **Sorts each bucket individually**
* **Combines all buckets to get the final sorted array**

Think of it like:

> You have marks of students (0–100).
> Instead of sorting all at once, you put
>
> * 0–9 in bucket 0
> * 10–19 in bucket 1
> * 20–29 in bucket 2
>   … then sort each bucket.

---

## 🔹 When should we use Bucket Sort?

Bucket Sort works best when:

* Input is **uniformly distributed**
* Values lie in a **known range**
* Floating-point numbers or large datasets

---

## 🔹 Real-Life Analogy 🧺

Imagine sorting **apples by size**:

1. Create baskets (small, medium, large)
2. Put apples into correct basket
3. Sort apples inside each basket
4. Join all baskets

---

## 🔹 Step-by-Step Example

### 📌 Input Array

```
A = [0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51]
```

### 📌 Step 1: Create Buckets

Suppose **n = 7**, so create **7 buckets**:

```
Bucket 0: (0.0 – 0.14)
Bucket 1: (0.15 – 0.29)
Bucket 2: (0.30 – 0.44)
Bucket 3: (0.45 – 0.59)
Bucket 4: (0.60 – 0.74)
Bucket 5: (0.75 – 0.89)
Bucket 6: (0.90 – 1.0)
```

---

### 📌 Step 2: Distribute Elements into Buckets

| Element | Bucket   |
| ------- | -------- |
| 0.42    | Bucket 2 |
| 0.32    | Bucket 2 |
| 0.23    | Bucket 1 |
| 0.52    | Bucket 3 |
| 0.25    | Bucket 1 |
| 0.47    | Bucket 3 |
| 0.51    | Bucket 3 |

Buckets after insertion:

```
Bucket 1 → [0.23, 0.25]
Bucket 2 → [0.42, 0.32]
Bucket 3 → [0.52, 0.47, 0.51]
```

---

### 📌 Step 3: Sort Each Bucket

(Usually using **Insertion Sort**)

```
Bucket 1 → [0.23, 0.25]
Bucket 2 → [0.32, 0.42]
Bucket 3 → [0.47, 0.51, 0.52]
```

---

### 📌 Step 4: Concatenate All Buckets

### ✅ Final Sorted Array

```
[0.23, 0.25, 0.32, 0.42, 0.47, 0.51, 0.52]
```

---

## 🔹 Pseudocode (DAA Style)

```
BUCKET_SORT(A, n)
    Create n empty buckets B[0...n-1]

    for i = 0 to n-1
        index = n * A[i]
        Insert A[i] into bucket B[index]

    for i = 0 to n-1
        Sort bucket B[i] using Insertion Sort

    Concatenate all buckets B[0...n-1] into array A
```

---

## 🔹 Time Complexity Analysis 📊

Let:

* `n` = number of elements
* `k` = number of buckets

### 🔸 Best Case (Uniform Distribution)

```
O(n)
```

Each bucket has few elements → very fast

### 🔸 Average Case

```
O(n + k)
```

Usually considered **O(n)**

### 🔸 Worst Case

```
O(n²)
```

All elements fall into **one bucket**

---

## 🔹 Space Complexity

```
O(n + k)
```

Extra space for buckets

---

## 🔹 Is Bucket Sort Stable?

✅ **Yes**, if stable sorting is used inside buckets.

---

## 🔹 Advantages ✅

* Very fast for uniform data
* Easy to understand
* Works well for floating-point numbers

---

## 🔹 Disadvantages ❌

* Not good for non-uniform data
* Uses extra memory
* Needs known range

---

## 🔹 Quick DAA Exam Summary 📝

| Feature    | Bucket Sort          |
| ---------- | -------------------- |
| Type       | Non-comparison based |
| Best Time  | O(n)                 |
| Worst Time | O(n²)                |
| Space      | O(n)                 |
| Stable     | Yes                  |
| Use Case   | Uniform distribution |
