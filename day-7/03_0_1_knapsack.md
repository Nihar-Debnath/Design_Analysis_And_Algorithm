# 🎒 0/1 Knapsack Problem (Quick Recap)

* You have **items**, each with:

  * **Weight** \(w_i\)
  * **Profit/Value** \(p_i\)
* Knapsack capacity = **W**
* **0/1 constraint**:
  👉 You either **take the whole item (1)** or **don’t take it (0)**
  ❌ You **cannot break** an item.

**Goal**: Maximize total profit without exceeding capacity.

---

# 🤔 What Does Greedy Try to Do?

Greedy makes a **locally best choice** at each step, such as:

1. Pick item with **maximum profit**
2. Pick item with **minimum weight**
3. Pick item with **maximum profit/weight ratio**

⚠️ These strategies **work for Fractional Knapsack**,
❌ but **fail for 0/1 Knapsack**.

---

# ❌ Why Greedy Fails in 0/1 Knapsack

Because:

* Greedy **never reconsiders decisions**
* Local optimum ≠ Global optimum
* 0/1 restriction blocks partial correction

---

# 📌 Classic Example Showing Greedy Failure

### Knapsack Capacity:

\[
W = 50
\]

### Items:

| Item | Weight (w) | Profit (p) | p/w |
| ---- | ---------- | ---------- | --- |
| A    | 10         | 60         | 6   |
| B    | 20         | 100        | 5   |
| C    | 30         | 120        | 4   |

---

## 🟡 Greedy Choice (Based on Highest p/w)

### Step 1:

Pick **A** (p/w = 6)

Remaining capacity = (50 - 10 = 40)
Total profit = **60**

---

### Step 2:

Pick **B** (p/w = 5)

Remaining capacity = (40 - 20 = 20)
Total profit = **160**

---

### Step 3:

Item **C** weighs 30 → ❌ cannot fit

---

### ❌ Greedy Result:

\[
\text{Profit} = 160
\]

---

## 🟢 Optimal Solution (Using Dynamic Programming)

Pick:

* **B (20, 100)**
* **C (30, 120)**

Total weight:
\[
20 + 30 = 50
\]

Total profit:
\[
100 + 120 = \boxed{220}
\]

---

# 🚫 Why Greedy Could Not Find This?

* Greedy **committed early** to item A
* That decision **blocked** item C
* Greedy **never explores combinations**
* No backtracking

---

# ⚖️ Greedy vs Dynamic Programming (0/1 Knapsack)

| Feature                | Greedy | Dynamic Programming |
| ---------------------- | ------ | ------------------- |
| Decision               | Local  | Global              |
| Backtracking           | ❌ No   | ✅ Yes               |
| Explores combinations  | ❌ No   | ✅ Yes               |
| Guaranteed optimal     | ❌ No   | ✅ Yes               |
| Works for 0/1 Knapsack | ❌      | ✅                   |

---

# 🧠 One-Line Exam Answer (VERY IMPORTANT)

> Greedy fails in the 0/1 Knapsack problem because making locally optimal choices may prevent forming the globally optimal combination due to the indivisible (0/1) nature of items.

---

# 🔑 Memory Trick (Never Forget)

* **Fractional Knapsack** → Greedy ✅
* **0/1 Knapsack** → Greedy ❌ → DP ✅

---

# 📌 Why Dynamic Programming Works Here

DP:

* Tries **all combinations**
* Stores subproblem results
* Ensures **global optimum**

Time Complexity:
\[
O(nW)
\]



---
---
---
---
---
---
---




# 🎒 0/1 Knapsack Problem — Dynamic Programming Explanation (DAA)

---

## 1️⃣ What is the 0/1 Knapsack Problem?

In the **0/1 Knapsack problem**:

* Each item has:

  * **Weight** ( w_i )
  * **Profit** ( p_i )
* Knapsack has a fixed **capacity ( W )**
* Each item can be:

  * **Taken completely (1)**
  * **Not taken at all (0)**

❌ **Items cannot be divided**

### Objective:

\[
\text{Maximize total profit} \quad \text{subject to total weight} \le W
\]

---

## 2️⃣ Difference: Fractional vs 0/1 Knapsack

