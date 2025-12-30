# 1️⃣ Why Do We Need Dynamic Programming?

### The core problem:

Some problems have:

* **Huge number of overlapping subproblems**
* **Recursive solutions that repeat work**

Example:

* Fibonacci numbers
* Shortest path problems
* Knapsack
* Matrix chain multiplication

👉 **Brute force / recursion becomes very slow**

---

# 2️⃣ What is Dynamic Programming (DP)?

## 📘 Definition (Exam-ready)

> **Dynamic Programming** is an algorithmic technique that solves complex problems by:
>
> * Breaking them into **smaller overlapping subproblems**
> * Solving each subproblem **once**
> * Storing the result and reusing it

📌 Coined by **Richard Bellman**

---

# 3️⃣ Two Core Properties of DP (VERY IMPORTANT)

A problem can be solved using DP **only if both are true**:

---

## ✅ 1. Optimal Substructure

> Optimal solution of the problem can be built from optimal solutions of its subproblems.

Example:

* Shortest path A → D depends on shortest path A → B and B → D

---

## ✅ 2. Overlapping Subproblems

> Same subproblems are solved multiple times.

Example:

* Fibonacci(5) calculates Fibonacci(3) many times

---

# 4️⃣ Simple Real-World Intuition for DP

### Problem:

You want to climb stairs with **minimum cost**.

❌ Without DP:

* You recalculate same steps again and again

✅ With DP:

* Store cost at each step
* Reuse it

👉 **Work once, remember forever**

---

# 5️⃣ How DP Works (Two Approaches)

---

## 🔹 1. Top-Down (Memoization)

* Start from main problem
* Go down recursively
* Store answers in a table

🧠 Think: **“Solve → store → reuse”**

---

## 🔹 2. Bottom-Up (Tabulation)

* Solve smallest subproblem first
* Build up to final answer

🧠 Think: **“Build step by step”**

---

# 6️⃣ What is a Greedy Algorithm?

## 📘 Definition

> A **Greedy Algorithm** makes the **best local choice** at each step, hoping it leads to the global optimum.

📌 It **never reconsiders** its decision.

---

## 🧠 Real-Life Greedy Example

### Problem:

Give change using minimum coins.

Coins: `1, 5, 10`

Greedy choice:

* Always pick **largest coin first**

For 28:

```
10 + 10 + 5 + 1 + 1 + 1
```

Works ✔

---

# 7️⃣ Why Greedy Sometimes FAILS?

Coins: `1, 3, 4`
Amount: `6`

### Greedy:

```
4 + 1 + 1 = 3 coins
```

### Optimal:

```
3 + 3 = 2 coins
```

❌ Greedy fails
✅ DP finds optimal

---

# 8️⃣ Greedy vs Dynamic Programming (EXAM GOLD)

| Feature          | Greedy          | Dynamic Programming |
| ---------------- | --------------- | ------------------- |
| Decision         | Local optimum   | Global optimum      |
| Backtracking     | ❌ No            | ✅ Yes               |
| Memory           | Very low        | Higher              |
| Complexity       | Fast            | Slower              |
| Accuracy         | Sometimes wrong | Always correct      |
| Reuse of results | ❌ No            | ✅ Yes               |

---

# 9️⃣ When to Use Greedy vs DP?

### Use **Greedy** when:

✔ Problem has **greedy-choice property**
✔ Local choice leads to global optimum
✔ Speed is priority

Examples:

* Kruskal’s Algorithm
* Prim’s Algorithm
* Huffman Coding
* Activity Selection

---

### Use **Dynamic Programming** when:

✔ Overlapping subproblems
✔ Optimal substructure
✔ Greedy fails

Examples:

* Knapsack (0/1)
* Longest Common Subsequence
* Matrix Chain Multiplication
* Fibonacci
* Coin Change (general)

---

# 🔟 DAA Exam One-Line Definitions

### Dynamic Programming:

> Solve once, store, reuse.

### Greedy:

> Choose best now, hope for best later.

---

# 🧠 Memory Trick

* **Greedy** → *Fast but risky*
* **DP** → *Slow but safe*






---
---
---
---
---




# 📘 Introduction to Dynamic Programming (DP)

**Dynamic Programming | Greedy vs Dynamic Programming | DAA**

---

## 1️⃣ What Problem Does Dynamic Programming Solve?

Many algorithmic problems involve:

* Multiple **choices at each stage**
* Need to find the **best (optimal) solution**
* Repeated solving of the **same subproblems**

❌ Brute force or naive recursion:

