## What is Horner’s Method?

**Horner’s method** is an **efficient technique to evaluate a polynomial at a given value of `x`** using **minimum multiplications and additions**.

👉 It **rewrites the polynomial** in a nested form to reduce computation.

---

## Problem statement (what we want to do)

Suppose we have a polynomial:

\[
P(x) = a_n x^n + a_{n-1} x^{n-1} + \dots + a_1 x + a_0
\]

And we want to **find the value of `P(x)` for a given `x`**.

---

## Why do we need Horner’s Method?

### ❌ Normal evaluation is inefficient

For example:

\[
P(x) = 2x^3 + 3x^2 + 4x + 5
\]

To compute this normally, you do:

* (x^3), (x^2)
* multiple multiplications
* repeated power calculations

This takes **many operations**.

---

### ✅ Horner’s Method reduces operations

* No powers like (x^3, x^2)
* Only **multiplication + addition**
* Faster and cleaner

---

## Core idea of Horner’s Method

Rewrite the polynomial like this:

\[
P(x) = (((a_n x + a_{n-1})x + a_{n-2})x + \dots + a_0)
\]

This nested form allows evaluation **from left to right**.

---

## Step-by-step example

### Given polynomial

\[
P(x) = 2x^3 + 3x^2 + 4x + 5
\]

Evaluate it at:

\[
x = 2
\]

---

### Step 1: Rewrite using Horner’s form

\[
P(x) = ((2x + 3)x + 4)x + 5
\]

---

### Step 2: Evaluate step by step

Start from the left:

1. (2)
2. (2 × 2 + 3 = 7)
3. (7 × 2 + 4 = 18)
4. (18 × 2 + 5 = 41)

---

### ✅ Final Answer

\[
P(2) = 41
\]

---

## Algorithm (simple steps)

1. Start with the **leading coefficient**
2. Multiply it by `x`
3. Add the next coefficient
4. Repeat until the last coefficient

---

## Pseudocode (very simple)

```
result = a[n]
for i = n-1 down to 0:
    result = result * x + a[i]
return result
```

---

## Operation count comparison

### Normal method

* Multiplications: ~ (n(n+1)/2)
* Expensive power calculations

### Horner’s Method

* Multiplications: **n**
* Additions: **n**
* **Optimal and fastest**

---

## Time Complexity

\[
\boxed{O(n)}
\]

(where `n` is the degree of the polynomial)

---

## Why Horner’s Method is important (exam point)

* Used in **compiler design**
* Used in **numerical methods**
* Used in **algorithm optimization**
* Reduces computation time significantly

---

## One-line exam definition ⭐

> **Horner’s method** is an efficient algorithm for evaluating a polynomial at a given point by rewriting it in nested form, requiring only linear time and minimal arithmetic operations.

---
---
---
---
---
---
---
---


## Just tell me this first 👇

You know **how to calculate this**, right?

\[
2x^3 + 3x^2 + 4x + 5 \quad \text{when } x = 2
\]

If yes → good.
If no → still fine, I’ll show.

---

## Normal way (the “slow” way)

Put (x = 2)

\[
2(2^3) + 3(2^2) + 4(2) + 5
\]

\[
= 2(8) + 3(4) + 8 + 5
\]

\[
= 16 + 12 + 8 + 5 = 41
\]

✔ Answer = **41**

But this needed:

* power calculations (`2^3`, `2^2`)
* many steps

---

## Horner’s Method = SAME ANSWER, LESS BRAIN PAIN 🧠

### Rule (ONLY ONE RULE)

👉 **Multiply, then add. Repeat.**

That’s it.

---

## Step-by-step like a machine 🤖

Polynomial:
\[
2x^3 + 3x^2 + 4x + 5
\]

Value:
\[
x = 2
\]

### Step 1: Write coefficients only

```
2   3   4   5
```

### Step 2: Start with first number

```
result = 2
```

### Step 3: Multiply by x, then add next number

* `result = 2 × 2 + 3 = 7`
* `result = 7 × 2 + 4 = 18`
* `result = 18 × 2 + 5 = 41`

---

## DONE. 🎉

\[
P(2) = 41
\]

No powers
No (x^3, x^2)
Only **multiply + add**

---

## Why this works (one line only)

Instead of calculating:
\[
2x^3 + 3x^2 + 4x + 5
\]

We calculate:
\[
(((2)x + 3)x + 4)x + 5
\]

Same math, **less work**.

---

## One-sentence meaning (memorize this)

> **Horner’s method** evaluates a polynomial by repeatedly multiplying by `x` and adding the next coefficient.

---

## Think of it like this 🧠

You are:

* carrying one value (`result`)
* every step:

  * **multiply by x**
  * **add next coefficient**

That’s ALL.
