# 🌳 Introduction to Trees (Very-Very Basics)

---

## 1️⃣ What is a Tree? (Absolute Beginner)

### 🔹 Simple Meaning

A **Tree** is a **non-linear data structure** used to store data in a **hierarchical way**.

📌 **Hierarchical** = data arranged like:

* Family tree
* Company structure
* Folder structure in your computer

---

### 🔹 Real-Life Example

```
           Principal
          /          \
     Teacher1       Teacher2
      /   \             |
   Stu1  Stu2         Stu3
```

This is a **Tree**.

---

### 🔹 Why not Array or Linked List?

| Structure   | Arrangement                   |
| ----------- | ----------------------------- |
| Array       | Linear (one after another)    |
| Linked List | Linear                        |
| Tree        | Hierarchical (parent → child) |

---

## 2️⃣ Basic Tree Terminology (Very Important)

Let’s understand basic words first.

```
        A
       / \
      B   C
     / \
    D   E
```

### 🔹 Node

Each box (A, B, C, D, E) is a **node**

### 🔹 Root

Topmost node
➡️ `A`

### 🔹 Parent & Child

* `A` is parent of `B` and `C`
* `B` is parent of `D` and `E`

### 🔹 Leaf Node

Nodes with **no children**
➡️ `C, D, E`

### 🔹 Edge

Connection between nodes
➡️ Lines between A–B, A–C, etc.

---

## 3️⃣ Binary Tree (Most Important Base)

### 🔹 Definition

A **Binary Tree** is a tree where:

> **Each node can have at most 2 children**

These children are called:

* **Left Child**
* **Right Child**

---

### 🔹 Example

```
        10
       /  \
      5    20
     / \
    3   7
```

✔ Allowed (max 2 children)
❌ Not allowed → 3 children

---

### 🔹 Important Point

Binary Tree **does NOT care about values**

* Left can be bigger
* Right can be smaller

---

## 4️⃣ Full Binary Tree (FBT)

### 🔹 Definition

A **Full Binary Tree** is a Binary Tree where:

> **Every node has either 0 or 2 children**

📌 No node is allowed to have **only 1 child**.

---

### 🔹 Example (Valid)

```
        A
       / \
      B   C
     / \
    D   E
```

✔ A → 2 children
✔ B → 2 children
✔ C, D, E → 0 children

---

### ❌ Invalid Full Binary Tree

```
        A
       /
      B
```

❌ A has only **1 child**

---

## 5️⃣ Complete Binary Tree (CBT)

### 🔹 Definition (Very Common in Exams)

A **Complete Binary Tree** is a Binary Tree where:

1. **All levels are completely filled**
2. **Except possibly the last level**
3. **Last level nodes are filled from LEFT to RIGHT**

---

### 🔹 Example (Valid CBT)

```
        1
       / \
      2   3
     / \  /
    4  5 6
```

✔ Last level filled left to right
✔ No gaps

---

### ❌ Invalid CBT

```
        1
       / \
      2   3
       \
        5
```

❌ Left child missing but right exists

---

📌 **Heap uses Complete Binary Tree**

---

## 6️⃣ Almost Complete Binary Tree

### 🔹 Meaning

An **Almost Complete Binary Tree** is:

> A tree that is **very close to complete**,
> but the last level may be **not fully filled**

📌 Practically:

* All levels filled
* Last level filled from left
* Few nodes may be missing at the rightmost

---

### 🔹 Example

```
        1
       / \
      2   3
     / \
    4   5
```

✔ Almost complete
✔ Missing nodes only at the **right end**

---

⚠️ Many books use **Almost Complete** interchangeably with **Complete Binary Tree**
👉 For exams, **treat them as same unless specified**

---

## 7️⃣ Binary Search Tree (BST) ⭐

### 🔹 Definition

A **Binary Search Tree** is a Binary Tree with **ordering rules**:

For every node:

```
Left Subtree  → Smaller values
Right Subtree → Larger values
```

---

### 🔹 Example

```
        10
       /  \
      5    20
     / \     \
    3   7     30
```

✔ Left < Parent
✔ Right > Parent

---

### ❌ Not a BST

```
        10
       /  \
     15    5
```

❌ Rule violated

---

### 🔹 Why BST is Important?

Because:

* **Search** → O(log n)
* **Insert** → O(log n)
* **Delete** → O(log n)

(when balanced)

---

