## 🧠 **What are “Properties of Asymptotic Notations”?**

> The **properties** of asymptotic notation** describe how we can **combine, simplify, or compare** functions representing time complexities.

They make it easier to:

* simplify complex expressions,
* compare algorithms,
* and reason mathematically about growth rates.

---

## ⚙️ **Main Properties of Asymptotic Notations**

Here are the **key properties** you should know 👇

| No. | Property Name                  | Description                                                                                          | Example                                                    |
| --- | ------------------------------ | ---------------------------------------------------------------------------------------------------- | ---------------------------------------------------------- |
| 1   | **Transitivity**               | If one function grows faster/slower than another, this relationship passes through a third function. | If f(n) = O(g(n)) and g(n) = O(h(n)) → then f(n) = O(h(n)) |
| 2   | **Reflexivity**                | A function is asymptotically equal to itself.                                                        | f(n) = O(f(n)), f(n) = Ω(f(n)), f(n) = Θ(f(n))             |
| 3   | **Symmetry (for Θ)**           | If f(n) = Θ(g(n)), then g(n) = Θ(f(n)).                                                              | If n² = Θ(3n²), then 3n² = Θ(n²)                           |
| 4   | **Transpose Symmetry**         | If f(n) = O(g(n)), then g(n) = Ω(f(n)).                                                              | If n = O(n²), then n² = Ω(n)                               |
| 5   | **Addition Rule**              | When combining functions, the faster-growing term dominates.                                         | f(n) = O(n² + n) → O(n²)                                   |
| 6   | **Multiplication by Constant** | Multiplying by a constant doesn’t change asymptotic behavior.                                        | 5n² = O(n²)                                                |
| 7   | **If-then rule**               | If f(n) = O(g(n)) and g(n) = O(f(n)), then f(n) = Θ(g(n)).                                           | If 3n² = O(5n²) and 5n² = O(3n²) → Θ(n²)                   |
| 8   | **Sum Rule**                   | When you add two complexities, the higher order dominates.                                           | O(n² + n) = O(n²)                                          |

---

Let’s understand each one **clearly** with examples 👇

---

## 🔹 1. **Transitivity Property**

**Rule:**
If

> f(n) = O(g(n))
> and g(n) = O(h(n))
> then
> f(n) = O(h(n))

✅ **Example:**

```
Let f(n) = n
Let g(n) = n²
Let h(n) = n³
```

* f(n) = O(g(n)) ✅ (n ≤ n²)
* g(n) = O(h(n)) ✅ (n² ≤ n³)
  ⇒ Therefore, f(n) = O(h(n)) ✅ (n ≤ n³)

---

## 🔹 2. **Reflexivity Property**

**Rule:**
Every function is asymptotically bounded by itself.

That is:

* f(n) = O(f(n))
* f(n) = Ω(f(n))
* f(n) = Θ(f(n))

✅ **Example:**
If f(n) = n²
Then n² = O(n²), Ω(n²), Θ(n²)

---

## 🔹 3. **Symmetry Property (for Θ only)**

**Rule:**
If f(n) = Θ(g(n)), then g(n) = Θ(f(n))

✅ **Example:**
If 2n² = Θ(5n²)
then 5n² = Θ(2n²)
Because both grow at the same rate (only constants differ).

---

## 🔹 4. **Transpose Symmetry Property**

**Rule:**
If f(n) = O(g(n)), then g(n) = Ω(f(n))

✅ **Example:**
If f(n) = n and g(n) = n²
→ f(n) = O(g(n)) (because n ≤ n²)
So by transpose, g(n) = Ω(f(n)) ✅

---

## 🔹 5. **Addition Rule**

**Rule:**
When adding two functions, the **dominant term** (the one that grows faster) determines the overall complexity.

✅ **Example:**
f(n) = n² + n
→ f(n) = O(n²) (since n² grows faster than n)

Another example:
f(n) = n³ + 100n² + 50
→ O(n³)

---

## 🔹 6. **Multiplication by Constant**

**Rule:**
If f(n) = O(g(n)), then for any constant k > 0,
k·f(n) = O(g(n))

✅ **Example:**
If f(n) = n and g(n) = n²
→ f(n) = O(g(n))
Then 5f(n) = 5n = O(n²) ✅

Constants don’t matter in asymptotic growth.

---

## 🔹 7. **If-Then (Equivalence) Property**

**Rule:**
If f(n) = O(g(n)) and g(n) = O(f(n)),
then f(n) = Θ(g(n))

✅ **Example:**
f(n) = 3n²
g(n) = 5n²

f(n) = O(g(n)) and g(n) = O(f(n))
⟹ f(n) = Θ(g(n)) ✅
Both grow at the same rate.

---

## 🔹 8. **Sum Rule**

**Rule:**
If f₁(n) = O(h(n)) and f₂(n) = O(h(n)),
then (f₁(n) + f₂(n)) = O(h(n))

✅ **Example:**
If f₁(n) = 2n, f₂(n) = 3n
Then (f₁ + f₂) = 5n = O(n)

---

## 📊 **Summary Table**

