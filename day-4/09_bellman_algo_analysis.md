# Code walkthrough — chunk by chunk

---

### 1) Headers and `Edge` struct

```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge
{
    int u, v;
    int w;
};
```

**Why:**

* `stdio.h` for `printf`/`scanf`.
* `stdlib.h` for `malloc`/`free`.
* `limits.h` for `LLONG_MAX` (we use `long long` distances).
* `struct Edge` stores one directed edge `u -> v` with integer weight `w`. Using an edge list is the common simple form for Bellman-Ford.

---

### 2) Read `V` and `E` with basic validation

```c
int V, E;
printf("Enter number of vertices and edges (V E): ");
if (scanf("%d %d", &V, &E) != 2 || V <= 0 || E < 0)
{
    fprintf(stderr, "Invalid V or E\n");
    return 1;
}
```

**Why / base case:**

* Program expects two integers. If input fails or `V` nonpositive or `E` negative → we exit with error.
* Always validate input in contest/exam to avoid undefined behaviour.

---

### 3) Print summary (UI help)

```c
printf("\n--- Graph Info ---\n");
printf("Vertices: %d\n", V);
printf("Edges: %d\n\n", E);
```

**Why:** helps you confirm you entered `V` and `E` correctly.

---

### 4) Allocate edge list on heap and read edges

```c
struct Edge *edges = malloc(sizeof(struct Edge) * E);
if (!edges) { fprintf(stderr, "Memory allocation failed\n"); return 1; }

printf("Enter %d edges in format: u v w\n", E);
for (int i = 0; i < E; ++i)
{
    printf("Edge %d: ", i);
    if (scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w) != 3)
    { fprintf(stderr, "Invalid edge input\n"); free(edges); return 1; }

    if (edges[i].u < 0 || edges[i].u >= V || edges[i].v < 0 || edges[i].v >= V)
    { fprintf(stderr, "Edge %d has invalid vertex index\n", i); free(edges); return 1; }
}
```

**Why / base cases:**

* `malloc` because we don’t know `E` at compile time. Always check result.
* For each edge we validate three ints, and we check indexes are in `[0, V-1]` — **prevent out-of-bounds**.
* If input wrong -> free `edges` and exit (important to avoid leaks if program continued).

**Input format required:** `u v w` per line, vertices are 0-based (0..V−1). Example: `0 1 -3`.

---

### 5) Read source vertex with validation

```c
int src;
printf("\nEnter source vertex (0 to %d): ", V - 1);
if (scanf("%d", &src) != 1 || src < 0 || src >= V)
{
    fprintf(stderr, "Invalid source vertex\n");
    free(edges);
    return 1;
}
```

**Why:** check `src` is valid. If not, free previously allocated memory then exit.

---

### 6) Allocate and initialize `dist` array

```c
long long *dist = malloc(sizeof(long long) * V);
if (!dist) { fprintf(stderr, "Memory allocation failed\n"); free(edges); return 1; }

for (int i = 0; i < V; ++i)
    dist[i] = LLONG_MAX;
dist[src] = 0LL;
```

**Why / base case:**

* Use `long long` to reduce the chance of overflow when summing weights.
* `LLONG_MAX` represents infinity: vertex unreachable.
* `dist[src] = 0` is the start: distance from source to itself = 0. **This initialization is critical** — without it nothing relaxes.

---

### 7) Run Bellman-Ford (core)

```c
printf("\nRunning Bellman-Ford...\n\n");

for (int i = 0; i < V - 1; ++i)
{
    printf("Iteration %d:\n", i + 1);

    int changed = 0;
    for (int j = 0; j < E; ++j)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] == LLONG_MAX)
            continue;

        long long cand = dist[u] + (long long)w;
        if (cand < dist[v])
        {
            printf("Relaxing edge %d -> (%d -> %d) weight %d | %lld → %lld\n",
                   j, u, v, w, dist[v], cand);

            dist[v] = cand;
            changed = 1;
        }
    }

    if (!changed)
    {
        printf("No changes, stopping early.\n\n");
        break;
    }

    printf("\n");
}
```

**Line-by-line explanation (core ideas):**

