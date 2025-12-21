# 🔢 Counting Sort (DAA)

## 1️⃣ What is Counting Sort? (Easiest definition)

**Counting Sort** is a **non-comparison based** sorting algorithm that:

* Counts how many times each **key value** occurs
* Uses this count to place elements in their **correct sorted position**
* Works best when the **range of input values is small**

👉 Instead of comparing elements, it **counts them**.

---

## 2️⃣ When Can We Use Counting Sort?

Counting Sort works **only if**:

* Elements are **integers**
* Values lie in a **known, small range**
  [
  0 \leq A[i] \leq k
  ]

---

## 3️⃣ Key Idea (Very Important)

1. Count occurrences of each value
2. Compute **prefix sum (cumulative count)**
3. Place elements in correct positions (from right to left → stability)

---

## 4️⃣ Counting Sort Working (Step-by-Step Example)

### Example Array

```text
A = [4, 2, 2, 8, 3, 3, 1]
```

Maximum value ( k = 8 )

---

### 🔹 Step 1: Create Count Array

Index = element value

```text
C[0..8] = [0,0,0,0,0,0,0,0,0]
```

Count frequency:

```text
Value : 1 2 3 4 5 6 7 8
Count : 1 2 2 1 0 0 0 1
```

So,

```text
C = [0,1,2,2,1,0,0,0,1]
```

---

### 🔹 Step 2: Compute Prefix Sum (Cumulative Count)

```text
C[1] = 1
C[2] = 3
C[3] = 5
C[4] = 6
C[5] = 6
C[6] = 6
C[7] = 6
C[8] = 7
```

Now:

```text
C = [0,1,3,5,6,6,6,6,7]
```

👉 This tells the **final position** of each element.

---

### 🔹 Step 3: Build Output Array (Right → Left for Stability)

Original array:

```text
[4, 2, 2, 8, 3, 3, 1]
```

Placing elements:

| Element | Position | Output          |
| ------- | -------- | --------------- |
| 1       | C[1]=1   | [1,*,*,*,*,*,*] |
| 3       | C[3]=5   | [1,*,*,*,3,*,_] |
| 3       | C[3]=4   | [1,*,*,3,3,*,*] |
| 8       | C[8]=7   | [1,*,*,3,3,_,8] |
| 2       | C[2]=3   | [1,*,2,3,3,*,8] |
| 2       | C[2]=2   | [1,2,2,3,3,_,8] |
| 4       | C[4]=6   | [1,2,2,3,3,4,8] |

---

### ✅ Final Sorted Array

```text
[1, 2, 2, 3, 3, 4, 8]
```

---

## 5️⃣ Counting Sort Algorithm (High-Level)

```text
CountingSort(A, n, k)
create C[0..k] initialized to 0
for i = 1 to n
    C[A[i]]++
for i = 1 to k
    C[i] = C[i] + C[i-1]
create output array B[1..n]
for i = n down to 1
    B[C[A[i]]] = A[i]
    C[A[i]]--
```

---

## 6️⃣ Time Complexity Analysis

Let:

* ( n ) = number of elements
* ( k ) = range of input values

### 🔹 Best Case

[
O(n + k)
]

### 🔹 Average Case

[
O(n + k)
]

### 🔹 Worst Case

[
O(n + k)
]

📌 Independent of input order

---

## 7️⃣ Space Complexity

Extra arrays:

* Count array → ( k+1 )
* Output array → ( n )

[
\boxed{O(n + k)}
]

❌ Not in-place

---

## 8️⃣ Is Counting Sort Stable? ✅

✔ Yes — if output is built **right to left**

Example:

```text
[2a, 2b, 1]
```

Sorted:

```text
[1, 2a, 2b]
```

Order preserved ✔

---

## 9️⃣ Is Counting Sort In-Place? ❌

❌ No, because:

* Requires auxiliary output array

---

## 🔟 Important Properties (Exam Table)

