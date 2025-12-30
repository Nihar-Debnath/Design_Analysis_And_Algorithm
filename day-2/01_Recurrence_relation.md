## What is a recurrence relation? (Beginner version)

### Step 1: Forget algorithms for a moment

Think about this **simple idea**:

> Sometimes, a value depends on **its previous value**.

Example from daily life:

* Your **age next year** depends on your **age this year**.
* Your **bank balance** tomorrow depends on today’s balance.

This kind of “self-dependence” is the core idea.

---

## Step 2: Simple math example (not DAA yet)

Consider this rule:

> “Each number is double the previous one”

\[
f(n) = 2f(n-1)
\]

This is a **recurrence relation** because:

* The value at `n`
* Depends on the value at `n-1`

👉 **Any formula that defines something using its smaller version is a recurrence relation.**

---

## Step 3: Now the definition (very simple)

> **A recurrence relation is an equation that defines a problem in terms of smaller instances of the same problem.**

Read that again slowly.

* “Defines a problem”
* “Using smaller instances”
* “Of the same problem”

That’s it. No complexity yet.

---

## Step 4: Why “recurrence”?

The word **recurrence** comes from **“recur”**, which means:

> **to happen again and again**

So:

* Same problem
* Solved again
* With smaller input

---

## Step 5: Extremely simple DAA-style example

Imagine this function:

```text
sum(n):
    if n == 1 return 1
    return n + sum(n-1)
```

Here:

* To compute `sum(n)`
* You need `sum(n-1)`

So we write:

\[
T(n) = T(n-1) + c
\]

This is a **recurrence relation**.

Why?

* `T(n)` depends on `T(n-1)`
* Same problem, smaller size

---

## Step 6: One sentence you should ALWAYS remember

> **A recurrence relation expresses a problem’s solution using solutions of smaller versions of the same problem.**

This sentence works:

* In exams
* In interviews
* In understanding algorithms

---

## Step 7: Why recurrence relations appear in DAA

In DAA, many algorithms are **recursive**:

* A function calls **itself**
* With **smaller input**

Whenever you see:

* recursion
  → a recurrence relation exists.

---

## Step 8: What a recurrence relation is NOT

❌ It is **not** the final time complexity
❌ It is **not** Big-O notation
❌ It is **not** a loop
❌ It is **not** Master Theorem

It is just:

> **A relationship showing dependency on smaller inputs**

---

## Step 9: Ultra-short memory hook 🧠

Remember this line forever:

> **“Same problem, smaller input.”**

If that exists → **recurrence relation exists**.

---
---
---
---
---


## 🧠 What is a Recurrence Relation?

A **recurrence relation** is simply an **equation that defines a problem in terms of smaller subproblems**.

In other words, it shows how the **time complexity** of a problem depends on the **time complexity of smaller versions** of the same problem.

---

### 🔹 Example 1: Linear Search

If you check each element one by one in an array of size `n`:

* You check one element → constant time = **O(1)**
* Then you search the remaining `n - 1` elements.

So,
👉 **T(n) = T(n - 1) + O(1)**
(base case: when `n = 1`, T(1) = O(1))

That’s a **recurrence relation**.

It means:

> Time to solve size `n` = time to solve smaller problem (size `n-1`) + constant work.

---

## 🔹 Example 2: Binary Search (our main focus)

Let’s recall how **binary search** works:

1. You have a **sorted array**.
2. Check the **middle element**:

   * If it’s the target → done.
   * If target < middle → search **left half**.
   * If target > middle → search **right half**.

So, every time, the **problem size reduces by half**.

---

### 🧩 Step 1: Define What We’re Measuring

Let’s define
👉 **T(n)** = time taken by binary search on an array of size `n`.

---

### 🧩 Step 2: Identify the Work Done at Each Step

At each step:

* Checking the middle element → takes **constant time** = O(1)
* Then we search **only one half** of the array → of size `n/2`

---

### 🧩 Step 3: Write the Recurrence Relation

So we get:

$$
T(n) = T(n/2) + O(1)
$$

and
$$
T(1) = O(1)
$$

That’s the **recurrence relation for binary search**.

It literally says:

> “To search `n` elements, we only need to search `n/2` elements next time — plus a small constant amount of work.”

---

## 🧮 Step 4: Solve the Recurrence

Now we need to find what **T(n)** equals in Big O notation.

We’ll solve:

$$
T(n) = T(n/2) + 1
$$

(for simplicity, drop constants)

---

### 🪜 Method 1: Recursion Tree Method (Visualization)

Let’s “unfold” the recurrence:

```
T(n) = T(n/2) + 1
     = T(n/4) + 1 + 1
     = T(n/8) + 1 + 1 + 1
     = ...
```

