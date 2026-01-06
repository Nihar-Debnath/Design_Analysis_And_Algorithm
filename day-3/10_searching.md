# What does “analysis of an algorithm” mean?

**Analysis** means:

* How much **time** the algorithm takes
* How much **extra memory** it uses

Mainly we study **Time Complexity** using:

* **Best case**
* **Worst case**
* **Average case**

---

# 1️⃣ Linear Search – Analysis

## What is Linear Search?

* We check elements **one by one**
* Start from the **first element**
* Stop when:

  * element is found, or
  * list ends

Example:

```
Array: 10 20 30 40 50
Key: 40
```

Check → 10 ❌ → 20 ❌ → 30 ❌ → 40 ✅

---

## Time Complexity Analysis of Linear Search

Let `n` = number of elements

### 🔹 Best Case

* Element found at **first position**
* Comparisons = 1

[
\text{Time} = O(1)
]

---

### 🔹 Worst Case

* Element is **last** or **not present**
* Comparisons = n

[
\text{Time} = O(n)
]

---

### 🔹 Average Case

* Element can be anywhere
* On average, checked `n/2` elements

[
\text{Time} = O(n)
]

---

## Space Complexity

* Uses only one variable

[
\text{Space} = O(1)
]

---

## Summary (Linear Search)

| Case    | Time |
| ------- | ---- |
| Best    | O(1) |
| Worst   | O(n) |
| Average | O(n) |
| Space   | O(1) |

---

# 2️⃣ Binary Search – Analysis

## What is Binary Search?

* Works on **sorted array only**
* Repeatedly:

  * Check **middle element**
  * Divide search space into **half**

Example:

```
Array: 10 20 30 40 50 60 70
Key: 40
```

Steps:

* Middle = 40 → found ✅

---

## Time Complexity Analysis of Binary Search

Let `n` = number of elements

Each step:

* Array size becomes **half**

```
n → n/2 → n/4 → n/8 → ...
```

This continues until size becomes 1.

---

### 🔹 Best Case

* Element found at **middle** in first step

[
\text{Time} = O(1)
]

---

### 🔹 Worst Case

* Element found at last step or not found

Number of steps:
[
\log_2 n
]

[
\text{Time} = O(\log n)
]

---

### 🔹 Average Case

* Still divides array by half each time

[
\text{Time} = O(\log n)
]

---

## Space Complexity

### Iterative Binary Search

[
\text{Space} = O(1)
]

### Recursive Binary Search

[
\text{Space} = O(\log n)
]

(due to recursion stack)

---

## Summary (Binary Search)

| Case              | Time     |
| ----------------- | -------- |
| Best              | O(1)     |
| Worst             | O(log n) |
| Average           | O(log n) |
| Space (iterative) | O(1)     |

---

# 3️⃣ Linear vs Binary Search (Very Important)

| Feature      | Linear Search     | Binary Search    |
| ------------ | ----------------- | ---------------- |
| Array type   | Sorted / Unsorted | **Sorted only**  |
| Method       | Sequential        | Divide & conquer |
| Best case    | O(1)              | O(1)             |
| Worst case   | O(n)              | O(log n)         |
| Average case | O(n)              | O(log n)         |
| Extra space  | O(1)              | O(1) / O(log n)  |
| Speed        | Slow              | Fast             |

---

# 4️⃣ When to use what?

### Use **Linear Search** when:

* Array is **small**
* Array is **unsorted**
* Simplicity matters

### Use **Binary Search** when:

* Array is **sorted**
* Large data
* Performance matters

---

# One-line exam answers ⭐

**Linear Search Analysis:**

> Linear search takes O(1) time in the best case and O(n) time in the average and worst cases.

**Binary Search Analysis:**

> Binary search takes O(1) time in the best case and O(log n) time in the average and worst cases.
