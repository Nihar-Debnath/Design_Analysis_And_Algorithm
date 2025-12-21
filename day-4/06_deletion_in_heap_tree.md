# 🔷 Deletion in Heap Tree (MAX HEAP)

---

## 1️⃣ What does “Deletion” mean in a Heap?

In a **Max Heap**:

> **Deletion always means deleting the ROOT element**
> (because root has the **maximum** value)

📌 You **cannot delete any random node directly** in a heap.

---

## 2️⃣ Why only the root?

Because heap is designed to:

* Quickly **access/remove max**
* Not for searching arbitrary elements

---

## 3️⃣ Basic Idea of Deletion (High Level)

To delete root:

1. Remove the **root**
2. Put the **last element** at root
3. Restore heap property using **heapify-down**

---

## 4️⃣ Deletion Algorithm (MAX HEAP)

### Steps:

1. Save root (max element)
2. Replace root with **last element**
3. Reduce heap size by 1
4. Call **heapify-down** from root

---

## 5️⃣ Example (STEP BY STEP)

### Given Max Heap (Array form)

```
A = [50, 30, 40, 10, 5, 20, 30]
```

Tree view:

```
            50
         /        \
       30          40
      /  \        /  \
    10    5     20   30
```

---

## 🔹 Step 1: Delete root (50)

Root = **50** (this is deleted)

---

## 🔹 Step 2: Move last element to root

Last element = **30**

```
            30
         /        \
       30          40
      /  \        /
    10    5     20
```

Array:

```
[30, 30, 40, 10, 5, 20]
```

---

## 🔹 Step 3: Heapify-Down (VERY IMPORTANT)

### Compare root with children:

* Children: 30 and 40
* Largest = 40

➡ Swap 30 and 40

```
[40, 30, 30, 10, 5, 20]
```

---

### Continue heapify at index of 30

Children: 20 only
30 ≥ 20 → OK

---

## ✅ Final Heap after deletion

```
[40, 30, 30, 10, 5, 20]
```

---

## 6️⃣ Heapify-Down Logic (BEGINNER FRIENDLY)

At every step:

1. Compare node with **both children**
2. Swap with **larger child**
3. Move downward
4. Stop when heap property satisfied

---

## 7️⃣ Pseudocode (MAX HEAP DELETE)

```text
DELETE_MAX(A, n):
    if n == 0:
        return

    max = A[0]
    A[0] = A[n-1]
    n = n - 1
    MAX_HEAPIFY(A, 0, n)
```

---

## 8️⃣ TIME COMPLEXITY (MOST IMPORTANT PART)

### Step-wise cost:

| Step              | Cost     |
| ----------------- | -------- |
| Remove root       | O(1)     |
| Move last element | O(1)     |
| Heapify-down      | O(log n) |

---

## 🔑 Why Heapify-Down is O(log n)?

* Heap height = `log n`
* In worst case, element moves **from root to leaf**
* One level per step

\[
\text{Time} = O(\log n)
\]

---

## 9️⃣ Final Time Complexity

\[
\boxed{O(\log n)}
\]

✔ This is **true for both Max Heap and Min Heap**

---

## 🔟 VERY COMMON EXAM CONFUSION

| Operation  | Time     |
| ---------- | -------- |
| Build Heap | O(n)     |
| Insert     | O(log n) |
| Delete     | O(log n) |

❗ Build heap is special
❗ Delete is NOT O(n)

---

## 🧠 ONE-LINE MEMORY TRICK

> **Deletion = replace root + heapify down = O(log n)**
