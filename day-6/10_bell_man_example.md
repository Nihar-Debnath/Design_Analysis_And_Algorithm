* **Example A:** graph with **negative edge(s)** but **no negative cycle** (Bellman-Ford succeeds)
* **Example B:** graph with a **negative weight cycle reachable** from the source (Bellman-Ford detects it)

For each example I’ll show the program steps (input → memory allocation → initialization → each relaxation iteration → where base cases/guards run → negative-cycle check → deallocation). At the end I’ll also **explain why Bellman-Ford is correct with negative edges and why Dijkstra can fail** (with a tiny counterexample).

---

## Quick reminder of the important code pieces we’ll refer to

(so you can map the dry-run to lines in your program)

1. Read `V, E` and `edges` array (`malloc`)
2. Read `src`
3. `dist` array `malloc`, initialize `dist[i]=LLONG_MAX`, `dist[src]=0`
4. Main loop: `for (i = 0; i < V-1; ++i)` { for each edge relax if `dist[u] != INF` } with `changed` early-stop
5. Negative cycle check: try one more relaxation — if any `dist[v]` would decrease, report negative cycle
6. Print distances, `free(edges)`, `free(dist)`

We’ll call `INF = LLONG_MAX`.

---

# EXAMPLE A — Negative edges, **no negative cycle**

### Input (what you type when the program asks)

```
V = 5, E = 8
Edges:
0: 0 1 -1
1: 0 2 4
2: 1 2 3
3: 1 3 2
4: 1 4 2
5: 3 2 5
6: 3 1 1
7: 4 3 -3
src = 0
```

(This is the same standard example we used earlier. It has negative edge(s) but no negative cycle reachable from `0`.)

---

### Step-by-step execution & state

**(1) Read `V,E`**

* Program prints prompt, you input `5 8`.
* Validation `V>0`, `E>=0` passes.

**(2) `edges = malloc(E * sizeof(struct Edge))`**

* Allocates array of 8 `Edge` on heap. (`edges[0]..edges[7]` filled next.)

**(3) Read edges**

* For each `i=0..7` the scanf fills `edges[i].u`, `.v`, `.w`. Input validated `0 <= u,v < V`.

**(4) Read `src`**

* You input `0`. Validation `0 <= src < V` passes.

**(5) `dist = malloc(V * sizeof(long long))`**

* Allocates `dist[0..4]`.

**(6) Initialize distances**

```text
for i=0..4: dist[i] = INF
dist[src]=0
```

So initially:

```
dist = [0, INF, INF, INF, INF]
```

(Important base case: `dist[src]=0` — without that nothing would ever relax.)

---

### Main relaxation loop: `for iter = 1 to V-1 (i.e., 4)`

We show each edge processed in each iteration, and only list relaxations (changes).

#### Iteration 1 (i = 0)

* `changed = 0` initially.
  Process edges 0..7 in order:

0. Edge 0: (0 -> 1, w=-1)
   `dist[0] != INF` so compute `cand = dist[0] + (-1) = 0 + (-1) = -1`.
   `cand < dist[1]` (`-1 < INF`) → **relax**: `dist[1] = -1`. `changed = 1`.
   (Your code prints: `Relaxing edge 0 -> (0 -> 1) weight -1 | INF → -1`)

1. Edge 1: (0 -> 2, w=4)
   `cand = 0 + 4 = 4 < INF` → relax: `dist[2] = 4`. (`changed` already 1)

2. Edge 2: (1 -> 2, w=3)
   `dist[1] = -1` so `cand = -1 + 3 = 2`. Compare to current `dist[2] = 4`.
   `2 < 4` → relax: `dist[2] = 2`.

3. Edge 3: (1 -> 3, w=2)
   `cand = -1 + 2 = 1 < INF` → relax: `dist[3] = 1`.

4. Edge 4: (1 -> 4, w=2)
   `cand = -1 + 2 = 1 < INF` → relax: `dist[4] = 1`.

5. Edge 5: (3 -> 2, w=5)
   `dist[3]=1`, `cand = 1 + 5 = 6`, compare to `dist[2]=2` → no change.

6. Edge 6: (3 -> 1, w=1)
   `cand = 1 + 1 = 2` compare to `dist[1] = -1` → no change.

