# The 3 main methods to solve a Recurrence Relation (DAA)

In DAA, once you **write** a recurrence relation, the next goal is:

> **Find how fast it grows** (time complexity)

To do that, we use **three standard methods**:

1️⃣ Substitution Method
2️⃣ Recursion Tree Method
3️⃣ Master Method (Master Theorem)

---

## Before we start — one IMPORTANT thing

All three methods try to answer **the same question**:

> “How big does `T(n)` become as `n` grows?”

They are just **different ways of thinking**.

---

# 1️⃣ Substitution Method (Guess + Prove)

### Beginner idea

Think of this as:

> **“Guess the answer, then prove it’s correct.”**

That’s literally it.

---

### Why is it called substitution?

Because:

* You **substitute** your guessed solution
* Back into the recurrence
* To check if it works

---

### Simple example

\[
T(n) = T(n-1) + 1
\]

### Step 1: Make a guess

Looking at it, you might guess:

\[
T(n) = O(n)
\]

---

### Step 2: Substitute the guess

Assume:
\[
T(n-1) = O(n-1)
\]

Put it into the recurrence:

\[
T(n) = O(n-1) + 1
\]

Which simplifies to:

\[
T(n) = O(n)
\]

✔ Guess works.

---

### When to use substitution

✔ When the recurrence is **simple**
✔ When you already **suspect the answer**
❌ Not great for complex recurrences

---

### Memory line

> **Substitution = Guess → Replace → Verify**

---

# 2️⃣ Recursion Tree Method (Visual Thinking)

### Beginner idea

Think of recursion like a **family tree** 🌳

* Each function call
* Creates smaller calls
* Until the base case

---

### Why is it called a tree?

Because:

* Root = original problem
* Children = recursive calls
* Leaves = base cases

---

### Example

\[
T(n) = 2T\left(\frac{n}{2}\right) + n
\]

---

### Step 1: Draw the tree

* Level 0: cost = `n`
* Level 1: two calls → each costs `n/2`
* Level 2: four calls → each costs `n/4`
* …
* Last level: base cases

---

### Step 2: Add cost at each level

Each level total cost = `n`

---

### Step 3: Count number of levels

Number of levels = `log n`

---

### Step 4: Total cost

\[
n + n + n + \dots (\log n \text{ times})
\]

\[
T(n) = O(n \log n)
\]

---

### When to use recursion tree

✔ To **understand** how recursion behaves
✔ Very helpful for exams
✔ Good stepping stone before Master Theorem

---

### Memory line

> **Recursion Tree = Draw → Add per level → Count levels**

---

# 3️⃣ Master Method (Fast & Formula-based)

### Beginner idea

Think of this as:

> **“A shortcut formula”** for common recurrences

You don’t draw, you don’t guess — you **compare**.

---

### The form it works on

Master Method works only if recurrence looks like:

\[
T(n) = aT\left(\frac{n}{b}\right) + f(n)
\]

Where:

* `a` = number of subproblems
* `n/b` = size of each subproblem
* `f(n)` = extra work

---

### Core idea (very important)

You compare:

* ( f(n) )
* with ( n^{\log_b a} )

---

### Three cases

#### Case 1:

If ( f(n) ) is **smaller**

\[
T(n) = O(n^{\log_b a})
\]

#### Case 2:

If ( f(n) ) is **equal**

\[
T(n) = O(n^{\log_b a} \log n)
\]

#### Case 3:

If ( f(n) ) is **bigger**

\[
T(n) = O(f(n))
\]

---

### Example (Merge Sort)

\[
T(n) = 2T\left(\frac{n}{2}\right) + n
\]

* ( a = 2 )
* ( b = 2 )
* ( f(n) = n )
* ( n^{\log_2 2} = n )

👉 Case 2

\[
T(n) = O(n \log n)
\]

---

### When to use Master Method

✔ Fastest method
✔ Most used in exams
✔ Only for divide & conquer recurrences

❌ Doesn’t work for `T(n-1)` type relations

---

### Memory line

> **Master Method = Compare f(n) with ( n^{\log_b a} )**

---

# Final comparison (easy to remember)

| Method         | Idea             | Best for                  |
| -------------- | ---------------- | ------------------------- |
| Substitution   | Guess & prove    | Simple recurrences        |
| Recursion Tree | Draw & sum       | Understanding + exams     |
| Master Method  | Formula shortcut | Standard divide & conquer |

---

## One final sentence to lock it in 🔒

> **Substitution guesses, Tree visualizes, Master computes instantly.**