## ⚙️ **Definition: Algorithm Analysis**

> The **analysis of an algorithm** means studying its **performance** — mainly **time** and **space requirements** — to see how efficiently it works.

There are **two ways** to analyze algorithms:

1. **Priori (Theoretical) Analysis**
2. **Posteriori (Empirical) Analysis**

---

## 🔹 **1. Priori Analysis (Before Execution)**

### 📘 **Meaning:**

“Priori” means **before** in Latin.

> **Priori Analysis** is done **before executing** the program —
> it is a **theoretical analysis** based on mathematical calculations.

---

### 🧠 **How it works:**

* We study the algorithm’s **logic**, **loops**, and **operations**.
* We calculate how many basic operations it performs as the input size grows.
* We express efficiency using **asymptotic notations** (like **O(n)**, **O(log n)**, etc.).

---

### 💬 **Example:**

Algorithm to find the **sum of first N numbers:**

```
sum = 0
for i = 1 to N:
    sum = sum + i
```

➡ Number of additions = **N times**
➡ So, **Time complexity = O(N)**

✅ We didn’t run the code — we just analyzed its logic.

---

### 🎯 **Purpose:**

* To **estimate performance** mathematically.
* To **compare algorithms** before implementing them.

---

### 🧩 **Advantages:**

* No need for a computer to test it.
* Helps in early-stage decision making (during algorithm design).

---

## 🔹 **2. Posteriori Analysis (After Execution)**

### 📘 **Meaning:**

“Posteriori” means **after** in Latin.

> **Posteriori Analysis** is done **after executing** the program —
> it is a **practical or experimental analysis**.

---

### 🧠 **How it works:**

* We **run the program** on a computer.
* We record **actual time taken**, **memory used**, and **CPU performance**.
* Results may vary depending on:

  * Hardware (processor, RAM)
  * Compiler
  * Input size
  * Operating System

---

### 💬 **Example:**

Run two sorting algorithms on your computer:

* Bubble Sort → took **5 seconds** for 10000 items
* Merge Sort → took **0.2 seconds** for 10000 items

✅ This is **posteriori analysis** — performance measured after actual execution.

---

### 🎯 **Purpose:**

* To **measure real-world performance**.
* To **test correctness** and **efficiency** in practice.

---

### 🧩 **Advantages:**

* Real and accurate measurements.
* Helps test under different conditions.

---

## 📊 **Comparison Table:**

| Feature        | **Priori Analysis**                 | **Posteriori Analysis**                  |
| -------------- | ----------------------------------- | ---------------------------------------- |
| **Meaning**    | Analysis before execution           | Analysis after execution                 |
| **Type**       | Theoretical / Mathematical          | Practical / Experimental                 |
| **Done using** | Algorithm logic & equations         | Actual program & data                    |
| **Depends on** | Steps, loops, structure             | Hardware, input, environment             |
| **Output**     | Time & space complexity (e.g. O(n)) | Real time, memory used                   |
| **Example**    | Predict O(n²) for Bubble Sort       | Bubble Sort takes 5 sec for 10,000 items |
| **Use**        | During design stage                 | During implementation/testing stage      |

---

## 🧠 **Simple Analogy (Real-life Example):**

Imagine you’re planning a trip.

* **Priori Analysis:**
  You look at the **map** and **estimate** it’ll take 2 hours to reach (theoretical).

* **Posteriori Analysis:**
  You **actually travel**, check the **real time taken** — maybe 2.5 hours (practical).

Same idea applies to algorithms! 💡

---

### ✅ **In Summary:**

| Term                    | Meaning                | When done                  |
| ----------------------- | ---------------------- | -------------------------- |
| **Priori Analysis**     | Theoretical estimation | Before running the program |
| **Posteriori Analysis** | Practical measurement  | After running the program  |