7. Edge 7: (4 -> 3, w=-3)
   `dist[4]=1`, `cand = 1 + (-3) = -2` compare to `dist[3] = 1` → **relax**: `dist[3] = -2`.

End of iteration 1: `changed = 1` so loop continues.

Current distances:

```
dist = [0, -1, 2, -2, 1]
```

(Notice several updates — these are printed by your `printf` lines showing which edge relaxed and the values before→after.)

#### Iteration 2 (i = 1)

Start with `dist = [0, -1, 2, -2, 1]`, `changed = 0`.

Process edges:

* Edge 0: 0->1: cand = 0 + (-1) = -1; `-1 < -1`? No → no change.
* Edge 1: 0->2: cand = 4; `4 < 2`? No.
* Edge 2: 1->2: cand = -1 + 3 = 2; `2 < 2`? No.
* Edge 3: 1->3: cand = -1 + 2 = 1; `1 < -2`? No.
* Edge 4: 1->4: cand = -1 + 2 = 1; `1 < 1`? No.
* Edge 5: 3->2: cand = -2 + 5 = 3; `3 < 2`? No.
* Edge 6: 3->1: cand = -2 + 1 = -1; `-1 < -1`? No.
* Edge 7: 4->3: cand = 1 + (-3) = -2; `-2 < -2`? No.

No relaxations in iteration 2 → `changed` remains 0. Your code hits the **early termination base case**:

```c
if (!changed) {
    printf("No changes, stopping early.\n");
    break;
}
```

So the algorithm **stops after iteration 2** (even though `V-1 = 4`), because distances are already stable.

Final distances:

```
dist = [0, -1, 2, -2, 1]
```

#### Negative cycle check (one more pass)

Your code runs the final check:

* For each edge `(u->v,w)`, if `dist[u] != INF` and `dist[u] + w < dist[v]` then negative cycle exists.

Run check quickly: none of the edges produce a smaller `dist[v]`. So **no negative cycle** reported.

**Program prints distances, frees `edges` and `dist` and exits normally.**

---

### Where base cases / checks applied in Example A

* **`if (dist[u] == LLONG_MAX) continue;`** — skipping relaxations from unreachable `u`. In this example, once `src` distributed reachability in first iteration, most u were reachable; this guard prevented `INF + w` undefined math before they became reachable.
* **`changed` early-stop** — triggered at end of iteration 2 because nothing changed; saves iterations.
* **Negative-cycle check** — tried one more relaxation and found none → clean finish.
* **Memory**: `malloc` for edges and dist at start, and `free(edges); free(dist);` at the end (and also in error paths).

---

# EXAMPLE B — **Negative cycle reachable** (Bellman-Ford detects it)

### Input

```
V = 3, E = 3
Edges:
0: 0 1 1
1: 1 2 -2
2: 2 0 -2
src = 0
```

This cycle 0→1→2→0 has total weight `1 + (-2) + (-2) = -3` so it's a negative cycle reachable from source `0`.

---

### Step-by-step execution & state

**(1) read V,E and `edges` as above** — `edges` array allocated and filled.

**(2) `src = 0`**, `dist` allocated and initialized:

```
dist = [0, INF, INF]
```

---

### Main relaxation loop `V-1 = 2` iterations

#### Iteration 1 (i = 0)

Start: `dist = [0, INF, INF]`, `changed=0`.

Process edges:

0. Edge0: (0 -> 1, w=1)
   `dist[0] != INF`, `cand = 0 + 1 = 1 < INF` → **relax** `dist[1] = 1`, `changed=1`.

1. Edge1: (1 -> 2, w=-2)
   `dist[1] = 1`, `cand = 1 + (-2) = -1 < INF` → **relax** `dist[2] = -1`.

