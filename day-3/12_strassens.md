# First: what problem are we solving?

We want to **multiply two matrices faster** than the normal method.

---

## Normal (traditional) matrix multiplication

If you multiply two **n × n matrices**:

* Time complexity =
  \[
  O(n^3)
  \]

Because:

* 3 nested loops
* For each element → `n` multiplications

This becomes **very slow** for large matrices.

---

# Idea behind Strassen’s Algorithm (very important)

👉 **Reduce the number of multiplications**

Normal method:

* Needs **8 multiplications** for 2×2 matrices

Strassen’s method:

* Needs **only 7 multiplications**

Multiplications are **more expensive** than additions, so this is faster overall.

---

# Step 1: Divide matrices into blocks

Suppose we have two matrices **A** and **B** of size `n × n`.

We divide each into **four submatrices**:

\[
A =
\begin{bmatrix}
A_{11} & A_{12} \
A_{21} & A_{22}
\end{bmatrix}
\quad
B =
\begin{bmatrix}
B_{11} & B_{12} \
B_{21} & B_{22}
\end{bmatrix}
\]

Each submatrix is of size `n/2 × n/2`.

---

# Step 2: Normal block multiplication (what we DON’T want)

Normally, we would compute:

\[
\begin{aligned}
C_{11} &= A_{11}B_{11} + A_{12}B_{21} \
C_{12} &= A_{11}B_{12} + A_{12}B_{22} \
C_{21} &= A_{21}B_{11} + A_{22}B_{21} \
C_{22} &= A_{21}B_{12} + A_{22}B_{22}
\end{aligned}
\]

This needs **8 matrix multiplications**.

---

# Step 3: Strassen’s trick (core concept)

Strassen defined **7 clever products** instead of 8:

\[
\begin{aligned}
M_1 &= (A_{11}+A_{22})(B_{11}+B_{22}) \
M_2 &= (A_{21}+A_{22})B_{11} \
M_3 &= A_{11}(B_{12}-B_{22}) \
M_4 &= A_{22}(B_{21}-B_{11}) \
M_5 &= (A_{11}+A_{12})B_{22} \
M_6 &= (A_{21}-A_{11})(B_{11}+B_{12}) \
M_7 &= (A_{12}-A_{22})(B_{21}+B_{22})
\end{aligned}
\]

✔ Only **7 multiplications**
✔ Some extra additions/subtractions (cheap operations)

---

# Step 4: Build the result matrix

Using those 7 values:

\[
\begin{aligned}
C_{11} &= M_1 + M_4 - M_5 + M_7 \
C_{12} &= M_3 + M_5 \
C_{21} &= M_2 + M_4 \
C_{22} &= M_1 - M_2 + M_3 + M_6
\end{aligned}
\]

That’s it — result matrix **C** is ready.

---

# Step 5: Recursion (why it’s fast)

Each multiplication of size `n` is reduced to:

* **7 multiplications of size `n/2`**

So recurrence relation becomes:

\[
T(n) = 7T(n/2) + O(n^2)
\]

---

# Time Complexity of Strassen’s Algorithm

Using Master Theorem:

\[
T(n) = O(n^{\log_2 7})
\approx O(n^{2.81})
\]

✔ Faster than (O(n^3))

---

# Space Complexity

* Extra space for submatrices
* Recursive calls

\[
\text{Space} = O(n^2)
\]

---

# Why Strassen is important (exam points)

* First algorithm to **break the O(n³) barrier**
* Uses **divide and conquer**
* Foundation for faster matrix algorithms

---

# Limitations (also exam-relevant)

* More **complex to implement**
* Extra memory overhead
* Not efficient for **small matrices**
* Floating-point precision issues

👉 In practice:

* Used only for **large matrices**
* Hybrid approach (switch to normal method for small sizes)

---

# One-line exam definition ⭐

> **Strassen’s matrix multiplication** is a divide-and-conquer algorithm that multiplies two matrices in \(O(n^{2.81})\) time by reducing the number of recursive multiplications from 8 to 7.
