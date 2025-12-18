# Merge Sort – Pseudocode (DAA)

---

## MERGE-SORT

```
MERGE-SORT(A, left, right)
1. if left < right
2.     mid ← ⌊(left + right) / 2⌋
3.     MERGE-SORT(A, left, mid)
4.     MERGE-SORT(A, mid + 1, right)
5.     MERGE(A, left, mid, right)
```

---

## MERGE Procedure

```
MERGE(A, left, mid, right)
1. n1 ← mid − left + 1
2. n2 ← right − mid

3. create arrays L[1…n1], R[1…n2]

4. for i ← 1 to n1
5.     L[i] ← A[left + i − 1]

6. for j ← 1 to n2
7.     R[j] ← A[mid + j]

8. i ← 1, j ← 1, k ← left

9. while i ≤ n1 and j ≤ n2
10.    if L[i] ≤ R[j]
11.        A[k] ← L[i]
12.        i ← i + 1
13.    else
14.        A[k] ← R[j]
15.        j ← j + 1
16.    k ← k + 1

17. while i ≤ n1
18.    A[k] ← L[i]
19.    i ← i + 1
20.    k ← k + 1

21. while j ≤ n2
22.    A[k] ← R[j]
23.    j ← j + 1
24.    k ← k + 1
```

---

## How examiners evaluate this 📝

They look for:

* ✔ recursive divide (`MERGE-SORT`)
* ✔ correct mid calculation
* ✔ separate `MERGE` procedure
* ✔ stable comparison (`≤`)
* ✔ copying remaining elements

---

## Shorter pseudocode (if space is limited)

```
MERGE-SORT(A)
if |A| ≤ 1 return A
split A into L and R
return MERGE(MERGE-SORT(L), MERGE-SORT(R))
```

---

## One-line theory reminder 🧠

> **Merge Sort recursively divides the array and merges sorted subarrays.**
