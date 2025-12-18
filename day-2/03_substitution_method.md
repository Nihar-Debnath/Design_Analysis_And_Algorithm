Now you’re asking about the **Substitution Method** for solving a recurrence — a very important concept in **DAA (Design and Analysis of Algorithms)**.

Let’s take it **step-by-step from a beginner’s point of view**, using your recurrence:

$$
T(n) = T(n/2) + c
$$

---

## 🧩 Step 1: Understand What the Recurrence Means

This means:

* The problem of size `n` takes time equal to:

  * Time for solving **a smaller problem** of size `n/2`, plus
  * Some **constant work** `c` done outside recursion (like comparing the middle element in binary search).

So, we want to find **how T(n) grows** when n becomes large.

---

## 🧮 Step 2: Apply the Substitution Method (expand it step by step)

We’ll **repeatedly substitute** the recurrence into itself until we reach the base case.

Let’s do it carefully 👇

---

### 🧠 Given:

$$
T(n) = T(n/2) + c
$$

Now, expand the **T(n/2)** term using the same recurrence:

$$
T(n/2) = T(n/4) + c
$$

Substitute this back into the first equation:

$$
T(n) = T(n/4) + c + c = T(n/4) + 2c
$$

---

Now expand one more step:

$$
T(n/4) = T(n/8) + c
$$

Substitute again:

$$
T(n) = T(n/8) + 3c
$$

---

Continue this process…

After **k** steps:

$$
T(n) = T(n / 2^k) + k \cdot c
$$

---

## 🧩 Step 3: Find When It Reaches the Base Case

The recursion stops when the input size becomes **1**,
i.e., when

$$
n / 2^k = 1
$$

Solve for **k**:

$$
2^k = n
$$
$$
k = \log_2 n
$$

That means after `log₂n` steps, recursion ends.

---

## 🧮 Step 4: Substitute Back k = log₂n

$$
T(n) = T(1) + c \cdot \log_2 n
$$

---

## 🧩 Step 5: Simplify the Base Case

If ( T(1) ) is constant $(say ( T(1) = c_0 ))$,

$$
T(n) = c_0 + c \cdot \log_2 n
$$

In Big-O notation, constants don’t matter, so:

$$
T(n) = O(\log n)
$$

---

## ✅ Final Answer

$$
\boxed{T(n) = O(\log n)}
$$

---

## 🔹 Intuitive Meaning

At every step:

* You do a small, constant amount of work (`c`).
* You cut the problem size in half.
* The number of times you can halve `n` before reaching 1 = **log₂n** times.

Hence total work = **c × log₂n**, i.e. **O(log n)**.

---

## 🔁 Summary Table

| Step       | Expansion             | Result           |
| ---------- | --------------------- | ---------------- |
| 1          | T(n) = T(n/2) + c     | Given            |
| 2          | = T(n/4) + 2c         | 1st substitution |
| 3          | = T(n/8) + 3c         | 2nd substitution |
| …          | = T(n / 2^k) + k·c    | after k steps    |
| Stop when  | n / 2^k = 1           | → k = log₂n      |
| Final      | T(n) = T(1) + c·log₂n | Simplify         |
| Complexity | O(log n)              | ✅                |

---

<br>
<br>
<br>

---


## 🧠 What is the **Substitution Method**?

The **Substitution Method** is a way to **solve recurrence relations** —
that means, it helps us **find the time complexity** of recursive algorithms.

---

### 🧩 In very simple words:

> The **Substitution Method** means you **keep substituting (expanding)** the recurrence relation again and again until you see a clear pattern.
> Then, you **simplify** it to find a formula or Big-O result.

---

### 💡 Why it’s called “Substitution”?

Because each time, you **substitute** the smaller part (like T(n/2), T(n-1), etc.)
with its own formula from the recurrence.

You repeat that **step-by-step** until you reach the smallest case (called the **base case**).

---

## 🧮 Example to Understand It

Let’s take the recurrence:
$$
T(n) = T(n/2) + c
$$

where

* (T(n)) = total time for size `n`,
* (T(n/2)) = time for half the size,
* (c) = constant time per step.

---

### Step 1: Write the given recurrence again

$$
T(n) = T(n/2) + c
$$

### Step 2: Substitute the smaller term with its own recurrence

We know
$$
T(n/2) = T(n/4) + c
$$

Now substitute this back:
$$
T(n) = $$T(n/4) + c$$ + c = T(n/4) + 2c
$$

### Step 3: Do one more substitution

$$
T(n/4) = T(n/8) + c
$$

So:
$$
T(n) = T(n/8) + 3c
$$

You can now **see a pattern** forming.

---

### Step 4: Write the general form

After **k** substitutions:

$$
T(n) = T(n / 2^k) + k \cdot c
$$

---

### Step 5: Find where it stops (base case)

We stop when the problem size = 1.

That happens when:

$$
n / 2^k = 1 \implies k = \log_2 n
$$

---

### Step 6: Substitute that back

$$
T(n) = T(1) + c \cdot \log_2 n
$$

Since (T(1)) and (c) are constants:

$$
\boxed{T(n) = O(\log n)}
$$

---

## 🧩 In plain language:

The **substitution method** is just a **step-by-step expansion** of the recurrence until you:

1. Recognize a pattern, and
2. Can express the total work as a simple function of n.

---

## ✅ Key Idea Summary

| Step | What You Do                           | Example              |
| ---- | ------------------------------------- | -------------------- |
| 1️⃣  | Write the recurrence                  | T(n) = T(n/2) + c    |
| 2️⃣  | Replace smaller term with its formula | T(n) = T(n/4) + 2c   |
| 3️⃣  | Keep repeating                        | T(n) = T(n/8) + 3c   |
| 4️⃣  | Find pattern                          | T(n) = T(n/2^k) + kc |
| 5️⃣  | Stop when subproblem = 1              | k = log₂n            |
| 6️⃣  | Simplify                              | T(n) = O(log n)      |
