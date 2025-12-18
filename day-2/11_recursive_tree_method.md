## 1️⃣ What is the Recursion Tree Method?

**Recursion Tree Method** is a way to **understand and solve recurrence relations** by:

👉 **Drawing the recursive calls as a tree**
👉 **Adding the work done at each level**
👉 **Summing all levels to get total time**

Think of it like:

> *“Let me see where time is actually being spent.”*

---

## 2️⃣ Why is it called a “tree”?

Because recursive calls behave like a **family tree**:

* Parent problem calls child problems
* Children call smaller children
* This continues until a base case

Each **node** = one function call
Each **level** = one recursion depth

---

## 3️⃣ What does each node represent?

Each node represents:

> **Work done at that call**

This includes:

* dividing the problem
* combining results
* any extra computation (`+ n`, `+ log n`, etc.)

---

## 4️⃣ Basic idea in 3 steps (memorize this)

### Step 1

Draw how the problem splits at each call

### Step 2

Write the **cost at each level**

### Step 3

Add all level costs

That’s it. No magic.

---

## 5️⃣ Why do we even need Recursion Tree Method?

Because:

* ❌ Master Theorem doesn’t work for all recurrences
* ❌ Substitution can feel abstract

Recursion Tree:

* makes recursion **visible**
* shows **where time comes from**
* works for **almost every recurrence**

---

## 6️⃣ How to “draw” the recursion tree (mentally)

Let’s say you have a recurrence like:

> “Solve one big problem → it creates smaller problems → repeat”

You imagine:

* **Root** = original problem `T(n)`
* **Next level** = problems created from it
* **Leaves** = base cases

Each level is **smaller than the one above**.

---

## 7️⃣ What do we calculate in a recursion tree?

We calculate **two things only**:

### 1️⃣ Cost per level

Add the work done by **all nodes at the same depth**

### 2️⃣ Number of levels

How deep the recursion goes until base case

---

## 8️⃣ Important intuition (THIS IS KEY)

> **Total Time = (Work per level) × (Number of levels)**

Sometimes:

* work per level **increases**
* sometimes it **decreases**
* sometimes it stays **constant**

Recursion Tree helps you *see* this.

---

## 9️⃣ Example intuition (no solving)

If:

* each level does **less work**
* and depth is **small**

👉 total time is small

If:

* each level does **same work**
* and depth is **log n**

👉 total time is `n log n`

---

## 🔟 When Recursion Tree Method is best

Use it when:

* Master Theorem ❌ doesn’t apply
* subproblem sizes are weird (`√n`, `n−1`)
* you want **intuition, not shortcuts**

---

## 1️⃣1️⃣ When NOT to use it

Avoid when:

* recurrence is trivial
* Master Theorem gives direct answer faster

---

## 1️⃣2️⃣ One-line exam definition 📝

> **Recursion Tree Method is a technique to analyze recurrence relations by representing recursive calls as a tree and summing the cost at each level.**

---

## 🧠 Memory Trick

> **Recursion Tree = draw calls → add level costs → get total time**
