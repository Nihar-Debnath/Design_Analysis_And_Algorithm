# 🚗 Travelling Salesman Problem (TSP)

## 1️⃣ What is the Travelling Salesman Problem?

Imagine:

* A **salesman**
* Several **cities**
* He must:

  1. Start from a city
  2. Visit **every city exactly once**
  3. Return to the **starting city**
* **Total travel cost should be minimum**

📌 Cities = **nodes**
📌 Roads = **edges with cost**

---

## 2️⃣ Very Simple Real-World Example

A delivery person must deliver packages to **4 cities** and return home.

Cities:

```
A, B, C, D
```

Distance matrix:

| From / To | A  | B  | C  | D  |
| --------- | -- | -- | -- | -- |
| **A**     | 0  | 10 | 15 | 20 |
| **B**     | 10 | 0  | 35 | 25 |
| **C**     | 15 | 35 | 0  | 30 |
| **D**     | 20 | 25 | 30 | 0  |

---

## 3️⃣ Why Not Use Greedy?

Greedy idea:

> “Go to the nearest unvisited city.”

From A:

* Nearest is B (10)
* From B → D (25)
* From D → C (30)
* Return C → A (15)

Total cost:

```
10 + 25 + 30 + 15 = 80
```

❌ This **may not be optimal**.

Greedy:

* Makes local decisions
* Does not check all routes

---

## 4️⃣ Why Brute Force is Bad

Total ways to visit `n` cities:
\[
(n-1)!
\]

For:

* 4 cities → 6 routes
* 10 cities → 362,880 routes 😵
* 20 cities → impossible

❌ Too slow

---

## 5️⃣ Why Dynamic Programming?

TSP has:

* **Optimal substructure**
* **Overlapping subproblems**

So DP works perfectly.

---
---
---
---
---
---
---
---

## 2️⃣ Now the BIG QUESTION: How DP fixes this

DP mindset is **completely different**:

> “I won’t decide now.
> I’ll try **every possible way**, remember results, and then choose the best.”

Key idea:

* **Try all routes**
* But **don’t repeat the same work again and again**

---

## 3️⃣ Imagine this real-life story 🚗

You are traveling:

* Cities: A, B, C, D
* You start from A

At some point:

* You are in **city C**
* You have already visited **A and B**

Now think carefully 👇

### Important realization:

Does it matter **HOW** you reached C?

❌ No!

If:

* You are in C
* A and B are already visited

Then:

* The **remaining problem** is exactly the same

👉 This is the **heart of DP**

---

## 4️⃣ What DP actually “remembers”

DP remembers this:

> “When I was in city C
> and I had already visited A and B,
> the minimum cost from there was X.”

So next time:

* If you reach the **same situation**
* DP says:
  **“I already solved this. Use the answer.”**

This is why DP is efficient.

---

## 5️⃣ How DP chooses better than greedy

Instead of saying:

> “Let me go to the nearest city.”

DP says:

> “Let me try going to B…
> Let me try going to C…
> Let me try going to D…
> Now I’ll choose whichever gives the least total distance.”

So:

* Greedy → **one choice**
* DP → **all choices**

---

## 6️⃣ Very simple comparison

### Greedy:

* Picks one road
* Never looks back
* Sometimes stuck with bad future

### DP:

* Tries every road
* Remembers results
* Chooses the **best full journey**

---

## 7️⃣ Why DP guarantees optimal answer

Because:

* It never ignores a possible path
* It compares **complete journeys**
* Not just the next step

So:

> Best full journey = guaranteed best answer

---

## 8️⃣ One-line beginner intuition 🧠

> **Greedy thinks short-term.
> DP thinks full-trip.**

---
---
---
---
---



## 🗺️ Example: 4 Cities (A, B, C, D)

### Distances (imagine roads):

```
A → B = 10     A → C = 15     A → D = 20
B → C = 35     B → D = 25
C → D = 30
(return paths same)
```

