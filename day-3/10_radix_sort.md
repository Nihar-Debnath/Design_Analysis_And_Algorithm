# 🔢 Radix Sort (DAA)

## 1️⃣ What is Radix Sort? (Easiest definition)

**Radix Sort** is a **non-comparison based** sorting algorithm that:

* Sorts numbers **digit by digit**
* Starts from **least significant digit (LSD)** or **most significant digit (MSD)**
* Uses a **stable sub-sorting algorithm** (usually Counting Sort)

👉 Think of it like **sorting numbers the way humans read digits**.

---

## 2️⃣ Why is it Called “Radix”?

* **Radix = base of number system**

  * Decimal → radix = 10
  * Binary → radix = 2

---

## 3️⃣ Key Idea (Very Important)

Instead of comparing numbers directly:

* Sort by **units digit**
* Then **tens digit**
* Then **hundreds digit**
* Continue until all digits are processed

⚠️ **Stability is compulsory**, otherwise Radix Sort fails.

---

## 4️⃣ Radix Sort Working (Step-by-Step Example)

### Example Array

```text
A = [170, 45, 75, 90, 802, 24, 2, 66]
```

We will use **LSD Radix Sort (most common in exams)**.

---

### 🔹 Step 1: Sort by Units Digit

| Number | Units Digit |
| ------ | ----------- |
| 170    | 0           |
| 45     | 5           |
| 75     | 5           |
| 90     | 0           |
| 802    | 2           |
| 24     | 4           |
| 2      | 2           |
| 66     | 6           |

After **stable sort**:

```text
[170, 90, 802, 2, 24, 45, 75, 66]
```

---

### 🔹 Step 2: Sort by Tens Digit

| Number | Tens Digit |
| ------ | ---------- |
| 170    | 7          |
| 90     | 9          |
| 802    | 0          |
| 2      | 0          |
| 24     | 2          |
| 45     | 4          |
| 75     | 7          |
| 66     | 6          |

After stable sort:

```text
[802, 2, 24, 45, 66, 170, 75, 90]
```

---

### 🔹 Step 3: Sort by Hundreds Digit

| Number | Hundreds Digit |
| ------ | -------------- |
| 802    | 8              |
| 2      | 0              |
| 24     | 0              |
| 45     | 0              |
| 66     | 0              |
| 170    | 1              |
| 75     | 0              |
| 90     | 0              |

After stable sort:

```text
[2, 24, 45, 66, 75, 90, 170, 802]
```

✔ **Array is now fully sorted**

---

## 5️⃣ Radix Sort Algorithm (High-Level)

```text
RadixSort(A, d)
for digit = 1 to d
    StableSort(A, digit)
```

Where:

* `d` = number of digits in maximum number
* StableSort = Counting Sort (most common)

---

## 6️⃣ Time Complexity Analysis

Let:

* ( n ) = number of elements
* ( d ) = number of digits
* ( k ) = radix (base, usually 10)

### 🔹 Time Complexity

[
\boxed{O(d \cdot (n + k))}
]

Since ( k = 10 ) (constant):

[
\boxed{O(dn)}
]

---

### 🔹 Best Case

[
O(dn)
]

### 🔹 Average Case

[
O(dn)
]

### 🔹 Worst Case

[
O(dn)
]

📌 **Independent of input order**

---

## 7️⃣ Space Complexity

* Requires auxiliary array (Counting Sort)

[
\boxed{O(n + k)}
]

❌ Not in-place

---

## 8️⃣ Is Radix Sort Stable? ✅

✔ Yes — **if** the internal sorting algorithm is stable
(Counting Sort is stable)

⚠️ If unstable sort is used → Radix Sort fails

---

## 9️⃣ Is Radix Sort In-Place? ❌

❌ No, because:

* Uses extra memory for counting & output array

---

## 🔟 Important Properties (Exam Table)

| Property           | Radix Sort |
| ------------------ | ---------- |
| Comparison-based   | ❌ No       |
| Stable             | ✅ Yes      |
| In-place           | ❌ No       |
| Adaptive           | ❌ No       |
| Best/Average/Worst | Same       |

---

## 1️⃣1️⃣ When Radix Sort is Used?

✅ Best when:

* Keys are integers or fixed-length strings
* Number of digits is small
* Large dataset

❌ Not suitable for:

* Floating numbers (without modification)
* Very large digit length

---

## 1️⃣2️⃣ Radix Sort vs Comparison Sorts

| Sort          | Time          |
| ------------- | ------------- |
| Quick / Merge | (O(n \log n)) |
| Radix         | (O(dn))       |

👉 Can beat comparison sorts when ( d ) is small

---

## 1️⃣3️⃣ GATE / DAA Trap Points ⚠️

* Radix sort is **non-comparison based**
* Stability is **mandatory**
* Uses Counting Sort internally
* Not in-place
* Time depends on **number of digits**, not input order

---

## 1️⃣4️⃣ One-Line Exam Answer

> Radix sort sorts numbers digit by digit using a stable sorting algorithm, achieving linear time when the number of digits is small.