* `for (i = 0; i < V-1; ++i)`: we do up to `V−1` iterations. **Why `V−1`?** See formal note below with KaTeX.
* `changed` is an early termination optimization: if no relaxation happened in a full iteration, distances already stabilized → we can stop early (saves time).
* For each edge `(u -> v, weight w)`:

  * If `dist[u] == LLONG_MAX`, `u` is currently unreachable, so we skip: you cannot relax from an unreachable node.
  * `cand = dist[u] + (long long)w`: compute candidate distance. **Cast to `long long`** to avoid `int` overflow during addition.
  * If `cand < dist[v]` → we relax: `dist[v] = cand`.
* The `printf` inside shows which edge caused a relaxation (helpful for debugging / study).

**Important base cases here:**

* **Unreachable `u`** must be skipped, otherwise `LLONG_MAX + w` would overflow/wrap.
* **Casting** the `w` to `long long` ensures `dist[u] + w` uses 64-bit math.
* **Early stop**: prevents unnecessary future iterations when already optimal.

---

### 8) Negative cycle check

```c
printf("\nChecking for negative cycles...\n");

for (int j = 0; j < E; ++j)
{
    int u = edges[j].u;
    int v = edges[j].v;
    int w = edges[j].w;

    if (dist[u] == LLONG_MAX)
        continue;

    if (dist[u] + w < dist[v])
    {
        printf("Negative cycle detected!\n");

        free(edges);
        free(dist);
        return 0;
    }
}
```

**Why:** Bellman-Ford property: after `V−1` relaxations, if you can still relax any edge, there is a reachable negative weight cycle. So we try one more relaxation: if any `dist[v]` can decrease, report negative cycle and exit.

**Base case:** skip when `dist[u] == LLONG_MAX` (unreachable) — negative cycles reachable only from source matter.

---

### 9) Print final distances and free memory

```c
printf("\n--- FINAL SHORTEST DISTANCES ---\n");
for (int i = 0; i < V; ++i)
{
    if (dist[i] == LLONG_MAX)
        printf("%d : INF\n", i);
    else
        printf("%d : %lld\n", i, dist[i]);
}

free(edges);
free(dist);
return 0;
```

**Why:** print `INF` for nodes unreachable from `src`. Then `free` heap allocations to avoid leaks (good style, required if program extended or re-used).

---

# Formal reason: Why **V−1** iterations? (tiny proof)

A simple fact: **any shortest simple path** between two distinct vertices in a graph with `V` vertices uses at most `V−1` edges (otherwise it repeats a vertex ⇒ a cycle). So the longest possible simple shortest path length (in edges) is `V−1`. Each relaxation can increase the number of edges on known shortest paths by at most 1. Therefore after `V−1` full passes, all shortest distances (for paths without cycles) must be found.

In KaTeX block:
\[
\text{If }P \text{ is a shortest simple path, } |P| \le V-1 \Rightarrow \text{V-1 relaxations suffice.}
\]

(After V−1 iterations any further improvement implies a negative cycle.)

---

# Dry run (concrete example) — step through iterations

Use the example often in textbooks (the one we used in earlier messages). Input:

