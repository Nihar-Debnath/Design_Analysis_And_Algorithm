# 🎒 Knapsack Problem (Beginner Friendly)

## 1️⃣ What is the Knapsack Problem?

You are given:

* A **bag (knapsack)** with limited capacity ( W )
* A set of **items**
* Each item has:

  * **Weight** ( w_i )
  * **Profit / Value** ( p_i )

### 🎯 Goal

> **Maximize total profit** such that total weight **does not exceed** knapsack capacity.

---

## 2️⃣ Real-Life Intuition

Imagine:

* You have a **bag that can carry 10 kg**
* You want to pack items to **earn maximum money**
* You cannot exceed the bag limit

---

## 3️⃣ Types of Knapsack Problems (VERY IMPORTANT)

| Type                    | Can take fraction?         | Greedy works? |
| ----------------------- | -------------------------- | ------------- |
| **Fractional Knapsack** | ✅ Yes                      | ✅ Yes         |
| **0/1 Knapsack**        | ❌ No                       | ❌ No          |
| **Unbounded Knapsack**  | ❌ No (but unlimited items) | ❌ No          |

👉 **Greedy Technique works ONLY for Fractional Knapsack**

---

# 🔹 FRACTIONAL KNAPSACK (Greedy Works)

## 4️⃣ Problem Statement (Fractional Knapsack)

Given:

| Item | Profit (p) | Weight (w) |
| ---- | ---------- | ---------- |
| 1    | 60         | 10         |
| 2    | 100        | 20         |
| 3    | 120        | 30         |

Knapsack Capacity:
[
W = 50
]

You **can take fractions** of items.

---

## 5️⃣ Greedy Strategy Used

👉 **Choose items based on maximum profit per unit weight**

\[
\text{Profit Density} = \frac{p}{w}
\]

---

## 6️⃣ Calculate Profit Density

| Item | Profit | Weight | ( \frac{p}{w} ) |
| ---- | ------ | ------ | --------------- |
| 1    | 60     | 10     | 6               |
| 2    | 100    | 20     | 5               |
| 3    | 120    | 30     | 4               |

👉 Sort items in **descending order of ( \frac{p}{w} )**

Order:
\[
\text{Item 1} \rightarrow \text{Item 2} \rightarrow \text{Item 3}
\]

---

## 7️⃣ Step-by-Step Greedy Solution

### Capacity = 50

### Step 1: Take Item 1

* Weight = 10
* Profit = 60
* Remaining capacity = 40

### Step 2: Take Item 2

* Weight = 20
* Profit = 100
* Remaining capacity = 20

### Step 3: Take **fraction** of Item 3

* Needed weight = 20 out of 30
* Fraction taken:
  \[
  \frac{20}{30} = \frac{2}{3}
  \]
* Profit gained:
  \[
  120 \times \frac{2}{3} = 80
  \]

---

## 8️⃣ Final Answer

Total Profit:
[
60 + 100 + 80 = \boxed{240}
]

✅ **This is the maximum possible profit**

---

## 9️⃣ Why Greedy Works Here?

Because:

* You are always choosing the item that gives **maximum profit per kg**
* Fraction is allowed → no regret later
* Both conditions satisfied:

  * **Greedy Choice Property**
  * **Optimal Substructure**

---

# 🔹 ALGORITHM (Fractional Knapsack – Greedy)

```text
FractionalKnapsack(items, W):
1. For each item i:
      calculate profit_density = p[i] / w[i]
2. Sort items in decreasing order of profit_density
3. total_profit = 0
4. For each item i:
      if w[i] <= W:
          take full item
          W = W - w[i]
          total_profit += p[i]
      else:
          take fraction W / w[i]
          total_profit += p[i] * (W / w[i])
          break
5. return total_profit
```

---

## 10️⃣ Time Complexity

* Sorting items: ( O(n \log n) )
* Selection: ( O(n) )

### ✅ Overall:

[
O(n \log n)
]

---

# 🔴 0/1 Knapsack (Greedy FAILS)

## 11️⃣ Why Greedy Does NOT Work for 0/1 Knapsack?

### Example:

