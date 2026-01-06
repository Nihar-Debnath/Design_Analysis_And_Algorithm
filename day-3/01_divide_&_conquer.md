# Divide and Conquer | Algorithm (DAA)

---

## 1️⃣ What is Divide and Conquer?

**Divide and Conquer** is an **algorithm design technique**.

It means:

> **Divide** a big problem into smaller problems
> **Conquer** the small problems (solve them)
> **Combine** their results to get the final answer

That’s the whole idea.

---

## 2️⃣ Why do we use Divide and Conquer?

Because:

* Big problems are **hard**
* Small problems are **easy**
* Computers solve **smaller repeated tasks faster**

So instead of solving one big problem directly, we:

* break it into parts
* solve parts independently
* merge the results

---

## 3️⃣ The 3 Core Steps (VERY IMPORTANT)

Every divide and conquer algorithm follows **exactly these 3 steps**:

### 1️⃣ Divide

Split the problem into **smaller subproblems**
Usually of **equal size**

### 2️⃣ Conquer

Solve the subproblems

* If small enough → solve directly (base case)
* Else → apply divide and conquer again (recursion)

### 3️⃣ Combine

Merge the solutions of subproblems
to form the solution of the original problem

---

## 4️⃣ Simple real-life analogy 🌱

### Searching a word in a dictionary 📖

* **Divide**: Open the dictionary in the middle
* **Conquer**: Decide left half or right half
* **Combine**: Continue until you find the word

This is **Binary Search** — a divide and conquer algorithm.

---

## 5️⃣ Key characteristics (theory points)

Divide and Conquer algorithms usually have:

* **Recursion**
* **Smaller identical subproblems**
* **Same strategy at every level**
* **Base case** to stop recursion

---

## 6️⃣ How Divide and Conquer looks in DAA terms

When we analyze divide and conquer algorithms, we get a **recurrence relation**:

\[
T(n) = aT(n/b) + f(n)
\]

Where:

* `a` → number of subproblems
* `n/b` → size of each subproblem
* `f(n)` → work done to divide + combine

This equation is the **mathematical model** of divide and conquer.

---

## 7️⃣ Common Divide and Conquer Algorithms

| Algorithm         | Divide              | Conquer         | Combine              |
| ----------------- | ------------------- | --------------- | -------------------- |
| Binary Search     | Split array in half | Search one half | No combine           |
| Merge Sort        | Split array         | Sort halves     | Merge                |
| Quick Sort        | Partition array     | Sort partitions | Combine by placement |
| Strassen’s Matrix | Split matrices      | Multiply parts  | Add results          |

---

## 8️⃣ Advantages (theory)

✅ Efficient for large problems
✅ Often reduces time complexity
✅ Easy to understand conceptually
✅ Works well with recursion

---

## 9️⃣ Disadvantages (theory)

❌ Uses recursion (extra stack space)
❌ Overhead of function calls
❌ Not suitable for all problems
❌ Sometimes complex to implement

---

## 🔟 Divide and Conquer vs Brute Force

| Brute Force                 | Divide & Conquer               |
| --------------------------- | ------------------------------ |
| Solve whole problem at once | Break into parts               |
| Slow for large input        | Faster                         |
| Simple but inefficient      | Slightly complex but efficient |

---

## 1️⃣1️⃣ When to use Divide and Conquer?

Use it when:

* Problem can be broken into **independent subproblems**
* Subproblems are **similar**
* Combining solutions is **easy**

---

## 1️⃣2️⃣ One-line exam definition 📝

> **Divide and Conquer is an algorithmic technique that solves a problem by recursively dividing it into smaller subproblems, solving them, and combining their solutions.**

---

## 🧠 Memory Trick

> **Divide → Solve → Combine**