## 8️⃣ Comparison Table (Exam Gold 💯)

| Type               | Rule                                 |
| ------------------ | ------------------------------------ |
| Binary Tree        | Max 2 children                       |
| Full BT            | 0 or 2 children only                 |
| Complete BT        | All levels full except last (L→R)    |
| Almost Complete BT | Nearly complete (last level partial) |
| BST                | Left < Root < Right                  |

---

## 9️⃣ One-Line Memory Trick 🧠

* **Binary Tree** → 2 children max
* **Full** → 0 or 2 children
* **Complete** → Fill left first
* **BST** → Sorted structure

---
---
---
---
---
---
---
---
---
---
---


So remember this:

> **Binary / Full → about NUMBER of children**
> **Complete / Almost Complete → about POSITION of nodes**
> **BST → about VALUE ordering**

---

# 1️⃣ Complete Binary Tree (CBT) — SUPER CLEAR

### 🧠 ONE RULE ONLY

> **Fill nodes level by level, LEFT to RIGHT**

That’s it. Nothing about values.

---

### ✅ Example (Complete)

```
        A
       / \
      B   C
     / \  /
    D   E F
```

Read level-wise:

* Level 0 → A
* Level 1 → B C
* Level 2 → D E F (left filled first ✔)

---

### ❌ Example (NOT Complete)

```
        A
       / \
      B   C
       \
        E
```

❌ Why?

* Left child of B is missing
* Right child exists → GAP ❌

📌 **No gaps allowed when reading left to right**

---

### 🧠 Mental Test (VERY IMPORTANT)

👉 Scan tree like a **queue (BFS)**
👉 Once you see a **NULL**,
👉 you must **NOT see any node later**

---

# 2️⃣ Almost Complete Binary Tree (STOP OVERTHINKING)

### 🔹 Truth (exam secret)

⚠️ **Almost Complete = Complete Binary Tree**
in **most DSA books & exams**

It just means:

> Last level may be **not fully filled**,
> but **filled from LEFT side**

---

### ✅ Example

```
        1
       / \
      2   3
     /
    4
```

✔ Last level incomplete
✔ Missing only at RIGHT
✔ So it’s **Almost Complete**

📌 This is ALSO a **Complete Binary Tree**

---

### ❌ Example (Not Almost Complete)

```
        1
       / \
      2   3
       \
        5
```

❌ Gap on left → invalid

---

# 3️⃣ Binary Search Tree (BST) — DIFFERENT CATEGORY

🚨 **BST is NOT about shape**
🚨 **BST is about VALUES**

---

### 🧠 ONE GOLDEN RULE

For **every node**:

```
Left Subtree  < Node < Right Subtree
```

---

### ✅ BST Example

```
        10
       /  \
      5    20
     / \     \
    3   7     30
```

Check:

* Left of 10 → all < 10 ✔
* Right of 10 → all > 10 ✔

---

### ❌ Not a BST

```
        10
       /  \
      5    8
```

❌ Right child < parent

---

### 🚨 VERY IMPORTANT

A BST:

* ❌ **does NOT have to be complete**
* ❌ **does NOT have to be full**

Example:

```
    10
      \
       20
         \
          30
```

✔ Valid BST
❌ Not complete
❌ Not full

---

# 4️⃣ Put Everything Together (THIS WILL CLEAR ALL CONFUSION)

### 📌 SAME TREE — DIFFERENT QUESTIONS

```
        10
       /  \
      5    20
     /
    3
```

| Question              | Answer                 |
| --------------------- | ---------------------- |
| Binary Tree?          | ✅ Yes                  |
| Full Binary Tree?     | ❌ No (5 has one child) |
| Complete Binary Tree? | ✅ Yes                  |
| Almost Complete?      | ✅ Yes                  |
| BST?                  | ✅ Yes                  |

---

# 5️⃣ One-Line Decision Rules (EXAM LIFE SAVER)

### ✔ Binary Tree?

→ Max 2 children

### ✔ Full Binary Tree?

→ Node has **0 or 2 children only**

### ✔ Complete / Almost Complete?

→ **Filled level-wise, left first**

### ✔ BST?

→ **Left < Root < Right**

---

# 6️⃣ Why This Topic Feels Hard (Truth)

Because:

* **Shape rules** (complete)
* **Count rules** (full)
* **Value rules** (BST)

👉 Your brain tries to mix them
👉 They are **independent checks**