Start city: **A**
Goal: visit **all cities once** and return to **A**

---

## ❌ What GREEDY does

### Step 1: From A

Nearest city = **B (10)**
Path: `A → B`

### Step 2: From B

Unvisited: C, D
Nearest = **D (25)**
Path: `A → B → D`

### Step 3: From D

Only left = C
Path: `A → B → D → C`

### Return to A

`C → A = 15`

### 🔴 Total cost (Greedy):

```
10 + 25 + 30 + 15 = 80
```

---

## ✅ What DP does (simple thinking)

DP does NOT commit early.

It says:

> “From A, I’ll try **every possible next city**
> and calculate the **full trip cost**.”

---

### Try Path 1:

```
A → B → C → D → A
10 + 35 + 30 + 20 = 95
```

### Try Path 2:

```
A → B → D → C → A
10 + 25 + 30 + 15 = 80
```

### Try Path 3:

```
A → C → B → D → A
15 + 35 + 25 + 20 = 95
```

### Try Path 4:

```
A → C → D → B → A
15 + 30 + 25 + 10 = 80
```

### Try Path 5:

```
A → D → B → C → A
20 + 25 + 35 + 15 = 95
```

### Try Path 6:

```
A → D → C → B → A
20 + 30 + 35 + 10 = 95
```

---

## 🟢 DP’s Final Decision

DP compares **all full trips**:

| Path              | Cost   |
| ----------------- | ------ |
| A → B → D → C → A | **80** |
| A → C → D → B → A | **80** |
| Others            | 95     |

👉 **Minimum = 80**

So DP gives the **correct optimal answer**.

---

## 🤔 “But isn’t DP just brute force?”

Good question!

DP is **smart brute force**:

* When DP reaches:

  ```
  Currently at C
  Already visited A and B
  ```
* It **remembers the best cost from here**
* Next time same situation appears → **reuse answer**

So:

* Brute force → repeat work ❌
* DP → remember and reuse ✅

---

## 🧠 One-line takeaway (EXAM FRIENDLY)

> **Greedy chooses the nearest city.
> DP compares all complete tours and remembers partial results.**



---
---
---
---
---



## ⏱️ Time Complexity of TSP

### 1️⃣ Greedy Approach

Greedy:

* From each city, choose nearest unvisited city

For **n cities**:

* From each city → check up to `n` cities
* Do this `n` times

**Time Complexity:**

```
O(n²)
```

✔️ Fast
❌ Not always correct

---

### 2️⃣ Brute Force (for understanding)

Brute force:

* Try **every possible order of cities**

Number of ways:

```
n!  (factorial)
```

**Time Complexity:**

```
O(n!)
```

❌ Extremely slow
✔️ Correct

---

### 3️⃣ Dynamic Programming (TSP using DP)

DP:

* Tries all possibilities
* But **does not repeat the same situation**

How many situations?

* Different sets of visited cities
* Different current cities

Total situations:

```
≈ n × 2ⁿ
```

For each situation:

* Try up to `n` next cities

**Time Complexity:**

```
O(n² × 2ⁿ)
```

✔️ Correct
✔️ Much faster than n!
❌ Still expensive for large n

---

## 🔍 Very simple comparison table

| Method       | Time Complexity | Correct? |
| ------------ | --------------- | -------- |
| Greedy       | O(n²)           | ❌        |
| Brute Force  | O(n!)           | ✅        |
| DP (Bitmask) | O(n²·2ⁿ)        | ✅        |

---

## 🧠 Beginner one-line memory trick

> **Greedy is fast but wrong.
> DP is slow but always right.
> Brute force is impossibly slow.**

---

### 📌 Exam Tip (IMPORTANT)

If asked:

> *“Why DP is preferred over greedy in TSP?”*

Write:

* Greedy is faster `O(n²)` but not optimal
* DP gives optimal solution in `O(n²·2ⁿ)`
