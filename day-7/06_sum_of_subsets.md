## 1️⃣ What is **Subset Sum Problem** (in very simple words)

You are given:

* Some **numbers**
* A **target sum**

### Question:

> Can I pick **some numbers** (or none)
> so that their **sum equals the target**?

That’s it. Nothing more.

---

## 2️⃣ Small example (understand this first)

Numbers:

```
[3, 4, 5]
```

Target:

```
9
```

### Possible choices:

* 3 + 4 = 7 ❌
* 3 + 5 = 8 ❌
* 4 + 5 = 9 ✅

👉 Answer: **YES**

---

## 3️⃣ Why brute force is bad

Brute force thinking:

> “For every number, I’ll either take it or not take it.”

For `n` numbers:

* Total choices = `2ⁿ`

Example:

```
[3, 4, 5]
Choices:
[]  
[3]  
[4]  
[5]  
[3,4]  
[3,5]  
[4,5]  
[3,4,5]
```

✔️ Correct
❌ Very slow when numbers increase

---

## 4️⃣ Why Greedy does NOT work

Greedy thinking:

> “Pick the biggest number first.”

Example:

```
Numbers: [3, 4, 6]
Target: 7
```

Greedy picks:

```
6 → remaining = 1 ❌
```

But correct answer:

```
3 + 4 = 7 ✅
```

So greedy fails ❌

---

## 5️⃣ Now the KEY IDEA: How DP thinks 🧠

DP asks a **simple YES/NO question** again and again:

> “Using the **first k numbers**,
> can I make **sum = S**?”

That’s all DP is doing.

---

## 6️⃣ DP table (think like a checklist ✔️❌)

Let’s take:

Numbers:

```
[3, 4, 5]
```

Target:

```
9
```

We make a table:

Rows → numbers considered
Columns → possible sums

---

### Step 1: Start with sum = 0

Sum = 0 is **always possible**
(just take nothing)

```
✔ at sum 0
```

---

### Step 2: Consider number = 3

What sums can we make?

* Don’t take 3 → sum 0 ✔
* Take 3 → sum 3 ✔

```
Possible sums: 0, 3
```

---

### Step 3: Consider number = 4

From previous sums:

* 0 → 4
* 3 → 7

```
Possible sums: 0, 3, 4, 7
```

---

### Step 4: Consider number = 5

From previous sums:

* 0 → 5
* 3 → 8
* 4 → 9 ✅
* 7 → 12 (ignore > target)

```
Possible sums: 0, 3, 4, 5, 7, 8, 9
```

🎉 Target `9` found → **YES**

---

## 7️⃣ Why DP is OPTIMAL here

DP:

* Tries **both choices** for every number:

  * take it
  * don’t take it
* But **remembers results**

So:

* Same sum is not recomputed again
* No repeated work

---

## 8️⃣ Why DP is faster than brute force

| Method      | Time       |
| ----------- | ---------- |
| Brute Force | 2ⁿ         |
| DP          | n × target |

DP is fast **when target is not huge**.

---

## 9️⃣ Real-life analogy 🧺

You have items with weights:

```
3kg, 4kg, 5kg
```

You want exactly:

```
9kg
```

DP keeps asking:

> “With these items, can I make 9kg?”

Greedy:

> “Pick the heaviest item first.”

Greedy fails.
DP checks all **possible weight combinations**.

---

## 🔑 One-line beginner summary (EXAM READY)

> **Subset Sum checks if a target sum can be formed from given numbers.
> DP solves it by building possible sums step by step and remembering results.**

---
---
---
---
---


# 📘 Subset Sum Problem — Formal Explanation

## 1️⃣ Problem Definition (Formal)

Given:

* A set of **n positive integers**
  [
  A = {a_1, a_2, a_3, \dots, a_n}
  ]
* A target value **S**

Determine whether there exists a **subset** of `A` whose sum is **exactly S**.

---

## 2️⃣ Why Dynamic Programming is Used

The problem has:

* **Optimal substructure**
  → Solution depends on solutions of smaller subproblems
* **Overlapping subproblems**
  → Same sums are checked multiple times

Therefore, **Dynamic Programming** is suitable.

---

## 3️⃣ DP State Definition

We define a DP table:

```
dp[i][s]
```

Meaning:

> Using the **first i elements**,
> is it possible to get **sum = s**?

Value:

* `true` → possible
* `false` → not possible

---

## 4️⃣ DP Base Conditions

### Case 1: Sum = 0

```
dp[i][0] = true   (empty subset)
```

### Case 2: No elements

```
dp[0][s] = false  (for s > 0)
```

---

## 5️⃣ DP Transition (Logic)

For the `i-th` element with value `a[i]`:

### Option 1: Do not take the element

```
dp[i-1][s]
```

### Option 2: Take the element (if s ≥ a[i])

```
dp[i-1][s - a[i]]
```

### Final rule:

```
dp[i][s] = dp[i-1][s] OR dp[i-1][s - a[i]]
```

(Only if `s ≥ a[i]`)

---

## 6️⃣ Final Answer

Check:

```
dp[n][S]
```

* `true` → subset exists
* `false` → subset does not exist

---

## 7️⃣ Time Complexity (TC)

### DP Table Size:

* Rows = `n + 1`
* Columns = `S + 1`

### Each cell takes constant time

[
\boxed{\text{Time Complexity } = O(n \times S)}
]

---

## 8️⃣ Space Complexity (SC)

### Using full table:

[
O(n \times S)
]

### Optimized (1D DP):

[
O(S)
]

---

## 9️⃣ Comparison with Other Approaches

| Method              | Time Complexity | Optimal? |
| ------------------- | --------------- | -------- |
| Brute Force         | (O(2^n))        | ✅        |
| Greedy              | (O(n \log n))   | ❌        |
| Dynamic Programming | (O(n \times S)) | ✅        |

---

## 🔑 Key Exam-Friendly Summary

> **Subset Sum Problem determines whether a subset with given sum exists.
> Dynamic Programming solves it using a boolean table of size `n × S`,
> achieving time complexity `O(n × S)` and space complexity `O(n × S)`.**