At each level:

* The problem size divides by 2.
* The number of levels = how many times you can divide n by 2 until you reach 1.

That is:
$$
\text{Levels} = \log_2 n
$$

And at each level, constant work `1` is done.

So total work =
$$
1 + 1 + 1 + ... + 1 \text{ (log n times)} = O(\log n)
$$

✅ **Final Answer:**
$$
T(n) = O(\log n)
$$

---

### 🪜 Method 2: Master Theorem (Shortcut Method)

Recurrence:
$$
T(n) = aT(n/b) + f(n)
$$

where

* `a` = number of subproblems
* `b` = factor by which size reduces
* `f(n)` = work done outside recursion

For binary search:

* `a = 1` (one subproblem)
* `b = 2` (size divides by 2)
* `f(n) = O(1)`

Compute:
$$
n^{\log_b a} = n^{\log_2 1} = n^0 = 1
$$

Now compare `f(n)` with `n^{\log_b a}`:

* `f(n)` = O(1)
* `n^{\log_b a}` = 1

They are the same order → Case 2 of Master Theorem:

$$
T(n) = O(\log n)
$$

✅ Again, **T(n) = O(log n)**

---

## ✅ Final Summary

| Concept                      | Explanation                                                    |
| ---------------------------- | -------------------------------------------------------------- |
| **Recurrence Relation**      | Equation expressing time for size `n` in terms of smaller size |
| **Binary Search Recurrence** | `T(n) = T(n/2) + O(1)`                                         |
| **Base Case**                | `T(1) = O(1)`                                                  |
| **Solving**                  | Using recursion tree or master theorem                         |
| **Final Complexity**         | `O(log n)`                                                     |

---

## 🧩 Quick Intuition

At each binary search step:

* The array becomes half smaller.
* The number of halvings until one element remains = **log₂n**.

So the total time = **O(log n)**.


---

<br>
<br>
<br>

---

## 🧩 What does **T** mean?

When we write **T(n)** in algorithm analysis, the **T** stands for **Time** (or sometimes **Total Time**).

So:

> **T(n)** = the **total time** (or number of operations) your algorithm takes to handle an input of size **n**.

That’s all it means.

It’s just a **function name** — we could’ve called it anything, like `Time(n)` or `Cost(n)` or `F(n)` — but in computer science, people usually write it as **T(n)** for "Time as a function of n."

---

### 🧠 Analogy: Think Like a Math Function

If you have a math function:

> f(x) = x² + 1
> that gives you a number for any x.

Similarly, in algorithms:

> T(n) = time it takes to solve input of size n.

So if n = 10, T(10) means “time to run the algorithm on 10 elements.”

---

## 💡 Where does T(n) come from?

When we analyze an algorithm, we want to **describe how its running time grows** when the input size increases.

We start by thinking:

* What’s the time for the **biggest** problem (size n)?
* How is it related to **smaller subproblems**?

That relation — between big and small problems — gives us a **recurrence relation**.

---

### Example 1: Binary Search Intuition

Suppose you’re searching a sorted array of size **n**.

Binary Search does:

1. Check the **middle** element → constant time → let’s call it **1 unit of time**.
2. Then search **half** the array → so time = whatever time it takes to search n/2 elements.

That means:

> Total time = (time for smaller half) + (constant checking work)

We can express that as:

$$
T(n) = T(n/2) + 1
$$

That’s the **recurrence**:

* **T(n)** = time for the whole array
* **T(n/2)** = time for the smaller half
* **+ 1** = constant extra work

---

### Example 2: Linear Search Intuition

You check one element at a time:

$$
T(n) = T(n - 1) + 1
$$

* You checked one element → +1 constant time
* You have n–1 elements left → smaller problem

Again, **T(n)** just represents “time for problem size n.”

---

## 🔹 Why not just use O(n) directly?

Because recurrence relations help us **derive** the Big-O complexity.
We use them when an algorithm’s structure is **recursive**, i.e., it calls itself on smaller inputs.

Binary Search, Merge Sort, Quick Sort, etc. — all these are recursive, so recurrence is the natural way to describe their time.

---

## ✅ Summary

| Symbol      | Meaning                                          |
| ----------- | ------------------------------------------------ |
| **T(n)**    | Total time (or number of steps) for input size n |
| **T(n/2)**  | Time for a smaller subproblem (half the size)    |
| **+1 / +c** | Extra constant work outside recursion            |
| **T(1)**    | Base case (smallest input, takes constant time)  |

---

**So T(n) comes from “Time taken by algorithm for input size n.”**
We use it to express how that time depends on smaller instances of the same problem.