| Property                       | Rule                             | Example                           |
| ------------------------------ | -------------------------------- | --------------------------------- |
| **Transitivity**               | f = O(g), g = O(h) ⇒ f = O(h)    | n = O(n²), n² = O(n³) ⇒ n = O(n³) |
| **Reflexivity**                | f = O(f), Ω(f), Θ(f)             | n² = O(n²)                        |
| **Symmetry (Θ)**               | f = Θ(g) ⇒ g = Θ(f)              | n² = Θ(3n²)                       |
| **Transpose Symmetry**         | f = O(g) ⇒ g = Ω(f)              | n = O(n²) ⇒ n² = Ω(n)             |
| **Addition Rule**              | Higher order dominates           | O(n² + n) = O(n²)                 |
| **Multiplication by Constant** | k·f(n) = O(f(n))                 | 5n² = O(n²)                       |
| **If-Then Rule**               | f = O(g) and g = O(f) ⇒ f = Θ(g) | 3n² & 5n² ⇒ Θ(n²)                 |
| **Sum Rule**                   | (f₁ + f₂) = O(h(n))              | 2n + 3n = O(n)                    |

---

## 🧩 **In Short:**

These properties help you:

* Simplify time complexities
* Compare algorithms easily
* Prove mathematical relationships between functions

---
---
---
---
























---

## 🧩 **What’s in the Table**

The table lists:

1. **Types of notations** (Big O, Big Omega, Theta, Small o, Small ω)
2. Their **mathematical meaning / relation**
3. And three **properties** checked for each:

   * Reflexive
   * Symmetric
   * Transitive

---

## ⚙️ **Column 1: The Notations and Their Meanings**

Let’s go one by one:

| Notation            | Mathematical Meaning            | English Meaning                                       |
| ------------------- | ------------------------------- | ----------------------------------------------------- |
| **Big O (O)**       | f(n) ≤ c·g(n) for large n       | f(n) grows **no faster** than g(n) (upper bound)      |
| **Big Omega (Ω)**   | f(n) ≥ c·g(n)                   | f(n) grows **at least as fast** as g(n) (lower bound) |
| **Theta (Θ)**       | c₁·g(n) ≤ f(n) ≤ c₂·g(n)        | f(n) and g(n) grow **at the same rate** (tight bound) |
| **Small o (o)**     | f(n) < c·g(n) for **all** c > 0 | f(n) grows **strictly slower** than g(n)              |
| **Small omega (ω)** | f(n) > c·g(n) for **all** c > 0 | f(n) grows **strictly faster** than g(n)              |

---

## ⚙️ **Columns 2–4: Properties**

Now, the next columns are testing whether each notation satisfies these properties:

| Property       | Meaning                                                   |
| -------------- | --------------------------------------------------------- |
| **Reflexive**  | f(n) related to itself (f(n) = O(f(n)))                   |
| **Symmetric**  | If f(n) = O(g(n)) then g(n) = O(f(n))                     |
| **Transitive** | If f(n) = O(g(n)) and g(n) = O(h(n)), then f(n) = O(h(n)) |

---

## 📊 **Interpretation of the Table**

| Notation            | Reflexive | Symmetric | Transitive | Explanation                                                                            |
| ------------------- | --------- | --------- | ---------- | -------------------------------------------------------------------------------------- |
| **Big O (O)**       | ✅         | ❌         | ✅          | A function is O of itself; not symmetric because if f = O(g), it doesn’t mean g = O(f) |
| **Big Omega (Ω)**   | ✅         | ❌         | ✅          | Similar reasoning; lower bound, not symmetric                                          |
| **Theta (Θ)**       | ✅         | ✅         | ✅          | Because Θ is a **tight bound**, it’s **reflexive**, **symmetric**, and **transitive**  |
| **Small o (o)**     | ❌         | ❌         | ✅          | Not reflexive because f(n) can’t be strictly less than itself; but transitive holds    |
| **Small omega (ω)** | ❌         | ❌         | ✅          | Not reflexive because f(n) can’t be strictly greater than itself; but transitive holds |

---

## 🧮 **The Examples Below the Table**

The handwritten examples below are just **visual confirmations**:

* He used **n², n³, n⁴** etc. to show relationships like
  ( n^2 = O(n^3) ), ( n^3 = O(n^4) ) ⇒ ( n^2 = O(n^4) )
  ✅ proving **transitivity**.

* And also comparisons like:

  * ( n^2 < n^3 ) → f(n) = O(g(n))
  * ( n^3 > n^2 ) → f(n) = Ω(g(n))
  * ( n^2 = Θ(n^2) )

These are concrete **numerical examples** to demonstrate the same rules written in the table.

---

## 🧠 **In Summary:**

| Notation | Reflexive | Symmetric | Transitive | Meaning                          |
| -------- | --------- | --------- | ---------- | -------------------------------- |
| **O**    | ✅         | ❌         | ✅          | Upper bound (worst case)         |
| **Ω**    | ✅         | ❌         | ✅          | Lower bound (best case)          |
| **Θ**    | ✅         | ✅         | ✅          | Tight bound (average/exact case) |
| **o**    | ❌         | ❌         | ✅          | Strictly smaller growth          |
| **ω**    | ❌         | ❌         | ✅          | Strictly greater growth          |