2. Edge2: (2 -> 0, w=-2)
   `dist[2] = -1`, `cand = -1 + (-2) = -3`. Compare to `dist[0] = 0`.
   `-3 < 0` → **relax** `dist[0] = -3`! (Crucial point: source's distance decreased!)

End of iteration 1: `dist = [-3, 1, -1]`, `changed=1`.

#### Iteration 2 (i = 1)

Start: `dist = [-3, 1, -1]`, `changed=0`.

Process edges:

0. Edge0: 0->1 (w=1)
   `cand = -3 + 1 = -2 < 1` → **relax** `dist[1] = -2`, `changed=1`.

1. Edge1: 1->2 (w=-2)
   `cand = -2 + (-2) = -4 < -1` → **relax** `dist[2] = -4`.

2. Edge2: 2->0 (w=-2)
   `cand = -4 + (-2) = -6 < -3` → **relax** `dist[0] = -6`.

End of iteration 2: `dist = [-6, -2, -4]`, `changed=1`.

We have completed `V-1` iterations (2 loops). Note distances keep decreasing each iteration because the negative cycle gives better and better paths.

---

### Negative cycle check (one more pass)

Your code now tries one more relaxation over all edges:

* For some edge (say 0->1): `dist[0] + 1 = -6 + 1 = -5`, compare to `dist[1] = -2`. Since `-5 < -2`, the check finds an improvement **even after V-1 iterations** → so the program prints `Negative cycle detected!` and exits (freeing memory before returning).

**This is exactly the Bellman-Ford negative cycle detection property**: if any distance can still be improved after `V-1` relaxations, a negative cycle reachable from `src` exists.

---

### Where base cases / checks applied in Example B

* **Skip unreachable `u`** guard was used only in first iteration for some edges; once nodes became reachable, relaxations happened.
* **Early stop** never triggered because `changed` was always `1` (continuously improving due to negative cycle).
* **Negative-cycle check** found further improvement and reported cycle.
* **Memory** freed on exit.

---

# Why Bellman-Ford works here and why Dijkstra would fail for negative edges

### Bellman-Ford correctness points

* It relaxes every edge up to `V−1` times. Any shortest simple path has at most `V−1` edges. After `V−1` passes, all shortest distances (if finite and no negative cycles reachable) have been propagated.
* The additional 1 pass checks if any distance can still be improved; if so, the improvement must involve a cycle, and because distance improves, the cycle is negative and reachable from the source.

(KaTeX recall you asked for earlier — formal idea:)
[
\text{Any simple path uses at most }V-1\text{ edges. After }V-1\text{ relaxations all shortest simple-path distances settle.}
]

### Dijkstra’s assumption & failure with negative edges

* Dijkstra is greedy: it relies on the fact that when it extracts the vertex with smallest tentative distance from the priority queue, that distance is final — **only true when all edge weights are non-negative**.
* With negative edges, a vertex that Dijkstra finalizes early may later have a **shorter path found via some other vertex** that hasn't been processed yet — Dijkstra will miss this because it never revisits finalized nodes.

#### Concrete counterexample where Dijkstra fails (simple)

Graph:

```
Vertices: S(=0), A(=1), B(=2)
Edges:
S -> A weight 0
S -> B weight 2
B -> A weight -3
```

* Shortest path from `S` to `A` is `S -> B -> A` with cost `2 + (-3) = -1`.
* Dijkstra’s steps:

  * Initialize: `dist[S]=0`, `dist[A]=0`, `dist[B]=2`.
  * The algorithm picks the smallest tentative (tie-break maybe picks A or S first). If Dijkstra pops `A` early because `dist[A] = 0`, it **finalizes A with 0** and never revisits it. It will output `dist[A] = 0`, which is **wrong** (true shortest is -1).
* Bellman-Ford will correctly find `-1` after relaxing edges (because it tries all edges repeatedly).

So **Dijkstra can produce wrong results when any negative edge exists**; Bellman-Ford is designed to handle negatives and detect negative cycles.

---

# Summary checklist for you to remember in the exam (short & precise)

1. Input validation: check `scanf` return, check `0 <= u,v < V`, check `V>0`.
2. Use `long long` for `dist` and `LLONG_MAX` for INF. Always check `if (dist[u] == INF) continue;` before relaxing.
3. Do up to `V-1` iterations of relaxing all edges. Use `changed` to stop early if nothing changed.
4. After `V-1` iterations, try one more pass — if any distance still decreases, **negative cycle reachable** exists.
5. Always `free(edges)` and `free(dist)` on all exit paths (good style).
6. Use Bellman-Ford if negative weights allowed or if you need negative cycle detection; use Dijkstra if all weights non-negative and you need speed.