| Property         | Counting Sort |
| ---------------- | ------------- |
| Comparison-based | ❌ No          |
| Stable           | ✅ Yes         |
| In-place         | ❌ No          |
| Adaptive         | ❌ No          |
| Best/Avg/Worst   | Same          |

---

## 1️⃣1️⃣ When Counting Sort is Used?

✅ Best when:

* Keys are integers
* Small range ( k )
* Need **stable sorting**

❌ Not suitable when:

* Range is very large
* Input values are floats or strings

---

## 1️⃣2️⃣ Counting Sort vs Comparison Sorts

| Sort          | Time          |
| ------------- | ------------- |
| Quick / Merge | (O(n \log n)) |
| Counting      | (O(n + k))    |

👉 Can beat comparison sorts when ( k = O(n) )

---

## 1️⃣3️⃣ GATE / DAA Trap Points ⚠️

* Counting Sort is **not comparison-based**
* Stability depends on **right-to-left placement**
* Not in-place
* Works only for **non-negative integers**

---

## 1️⃣4️⃣ One-Line Exam Answer

> Counting sort sorts elements by counting occurrences of each key and computing their final positions using prefix sums.



---
---
---

---
---
---
---
---
---




# 🔢 Counting Sort — VERY SIMPLE EXAMPLE

## Example Array

```text
A = [3, 1, 2, 1]
```

Here:

* ( n = 4 )
* Maximum value ( k = 3 )

---

## Step 1️⃣ Create Count Array

Index = value

```text
C[0..3] = [0, 0, 0, 0]
```

Now count each number:

* See **3** → C[3]++
* See **1** → C[1]++
* See **2** → C[2]++
* See **1** → C[1]++

Result:

```text
Value : 0 1 2 3
Count : 0 2 1 1
```

So,

```text
C = [0, 2, 1, 1]
```

👉 Meaning:

* Two 1’s
* One 2
* One 3

---

## Step 2️⃣ Prefix Sum (Cumulative Count)

Now convert counts to **positions**.

```text
C[0] = 0
C[1] = 2
C[2] = 2 + 1 = 3
C[3] = 3 + 1 = 4
```

So:

```text
C = [0, 2, 3, 4]
```

👉 Meaning:

* All **1s end at position 2**
* All **2s end at position 3**
* All **3s end at position 4**

---

## Step 3️⃣ Build Output Array (Right → Left)

Create output array:

```text
B = [_, _, _, _]
```

Now read input **from right to left**.

---

### i = 4 → element = 1

* Position = C[1] = 2
* Place 1 at B[2]
* Decrease C[1]

```text
B = [_, 1, _, _]
C = [0, 1, 3, 4]
```

---

### i = 3 → element = 2

* Position = C[2] = 3
* Place 2 at B[3]
* Decrease C[2]

```text
B = [_, 1, 2, _]
C = [0, 1, 2, 4]
```

---

### i = 2 → element = 1

* Position = C[1] = 1
* Place 1 at B[1]
* Decrease C[1]

```text
B = [1, 1, 2, _]
C = [0, 0, 2, 4]
```

---

### i = 1 → element = 3

* Position = C[3] = 4
* Place 3 at B[4]
* Decrease C[3]

```text
B = [1, 1, 2, 3]
```

---

## ✅ Final Sorted Output

```text
[1, 1, 2, 3]
```

---

## 🔑 One-Sentence Intuition (Very Important)

> **Counting Sort does not move elements by comparing; it only calculates where each value should go and places it directly there.**

---

## 🧠 Why Prefix Sum is Needed?

Without prefix sum:

* You only know **how many**
  With prefix sum:
* You know **where to place**

---

## ⚠️ Why Right-to-Left Placement?

To maintain **stability**:

Example:

```text
[1a, 1b, 2]
```

Sorted:

```text
[1a, 1b, 2]
```

Order preserved ✔