* Tries all possibilities
* Very slow (exponential time)

✅ **Dynamic Programming**:

* Avoids repeated work
* Guarantees **optimal solution**

---

## 2️⃣ Greedy Method vs Dynamic Programming

---

### 🔹 Greedy Method

**Definition**

> Greedy method makes the **locally optimal choice** at each step, hoping it leads to the global optimum.

**Key Idea**
👉 “Take the best option available right now.”

**Important Limitation**
❌ Local optimum ≠ Global optimum (always)

---

### ❌ Greedy Failure (Shortest Path Example)

Suppose:

* At a node, greedy chooses the **smallest immediate edge**
* Later, that choice leads to a **larger total path cost**

✔ Greedy does **not explore all possibilities**
✔ Once a decision is made, it is **never changed**

---

### 🔹 Dynamic Programming

**Definition (Exam-ready)**

> Dynamic Programming solves a problem by exploring **all possible sequences of decisions**, breaking the problem into **overlapping subproblems**, solving each **once**, and storing the results.

✔ Guarantees **global optimal solution**
✔ Trades **extra memory** for **correctness and efficiency**

---

## 3️⃣ Why Dynamic Programming Works (Core Difference)

| Greedy         | Dynamic Programming            |
| -------------- | ------------------------------ |
| Local decision | Global decision                |
| Fast           | Slightly slower                |
| Low memory     | Uses table (memory)            |
| May fail       | Always correct (if applicable) |

---

## 4️⃣ Two Key Features of Dynamic Programming (MOST IMPORTANT)

A problem can be solved using DP **only if BOTH conditions are satisfied**.

---

## ✅ 1. Optimal Substructure

**Meaning**

> The optimal solution of a problem can be constructed from optimal solutions of its subproblems.

### Example:

Shortest path A → D depends on:

* Shortest path A → B
* Shortest path B → D

📌 Similar to **Divide and Conquer**

* Example: Merge Sort
* But **this alone is not enough for DP**

---

## ✅ 2. Overlapping Subproblems (CRUCIAL DIFFERENCE)

**Meaning**

> Same subproblems are solved **again and again**.

📌 This is what separates **Dynamic Programming** from **Divide and Conquer**.

---

## 5️⃣ Fibonacci Series Example (Classic DP Explanation)

### Recursive Definition:

[
F(n) = F(n-1) + F(n-2)
]

---

### ❌ Without DP (Naive Recursion)

For `F(4)`:

* `F(3)` and `F(2)` are recalculated multiple times
* `F(2)`, `F(1)`, `F(0)` repeat again and again

⏱ Time Complexity:
[
O(2^n) \quad \text{(Exponential)}
]

---

### ✅ With DP (Memoization / Tabulation)

* Store results of `F(0), F(1), F(2), ...`
* Each Fibonacci value is computed **only once**

⏱ Time Complexity:
[
O(n)
]

🧠 **Core DP idea**:

> “Solve once → Store → Reuse”

---

## 6️⃣ How Dynamic Programming Improves Efficiency

| Approach            | Time Complexity     |
| ------------------- | ------------------- |
| Naive recursion     | Exponential         |
| Dynamic Programming | Polynomial / Linear |

DP avoids recomputation by using:

* **Memoization (Top-Down)**
* **Tabulation (Bottom-Up)**

---

## 7️⃣ Applications of Dynamic Programming (From Video)

Dynamic Programming is widely used in **optimization problems**:

1. **Matrix Chain Multiplication**
2. **Multi-Stage Graph**
3. **Travelling Salesman Problem (TSP)**
4. **Longest Common Subsequence (LCS)**
5. **Subset Sum Problem**
6. **All-Pairs Shortest Path (Floyd-Warshall)**
7. **0-1 Knapsack Problem**

---

## 8️⃣ One-Line Exam Answers (Very Important)

* **Greedy Algorithm**:

  > Makes locally optimal choices; may not give global optimum.

* **Dynamic Programming**:

  > Solves overlapping subproblems and stores results to ensure optimal solution.

* **Key Difference from Divide & Conquer**:

  > DP has **overlapping subproblems**.

---

## 9️⃣ Memory Trick (Never Forget)

* **Greedy** → *Fast but risky*
* **Dynamic Programming** → *Slow but safe*

---

## 🔟 Final Summary (Perfect Conclusion Line)

> Dynamic Programming guarantees optimal solutions by solving and storing overlapping subproblems, whereas the Greedy method makes quick local decisions that may fail to produce a global optimum.
