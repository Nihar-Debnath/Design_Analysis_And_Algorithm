## 🧠 **What are Asymptotic Notations?**

> **Asymptotic Notations** are **mathematical tools** used to describe the **efficiency of an algorithm** when the input size (**n**) becomes very large.

In other words:

> They tell us **how fast or slow an algorithm grows** as the input size increases.

---

### ⚙️ **Why we use them:**

When analyzing an algorithm, we don’t care about:

* exact seconds,
* hardware, or
* language used.

We only care about **how performance scales** when input grows (e.g., from 10 to 1 million).

---

### 🧩 **Example:**

Two algorithms for the same problem:

| Input Size (n) | Algo A (2n + 3 steps) | Algo B (5n² + 2 steps) |
| -------------- | --------------------- | ---------------------- |
| 10             | 23                    | 502                    |
| 100            | 203                   | 50,002                 |

When **n** grows, **n²** grows much faster than **n**,
so Algo A is more efficient for large inputs.

➡ We use **asymptotic notations** to describe this mathematically.

---

## 📊 **Types of Asymptotic Notations**

There are **three main notations**:

| Symbol      | Name                   | Describes                               | Think of it as       |
| ----------- | ---------------------- | --------------------------------------- | -------------------- |
| **O(f(n))** | **Big O Notation**     | **Upper bound (worst case)**            | "At most this fast"  |
| **Ω(f(n))** | **Big Omega Notation** | **Lower bound (best case)**             | "At least this fast" |
| **Θ(f(n))** | **Theta Notation**     | **Tight bound (average/expected case)** | "Exactly this fast"  |

---

## 🔹 1. **Big O Notation – Upper Bound (Worst Case)**

**Definition:**

> Big O gives the **maximum time** an algorithm can take to complete for an input size **n**.

It shows the **worst-case scenario** — the slowest the algorithm could ever be.

---

### 🧮 Example:

If an algorithm takes
**T(n) = 3n² + 4n + 2**,
then the **Big O notation** is:

👉 **O(n²)**

Because when **n** becomes very large,
**n²** dominates (the smaller terms become negligible).

---

### 💬 Real-life analogy:

> “It will take **at most** 1 hour to finish.”
> That’s **Big O** — the worst-case guarantee.

---

### 📌 Common Big O complexities:

| Complexity     | Name          | Example                                   |
| -------------- | ------------- | ----------------------------------------- |
| **O(1)**       | Constant time | Accessing an array element                |
| **O(log n)**   | Logarithmic   | Binary Search                             |
| **O(n)**       | Linear        | Linear Search                             |
| **O(n log n)** | Log-linear    | Merge Sort, Quick Sort                    |
| **O(n²)**      | Quadratic     | Bubble Sort                               |
| **O(2ⁿ)**      | Exponential   | Recursive Fibonacci                       |
| **O(n!)**      | Factorial     | Travelling Salesman Problem (Brute Force) |

---

## 🔹 2. **Big Omega (Ω) Notation – Lower Bound (Best Case)**

**Definition:**

> Big Ω gives the **minimum time** an algorithm will take —
> the **best-case scenario**.

---

### 🧮 Example:

If **T(n) = 3n² + 4n + 2**,
then **Ω(n²)** means:

> The algorithm takes **at least proportional to n²** steps.

---

### 💬 Real-life analogy:

> “It will take **at least** 30 minutes to finish.”
> That’s **Big Omega** — the best-case limit.

---

## 🔹 3. **Theta (Θ) Notation – Tight Bound (Average Case)**

**Definition:**

> Big Θ gives both the **upper and lower bound** of an algorithm —
> meaning it grows **exactly at that rate**.

If the time complexity is between two functions that both grow like **n²**,
then we say it’s **Θ(n²)**.

---

### 🧮 Example:

If **T(n) = 3n² + 4n + 2**,
then **Θ(n²)** because both upper and lower bounds are proportional to **n²**.

---

### 💬 Real-life analogy:

> “It will take **around 45 minutes**, no matter what.”
> That’s **Theta** — the typical or average growth rate.

---

## ⚖️ **Comparison Summary Table:**

| Notation    | Meaning     | Describes              | Example Statement                         |
| ----------- | ----------- | ---------------------- | ----------------------------------------- |
| **O(f(n))** | Upper Bound | **Worst case**         | Algorithm takes *at most* f(n) time       |
| **Ω(f(n))** | Lower Bound | **Best case**          | Algorithm takes *at least* f(n) time      |
| **Θ(f(n))** | Tight Bound | **Average/Exact case** | Algorithm takes *approximately* f(n) time |

---

### 🧮 **Example Summary: Linear Search**

Searching for an element in an array of size **n**:

| Case             | Description                               | Notation |
| ---------------- | ----------------------------------------- | -------- |
| **Best case**    | Element is first → 1 comparison           | **Ω(1)** |
| **Worst case**   | Element not found or last → n comparisons | **O(n)** |
| **Average case** | Element somewhere in middle               | **Θ(n)** |

---

## 🧩 **In Short:**

| Notation    | Meaning     | Think as             |
| ----------- | ----------- | -------------------- |
| **O(f(n))** | Upper bound | Worst case           |
| **Ω(f(n))** | Lower bound | Best case            |
| **Θ(f(n))** | Tight bound | Average / Exact case |