```
V = 5, E = 8
Edges (index: u v w):
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

**Initial distances (before iterations):**

```
dist = [0, INF, INF, INF, INF]
```

Now iterate:

**Iteration 1:**

* Edge0 (0→1, -1): cand = 0 + (-1) = -1 < INF ⇒ dist[1] = -1
* Edge1 (0→2, 4): cand = 4 < INF ⇒ dist[2] = 4
* Edge2 (1→2, 3): cand = -1 + 3 = 2 < 4 ⇒ dist[2] = 2
* Edge3 (1→3, 2): cand = -1 + 2 = 1 < INF ⇒ dist[3] = 1
* Edge4 (1→4, 2): cand = -1 + 2 = 1 < INF ⇒ dist[4] = 1
* Edge5 (3→2, 5): cand = 1 + 5 = 6 ≥ 2 ⇒ no change
* Edge6 (3→1, 1): cand = 1 + 1 = 2 ≥ -1 ⇒ no change
* Edge7 (4→3, -3): cand = 1 + (-3) = -2 < 1 ⇒ dist[3] = -2

After iteration 1:

```
dist = [0, -1, 2, -2, 1]
```

**Iteration 2:**

* Try all edges — none produce a smaller distance:

  * e.g. Edge5 (3→2): cand = -2 + 5 = 3 >= 2 → no
  * Edge6 (3→1): cand = -2 + 1 = -1 == dist[1] → no
  * Edge7 (4→3): cand = 1 + (-3) = -2 == dist[3] → no
* So `changed` stays 0 → loop breaks early.

Final `dist`:

```
0 : 0
1 : -1
2 : 2
3 : -2
4 : 1
```

Negative cycle check will not find any further relaxations -> no negative cycle.

This dry run matches what the program prints (and the `printf` in loop would show the relaxations that happened).

---

# Key edge cases & pitfalls (exam checklist)

1. **Input format** — make sure you type exactly `V E` then `E` lines `u v w` then `src`. If you omit or mis-order values, `scanf` will wait or fail.
2. **0-based vs 1-based vertices** — your program expects **0-based** vertices (0..V−1). If exam uses 1..V, convert (`u-1`, `v-1`, `src-1`) consistently.
3. **Unreachable nodes** — always check `if (dist[u] == INF) continue;` before relaxing to avoid adding to INF.
4. **Overflow** — use `long long` and cast weights when adding: `dist[u] + (long long)w`. Avoid trying to guard with `if (dist[u] > LLONG_MAX - w)` because with negative weights that guard is wrong. Better: skip if `dist[u]==INF` and use `long long`.
5. **Negative weight cycles** — only cycles reachable from `src` matter. That’s why we check `if (dist[u] == INF) continue;`.
6. **Free memory on every early exit** — your code does this in error branches and in negative cycle branch — good practice.
7. **Edge list size 0** — `E == 0` is valid: program should still run and print `src` distance 0 and others INF.
8. **Large V or E** — `malloc` may fail; you check that. In contests, if constraints are huge, prefer adjacency list + Dijkstra for non-negative weights, but Bellman-Ford is O(V·E).

---

# Complexity and when to use Bellman-Ford

* **Time complexity:** worst case (\Theta(V \cdot E)). With early stopping it can be much faster on many graphs.
* **Space complexity:** (\Theta(V + E)) for `dist` plus `edges`.
* **Use Bellman-Ford when:** you need to handle negative edge weights or detect negative cycles reachable from source. For graphs with no negative weights and large size, use Dijkstra (faster).

---

# Extra tips for the exam (quick checklist you can recite)

* Always set `dist[src] = 0` — first thing.
* Use `LLONG_MAX` for INF and test `dist[u] == LLONG_MAX` before adding.
* Do `V-1` relax iterations, then one extra pass to detect negative cycles.
* Print `INF` for unreachable nodes.
* If vertex indexing in problem is 1-based, convert to 0-based early.
* If asked to print the path itself, maintain a `parent[]` array: whenever you relax `v`, set `parent[v] = u`. After algorithm, reconstruct path by following parents (with care if negative cycle or unreachable).

---

# Optional: How to print actual shortest path (brief)

Add:

```c
int *parent = malloc(sizeof(int)*V);
for (i=0;i<V;i++) parent[i] = -1;
...
if (cand < dist[v]) { dist[v] = cand; parent[v] = u; }
```

Then to print path from `src` to `t`, follow parents backwards and reverse the list. (But be careful: if negative cycles reachable, path reconstruction may be undefined.)

---

# Final sanity check — sample run to copy-paste into terminal

Type exactly (after running program):

```
Enter number of vertices and edges (V E): 5 8

Enter 8 edges in format: u v w
Edge 0: 0 1 -1
Edge 1: 0 2 4
Edge 2: 1 2 3
Edge 3: 1 3 2
Edge 4: 1 4 2
Edge 5: 3 2 5
Edge 6: 3 1 1
Edge 7: 4 3 -3

Enter source vertex (0 to 4): 0
```

You should see the printed relaxations and final distances:

```
0 : 0
1 : -1
2 : 2
3 : -2
4 : 1
```