| Feature          | Fractional Knapsack | 0/1 Knapsack        |
| ---------------- | ------------------- | ------------------- |
| Item division    | Allowed             | ❌ Not allowed       |
| Greedy works?    | ✅ Yes               | ❌ No                |
| Optimal strategy | Profit/Weight ratio | Dynamic Programming |

📌 **This distinction is crucial**.

---

## 3️⃣ Why Greedy Works for Fractional but FAILS for 0/1 Knapsack

### Greedy Strategy:

> Select items based on **highest profit/weight ratio first**

* Works only when **partial selection is allowed**
* In 0/1 knapsack, once an item is selected, it **blocks capacity permanently**
* Greedy does **not reconsider decisions**

---

## 4️⃣ Example Showing Greedy Failure (As in Video)

### Given:

Knapsack Capacity = **W**

Items:

| Item | Weight | Profit | Profit/Weight |
| ---- | ------ | ------ | ------------- |
| 1    | 10     | 40     | 4             |
| 2    | 20     | 60     | 3             |
| 3    | 30     | 85     | 2.83          |

---

### 🔴 Greedy Selection (Highest p/w first)

1. Select item 1 → profit = 40
2. Select item 2 → profit = 40 + 60 = **80**
3. Item 3 cannot fit

#### ❌ Greedy Result:

\[
\text{Profit} = 80
\]

---

### 🟢 Optimal Solution (Non-Greedy)

Select:

* Item 3 only

\[
\text{Profit} = 85
\]

✔ **85 > 80**

---

## 5️⃣ Why Greedy Failed Here?

* Greedy focused on **local profit/weight**
* Early selections **blocked better combinations**
* No backtracking
* No exploration of alternatives

📌 **Local optimum ≠ Global optimum**

---

## 6️⃣ How to Solve 0/1 Knapsack Correctly?

### 🔹 Brute Force Method

Each item has **2 choices**:

* Include (1)
* Exclude (0)

For **n items**:
\[
\text{Total combinations} = 2^n
\]

---

### Example: 3 Items

\[
2^3 = 8 \text{ possible combinations}
\]

| Combination | Items Taken | Total Profit |
| ----------- | ----------- | ------------ |
| 000         | None        | 0            |
| 001         | 3           | 85           |
| 010         | 2           | 60           |
| 011         | 2,3         | ❌ overweight |
| 100         | 1           | 40           |
| 101         | 1,3         | ❌ overweight |
| 110         | 1,2         | 80           |
| 111         | 1,2,3       | ❌ overweight |

✅ **Maximum valid profit = 85**

---

### ❌ Problem with Brute Force

* Time complexity:
  \[
  O(2^n)
  \]
* Becomes impossible for large ( n )

---

## 7️⃣ Dynamic Programming Solution (Efficient & Optimal)

Dynamic Programming:

* Uses **optimal substructure**
* Uses **overlapping subproblems**
* Avoids recomputation

### DP Time Complexity:

\[
O(nW)
\]

✔ Guarantees **optimal solution**
✔ Much faster than brute force
✔ Correct for 0/1 Knapsack

---

## 8️⃣ Greedy vs Dynamic Programming (0/1 Knapsack)

| Feature                   | Greedy | Dynamic Programming |
| ------------------------- | ------ | ------------------- |
| Decision type             | Local  | Global              |
| Explores combinations     | ❌ No   | ✅ Yes               |
| Backtracking              | ❌ No   | ✅ Yes               |
| Always optimal            | ❌ No   | ✅ Yes               |
| Suitable for 0/1 Knapsack | ❌      | ✅                   |

---

## 9️⃣ One-Line Exam Answer (IMPORTANT)

> Greedy approach fails for the 0/1 Knapsack problem because locally optimal choices may prevent achieving the globally optimal solution due to the indivisible nature of items.

---

## 🔑 Memory Trick

* **Fractional Knapsack** → Greedy ✅
* **0/1 Knapsack** → Greedy ❌ → DP ✅

---

## 🔚 Final Conclusion

The greedy method cannot guarantee optimality in the 0/1 Knapsack problem because it does not evaluate all possible combinations. Dynamic Programming overcomes this limitation by systematically exploring and storing subproblem results to ensure the best possible solution.
