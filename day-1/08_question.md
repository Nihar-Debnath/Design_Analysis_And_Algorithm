## 1) The functions (as in the picture)

I’ll use the notation that matches the image:

* $(f_1(n) = n^2 \cdot \log_{10} n)$
* $(f_2(n) = n \cdot \big(\log_{10} n\big)^{10})$


(If your logs use a different base the asymptotic result is the same — changing the log base is just a constant factor for $(\log n)$, but using different bases in small-n numerical checks can change which numeric value is larger.)

---

## 2) Quick increasing-order reminder

(Useful background your image shows)

$$[
O(1) ; <; O(\log\log n); <; O(\log n); <; O(n^{1/2}); <; O(n); <; O(n\log n); <; O(n^2); <; O(n^3); <; O(2^n); <; O(n!)
]$$

This tells you roughly where (n), $(n\log n)$, (n^2), etc. sit relative to each other.

---

## 3) Evaluate numerically at (n=16) and (n=10^9)

I computed these precisely (logs base 10):

### For (n=16)

$$(\log_{10}16 \approx 1.20411998)$$

* $$(f_1(16) = 16^2 \cdot \log_{10}16 = 256 \cdot 1.20412 \approx 308.25)$$
* $$(f_2(16) = 16 \cdot (1.20412)^{10} \approx 16 \cdot 6.4076 \approx 102.52)$$

So **at (n=16)** (with both logs base 10) we get
$$[
f_1(16) \approx 308.25,\qquad f_2(16)\approx102.52\quad\Rightarrow\quad f_1(16) > f_2(16).
]$$

> Note: if somebody used a different log base for (f_2) (e.g. (\log_2 16 = 4)), then ((\log_2 16)^{10}=4^{10}=1{,}048{,}576) and (f_2(16)) would be huge — that is why mixing bases in hand work can give surprising small-(n) results. But asymptotically the base doesn’t change the growth class.

---

### For (n=10^9)

$(\log_{10}10^9 = 9)$

* $(f_1(10^9) = (10^9)^2 \cdot 9 = 9\times10^{18})$
* $(f_2(10^9) = 10^9 \cdot 9^{10} ). Since (9^{10}=3{,}486{,}784{,}401 \approx 3.4867\times10^9)$,
  $$[
  f_2(10^9) \approx 10^9\cdot 3.4867\times10^9 = 3.4867\times10^{18}.
  ]$$

So **at (n=10^9)**,
$$[
f_1(10^9)\approx 9.0\times10^{18},\qquad f_2(10^9)\approx 3.4868\times10^{18},
]$$
so again **$(f_1(10^9) > f_2(10^9))$** (and the gap is larger than at (n=16)).

---

## 4) The real (asymptotic) comparison — the step-by-step proof

Compute the ratio
$$
\frac{f_1(n)}{f_2(n)} = \frac{n^2\log n}{n(\log n)^{10}} =  \frac{n\log n}{\log n(\log n)^{9}} = \frac{n}{(\log n)^9} = \frac{\log (n)}{\log((\log n)^9)} 
$$

$$
    = \frac{\log (n)}{9\log(\log n)} = \frac{\log (n)}{\log(\log n)}
$$

* 9 constants cancels out because we `c*n =  n` where c is constant


---

We ask: does this ratio go to (0), a constant, or $(\infty)$ as $(n\to\infty)$?

Let $(n=e^t)$. Then $(\log n = t)$ and the ratio becomes
$$[
\frac{e^t}{t^9}.
]$$
As $(t\to\infty)$, $(e^t)$ grows MUCH faster than any polynomial $(t^9)$, so
$$[
\lim_{t\to\infty}\frac{e^t}{t^9}=\infty.
]$$
Hence
$$[
\lim_{n\to\infty}\frac{f_1(n)}{f_2(n)}=\infty,
]$$
which means $(f_1(n))$ grows strictly faster than $(f_2(n)) $for large (n). In asymptotic notation:

* $(f_1(n) = \omega(f_2(n))) (i.e. (f_2(n)=o(f_1(n))))$,
* equivalently $(f_1(n)\in\Omega(f_2(n)))$ but **not** $(O(f_2(n)))$, and $(f_1)$ and $(f_2)$ are **not** $(\Theta)$ of each other.

Intuition: the extra factor of (n) in $(f_1)$ (compared to the (n) in $(f_2)$) beats any fixed power of $(\log n)$. In general, for any constant (k) and any fixed (c>0),
$$[
\lim_{n\to\infty}\frac{n^c}{(\log n)^k}=\infty.
]$$

---

## 5) Conclusion / takeaways

* **Asymptotically:** $(f_1(n) = n^2\log n)$ **dominates** $(f_2(n)=n(\log n)^{10})$. So for very large (n), $(f_1)$ is larger and $(f_2)$ is negligible comparatively. Symbolically: $(f_2(n)=o(f_1(n)))$.
* **Numerical checks:** For the given choices with logs base 10, both at (n=16) and at $(n=10^9)$ we found $(f_1>f_2)$. If someone uses different log bases inconsistently (e.g. $(\log_2)$ inside $(f_2)$ but log10 in $(f_1)$), small-(n) numeric comparisons can flip, so don’t trust tiny examples — rely on asymptotic reasoning for large-(n) behavior.
* **Rule of thumb:** any polynomial factor (n^\alpha) (with $(\alpha>0)$) eventually outgrows any polylogarithmic factor $((\log n)^k)$.