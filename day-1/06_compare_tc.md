## 🧩 What is **Time Complexity**?

**Time complexity** measures how the **execution time** (or number of operations) of an algorithm **increases** with the size of input ( n ).

It tells us *how efficiently* an algorithm performs when the input grows larger.

---

## ⚙️ **Different Types of Time Complexities**

Here are the most common **time complexity classes**, starting from the **fastest (best)** to the **slowest (worst)**:

| Order | Complexity                       | Example Algorithm                    | Growth Rate Description                            |
| :---: | :------------------------------- | :----------------------------------- | :------------------------------------------------- |
|  1️⃣  | **O(1)** — Constant Time         | Accessing an element in an array     | Always takes same time, independent of input size  |
|  2️⃣  | **O(log n)** — Logarithmic Time  | Binary Search                        | Time grows slowly even if input increases a lot    |
|  3️⃣  | **O(n)** — Linear Time           | Linear Search, Traversing an array   | Time increases directly with input size            |
|  4️⃣  | **O(n log n)** — Log-Linear Time | Merge Sort, Quick Sort (avg case)    | Slightly slower than linear, faster than quadratic |
|  5️⃣  | **O(n²)** — Quadratic Time       | Bubble Sort, Insertion Sort          | Time increases rapidly with n²                     |
|  6️⃣  | **O(n³)** — Cubic Time           | Matrix Multiplication (naive)        | Even more rapid growth                             |
|  7️⃣  | **O(2ⁿ)** — Exponential Time     | Recursive Fibonacci, Subset problems | Grows extremely fast — impractical for large n     |
|  8️⃣  | **O(n!)** — Factorial Time       | Travelling Salesman (Brute Force)    | Grows the fastest — only works for tiny inputs     |

---

## 📈 **Comparison: Increasing Order of Growth**

Here’s how they are **arranged from smallest (fastest)** to **largest (slowest)**:

[
O(1) \ < \ O(\log n) \ < \ O(n) \ < \ O(n \log n) \ < \ O(n^2) \ < \ O(n^3) \ < \ O(2^n) \ < \ O(n!)
]

---

## 🧮 **Intuitive Growth Example**

Let’s take ( n = 10 ):

| Complexity | Approx. Operations |
| ---------- | ------------------ |
| O(1)       | 1                  |
| O(log n)   | ~3                 |
| O(n)       | 10                 |
| O(n log n) | ~33                |
| O(n²)      | 100                |
| O(n³)      | 1000               |
| O(2ⁿ)      | 1024               |
| O(n!)      | 3,628,800 😱       |

➡️ You can see how **exponential and factorial** time complexities explode in growth!

---

## 🧠 **Summary (In Words)**

* **Constant (O(1))** → Fastest
* **Logarithmic (O(log n))** → Very efficient (e.g. binary search)
* **Linear (O(n))** → Grows directly with input
* **Linearithmic (O(n log n))** → Common in efficient sorting algorithms
* **Quadratic (O(n²))** → Typical of nested loops
* **Cubic (O(n³))** → Three nested loops
* **Exponential (O(2ⁿ))** → Very expensive (recursion-heavy problems)
* **Factorial (O(n!))** → Almost impossible for large n

---

## 📊 Visual Analogy (How They Grow)

If you plotted them on a graph for large ( n ):

```
|                             O(n!)
|                        O(2^n)
|                O(n^3)
|            O(n^2)
|        O(n log n)
|      O(n)
|   O(log n)
| O(1)
+---------------------------------> n
```
