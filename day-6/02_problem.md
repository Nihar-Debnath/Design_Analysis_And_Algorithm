![](./images/Screenshot%202025-11-24%20205055.png)


---



## ✅ Let’s solve the question shown in the image using **Dijkstra’s Algorithm**

Source node = **1**
We must find shortest distance from **1 → 2, 1 → 3, 1 → 4, 1 → 5, 1 → 6**

---

# # 🗺 Graph (as in the picture)

Edges with weights:

* 1–2 = 7
* 1–3 = 9
* 1–6 = 14
* 2–3 = 10
* 2–4 = 15
* 3–4 = 11
* 3–6 = 2
* 6–5 = 9
* 5–4 = 6

---

---

# # 🧮 Applying Dijkstra, step by step

### Initial distances

| Node | Dist |
| ---- | ---- |
| 1    | 0    |
| 2    | ∞    |
| 3    | ∞    |
| 4    | ∞    |
| 5    | ∞    |
| 6    | ∞    |

---

### After processing node **1**

Update neighbors:

| Node | Dist |
| ---- | ---- |
| 1    | 0    |
| 2    | 7    |
| 3    | 9    |
| 6    | 14   |
| 4    | ∞    |
| 5    | ∞    |

---

### Next smallest → node **2**

Check neighbors:

* 2→3 = 7 + 10 = 17 (NOT better)
* 2→4 = 7 + 15 = 22

| Node | Dist |
| ---- | ---- |
| 1    | 0    |
| 2    | 7    |
| 3    | 9    |
| 6    | 14   |
| 4    | 22   |
| 5    | ∞    |

---

### Next smallest → node **3**

neighbors:

* 3→6 = 9 + 2 = **11** ✔ improved
* 3→4 = 9 + 11 = **20** ✔ improved

| Node | Dist |
| ---- | ---- |
| 1    | 0    |
| 2    | 7    |
| 3    | 9    |
| 6    | 11   |
| 4    | 20   |
| 5    | ∞    |

---

### Next smallest → node **6**

neighbors:

* 6→5 = 11 + 9 = **20**

| Node | Dist |
| ---- | ---- |
| 1    | 0    |
| 2    | 7    |
| 3    | 9    |
| 6    | 11   |
| 4    | 20   |
| 5    | 20   |

---

### Next smallest → node **4**

(no improvement)

---

### Last → node **5**

(no improvement)

---

---

# # 🏁 FINAL SHORTEST DISTANCES FROM SOURCE = 1

| Destination | Distance |
| ----------- | -------- |
| 2           | **7**    |
| 3           | **9**    |
| 4           | **20**   |
| 5           | **20**   |
| 6           | **11**   |

---

# ✔ FINAL ANSWER TO FILL IN TABLE

| Source = 1 |   2   |   3   |    4   |    5   |    6   |
| ---------: | :---: | :---: | :----: | :----: | :----: |
|   Distance | **7** | **9** | **20** | **20** | **11** |