| Item | Profit | Weight |
| ---- | ------ | ------ |
| A    | 60     | 10     |
| B    | 100    | 20     |
| C    | 120    | 30     |

Capacity:
[
W = 50
]

Greedy (by profit density):

* Pick A + B → weight = 30 → profit = 160

Optimal (DP solution):

* Pick B + C → weight = 50 → profit = **220**

❌ Greedy gives **wrong answer**

Reason:

* **Fraction not allowed**
* Local best choice ruins global optimum

---

## 12️⃣ Final Summary (EXAM GOLD ⭐)

* **Knapsack Problem:** Maximize profit under weight constraint
* **Fractional Knapsack:**

  * Fraction allowed
  * Solved using **Greedy**
* **0/1 Knapsack:**

  * No fraction
  * Solved using **Dynamic Programming**
* **Greedy Strategy:** Choose item with max ( \frac{p}{w} )

---

## 📝 One-Line Exam Definition

> **Fractional Knapsack is a greedy problem where items are selected based on maximum profit-to-weight ratio, allowing fractional selection to achieve maximum profit.**

---
---
---
---


## ❓ Your Question (Rephrased Clearly)

> *“What if I pick the item of weight 10 multiple times (like 5 times)?
> Won’t that give me the maximum profit = 300?”*

You are referring to **this item**:

| Item   | Profit | Weight |
| ------ | ------ | ------ |
| Item 1 | 60     | 10     |

Capacity:
[
W = 50
]

If allowed:

* Pick it **5 times**
* Profit:
  [
  5 \times 60 = 300
  ]

---

## 🔴 Key Point You Are Missing (IMPORTANT)

### 👉 **In the given Knapsack problem, EACH ITEM IS AVAILABLE ONLY ONCE**

This is **not optional** — it is part of the **problem definition**.

---

## 🧠 Knapsack Variants (THIS SOLVES YOUR CONFUSION)

| Problem Type            | Can repeat same item? | Fraction allowed? |
| ----------------------- | --------------------- | ----------------- |
| **Fractional Knapsack** | ❌ No                  | ✅ Yes             |
| **0/1 Knapsack**        | ❌ No                  | ❌ No              |
| **Unbounded Knapsack**  | ✅ Yes                 | ❌ No              |

---

## 1️⃣ Why You CANNOT Pick Weight-10 Item 5 Times

In **Fractional Knapsack**:

* You can take **fraction of an item**
* But **each item exists only once**

So for Item 1 (10 kg):

* You can take:

  * 100% of it
  * OR 50% of it
* ❌ But **not 5 copies**

📌 Fraction ≠ Multiple Copies

---

## 2️⃣ Why Fractional Knapsack Still Stops at 240

You have only:

* ONE item of weight 10 (profit 60)
* ONE item of weight 20 (profit 100)
* ONE item of weight 30 (profit 120)

After using all possible items:

* You are **forced** to take fraction of the next best item

Hence:
[
\text{Max Profit} = 240
]

---

## 3️⃣ When Your Idea (300 Profit) WOULD Be Correct

### 🔹 Unbounded Knapsack

If problem said:

> “You can take **unlimited copies** of each item”

Then yes ✅
Your logic is **100% correct**.

### Example (Unbounded Knapsack):

* Item: (60 profit, 10 weight)
* Capacity: 50

Then:
[
\frac{50}{10} = 5 \text{ items}
]
[
5 \times 60 = \boxed{300}
]

---

## 4️⃣ Why Unbounded Knapsack Is NOT Greedy

Even though it looks greedy:

* Greedy fails in many unbounded cases
* Requires **Dynamic Programming**

So:

* ❌ Not solved using Greedy
* ✅ Solved using DP

---

## 5️⃣ Simple Analogy (Real-Life)

Think like this:

> You have **one gold bar of 10 kg**, not a gold shop.

* You can:

  * Cut the gold bar (fractional)
* You cannot:

  * Magically duplicate it

---

## 🔥 Final Mental Model (Remember This)

> **Fractional = break the item
> Unbounded = repeat the item
> 0/1 = take it or leave it**

---

## 📝 One-Line Exam Answer (VERY IMPORTANT)

> In Fractional Knapsack, each item can be taken only once, though fractions are allowed; multiple copies are not permitted.
