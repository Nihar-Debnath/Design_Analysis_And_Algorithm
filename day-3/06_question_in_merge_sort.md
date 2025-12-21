## The Question (decoded slowly)

> **“Average number of comparisons performed by merge sort algorithm, in merging 2 sorted lists of length 2”**

This sentence has **three important parts** 👇

---

## 1️⃣ “Merging 2 sorted lists”

This means **ONLY the MERGE step**, **not the full merge sort**.

So we are **NOT** talking about:

* recursion
* splitting
* overall time complexity \( O(n \log n) \)

👉 We are ONLY analyzing this function:

```text
merge(A, B)
```

---

## 2️⃣ “Lists of length 2”

Each list has **exactly 2 elements**:

* List A → 2 elements (already sorted)
* List B → 2 elements (already sorted)

Example (values don’t matter yet):

```text
A = [a1, a2]  where a1 < a2
B = [b1, b2]  where b1 < b2
```

---

## 3️⃣ “Average number of comparisons” ⚠️ (MOST IMPORTANT)

This is where students usually misunderstand.

### ❌ What it does NOT mean

* NOT worst case
* NOT best case
* NOT “always 3 comparisons”

### ✅ What it DOES mean

* Consider **ALL possible valid inputs**
* Assume **each case is equally likely**
* Compute the **expected (average)** number of comparisons

👉 This is **probability + algorithm analysis**

---

## What varies and what does NOT?

### ❌ Internal order does NOT change

Because lists are already sorted:

```text
a1 < a2
b1 < b2
```

This NEVER changes.

### ✅ Relative order BETWEEN lists changes

Examples:

* All A elements smaller than B
* All B elements smaller than A
* Interleaving like A, B, A, B
* Interleaving like B, A, B, A

These different interleavings cause **different number of comparisons**.

---

## Why “average” is needed here?

Because **merge algorithm is data-dependent**.

Sometimes:

* It finishes early → fewer comparisons
* Sometimes:
* It runs longer → more comparisons

So GATE asks:

> “On average, how many comparisons will it do?”

---

## Mental picture (important for intuition)

You are merging **2 sorted cards** from hand A and **2 sorted cards** from hand B.

You:

* Compare top cards
* Pick the smaller one
* Repeat until one hand becomes empty

Number of comparisons depends on **how early one hand empties**.

---

## One-line understanding (exam-ready)

> The question asks for the **expected number of element-to-element comparisons** performed by the **merge procedure**, assuming **all valid interleavings of two sorted lists of size 2 are equally likely**.

---
---
---
---


## Problem

> **Average number of comparisons performed by merge sort while merging two sorted lists of length 2 each**

Each list is already sorted.

---

## Key Insight (the “trick”)

* You **do NOT assume worst case**
* You must compute the **expected (average) number of comparisons**
* All **relative interleavings** of the two sorted lists are **equally likely**

---

## Step 1: Setup

Let the two sorted lists be:

* List A: \( a_1 < a_2 \)
* List B: \( b_1 < b_2 \)

Only the **relative order between A and B elements varies**, but internal order is fixed.

Number of valid interleavings:

\[
\binom{4}{2} = 6
\]

So, **6 equally likely cases**.

---

## Step 2: Enumerate all cases and count comparisons

| Case | Final Order         | Comparisons |
| ---- | ------------------- | ----------- |
| 1    | \( a_1,a_2,b_1,b_2 \) | 2           |
| 2    | \( a_1,b_1,a_2,b_2 \) | 3           |
| 3    | \( a_1,b_1,b_2,a_2 \) | 3           |
| 4    | \( b_1,a_1,a_2,b_2 \) | 3           |
| 5    | \( b_1,a_1,b_2,a_2 \) | 3           |
| 6    | \( b_1,b_2,a_1,a_2 \) | 2           |

---

## Step 3: Compute the average

\[
\text{Average} = \frac{2 + 3 + 3 + 3 + 3 + 2}{6}
= \frac{16}{6}
= \boxed{\frac{8}{3}}
\]

---

## ✅ Final Answer (GATE correct form)

\[
\boxed{\dfrac{8}{3}}
\]

---

## Why GATE loves this question

* Many students answer **3 (worst case)** ❌
* But GATE asks **average case** ✔
* Requires **probability + algorithm insight**


---
---
---
---


Great 👍
Let’s do this **only with concrete numbers**, no theory, no symbols — so the question becomes *obvious*.

---

## Setup: two sorted lists of length 2

Take fixed sorted lists:

```text
A = [1, 3]
B = [2, 4]
```

But GATE says **average**, so the *relative values can change* as long as:

* A stays sorted
* B stays sorted

So we must consider **all possible valid value arrangements**.

---

## All possible valid merge scenarios (with numbers)

### Case 1: A completely smaller than B

```text
A = [1, 2]
B = [3, 4]
```

Merge steps:

1. compare 1 and 3 → pick 1
2. compare 2 and 3 → pick 2
   (A is empty → stop comparing)

👉 Comparisons = **2**

---

### Case 2: B completely smaller than A

```text
A = [3, 4]
B = [1, 2]
```

Merge steps:

1. compare 3 and 1 → pick 1
2. compare 3 and 2 → pick 2
   (B is empty → stop comparing)

👉 Comparisons = **2**

---

### Case 3: Interleaving (A, B, A, B)

```text
A = [1, 3]
B = [2, 4]
```

Merge steps:

1. compare 1 and 2 → pick 1
2. compare 3 and 2 → pick 2
3. compare 3 and 4 → pick 3
   (A empty → stop)

👉 Comparisons = **3**

---

### Case 4: Interleaving (A, B, B, A)

```text
A = [1, 4]
B = [2, 3]
```

Merge steps:

1. compare 1 and 2 → pick 1
2. compare 4 and 2 → pick 2
3. compare 4 and 3 → pick 3
   (B empty → stop)

👉 Comparisons = **3**

---

### Case 5: Interleaving (B, A, A, B)

```text
A = [2, 3]
B = [1, 4]
```

Merge steps:

1. compare 2 and 1 → pick 1
2. compare 2 and 4 → pick 2
3. compare 3 and 4 → pick 3
   (A empty → stop)

👉 Comparisons = **3**

---

### Case 6: Interleaving (B, A, B, A)

```text
A = [2, 4]
B = [1, 3]
```

Merge steps:

1. compare 2 and 1 → pick 1
2. compare 2 and 3 → pick 2
3. compare 4 and 3 → pick 3
   (B empty → stop)

👉 Comparisons = **3**

---

## Summary Table

| Case | Comparisons |
| ---- | ----------- |
| 1    | 2           |
| 2    | 2           |
| 3    | 3           |
| 4    | 3           |
| 5    | 3           |
| 6    | 3           |

---

## Average number of comparisons

\[
\text{Average} = \frac{2 + 2 + 3 + 3 + 3 + 3}{6}
= \frac{16}{6}
= \boxed{\frac{8}{3}}
\]

---

## Final GATE Answer

\[
\boxed{\dfrac{8}{3}}
\]

---

### Why this example works perfectly for GATE

* Uses **actual numbers**
* Shows **early termination**
* Makes it clear why it’s **not always 3**