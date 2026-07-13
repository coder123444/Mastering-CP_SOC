# 🏆 Mastering Competitive Programming

 
> **IIT Bombay  Seasons of Code (SOC) 2026**
 
 
> **Mentor:**  Adit and Vijay
> **Reference Book:** [Competitive Programmer's Handbook](https://cses.fi/book/book.pdf) by Antti Laaksonen

---

## 📚 About This Repository

This repository documents my journey through the **Mastering CP** project under SOS 2026. It contains C++ solutions to problems from **LeetCode**, **CSES**, and **Codeforces**, organized week by week alongside the corresponding theory from the CP Handbook.

All solutions are written in **C++** and focus on clarity, correctness, and time/space efficiency.

---

## 🗂️ Repository Structure

```
Mastering-CP/
├── Week1/               # Sorting, Binary Search, Data Structures
│   ├── LeetCode/
│   ├── CSES/
│   └── Codeforces/
├── Week2/               # Greedy Algorithms & Bit Manipulation
│   ├── CSES-Greedy/
│   ├── Codeforces-Greedy/
│   └── Codeforces-BitManipulation/
├── Week3/               # Number Theory & Combinatorics
│   ├── FastExponentiation/
│   ├── Sieve/
│   ├── Combinatorics/
│   └── NumberTheory/
├── Week4/               # Dynamic Programming
│   ├── CSES-DP/
│   └── Codeforces-DP/
└── Week5/               # Graphs & Trees
    ├── CSES-Graphs/
    └── CSES-Trees/
```

---

## 📅 Week by Week Progress

### 📘 Week 1 : Fundamentals
**CP Handbook Chapters:** 1 (Intro), 2 (Time Complexity), 3 (Sorting & Binary Search), 4 (Data Structures)

**Key Concepts:**
- Time complexity analysis (Big-O notation)
- Sorting algorithms and STL (`sort`, `stable_sort`)
- Binary search (`lower_bound`, `upper_bound`)
- Data structures: `vector`, `set`, `map`, `string`

| Platform | Problem | Key Technique |
|----------|---------|---------------|
| LeetCode | [Single Number](https://leetcode.com/problems/single-number/) | XOR trick |
| LeetCode | [Relative Sort Array](https://leetcode.com/problems/relative-sort-array/) | Custom comparator |
| LeetCode | [Max Vowels in Substring](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/) | Sliding window |
| LeetCode | [Squares of Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/) | Two pointers O(n) |
| LeetCode | [Sort Colors](https://leetcode.com/problems/sort-colors/) | Dutch National Flag |
| LeetCode | [Kth Largest Element](https://leetcode.com/problems/kth-largest-element-in-an-array/) | QuickSelect O(n) |
| CSES | [Apartments](https://cses.fi/problemset/task/1084) | Greedy + Two Pointers |
| CSES | [Maximum Subarray Sum](https://cses.fi/problemset/task/1643) | Kadane's Algorithm |
| CSES | [Missing Coin Sum](https://cses.fi/problemset/task/2183) | Sort + Reach Greedy |
| CSES | [Collecting Numbers](https://cses.fi/problemset/task/2216) | Position tracking |
| CSES | [Collecting Numbers II](https://cses.fi/problemset/task/2217) | Swap + boundary update |
| CSES | [Restaurant Customers](https://cses.fi/problemset/task/1619) | Event sweep |
| CF | [Ordinary Numbers](https://codeforces.com/problemset) | Greedy |
| CF | [Twins](https://codeforces.com/problemset/problem/318/B) | Sort + prefix sum |
| CF | [Gravity Flip](https://codeforces.com/problemset/problem/405/B) | Sorting insight |
| CF | [Two Arrays And Swaps](https://codeforces.com/problemset/problem/1351/B) | Greedy sort |
| CF | [Zero Remainder Array](https://codeforces.com/problemset/problem/1374/C) | Math + prefix |

---

### 📗 Week 2 : Greedy Algorithms & Bit Manipulation
**CP Handbook Chapters:** 6 (Greedy), 10 (Bit Manipulation)

**Key Concepts:**
- Greedy strategy: prove exchange argument or use invariants
- Interval scheduling and sweep line
- Bitwise operators: `&`, `|`, `^`, `~`, `<<`, `>>`
- Common bit tricks: `x & (x-1)`, `__builtin_popcount`, XOR properties

| Platform | Problem | Key Technique |
|----------|---------|---------------|
| CSES | [Tasks and Deadlines](https://cses.fi/problemset/task/1630) | Greedy — Shortest Job First |
| CSES | [Nested Ranges Check](https://cses.fi/problemset/task/2168) | Sort + prefix max |
| CSES | [Nested Ranges Count](https://cses.fi/problemset/task/2169) | Sort + BIT/sweep |
| CSES | [Room Allocation](https://cses.fi/problemset/task/1164) | Event sweep + multiset |
| CSES | [Reading Books](https://cses.fi/problemset/task/1631) | Sort + pairing |
| CF | [Minimal Difference](https://codeforces.com/problemset) | Sort + sliding window |
| CF | [Hyperset](https://codeforces.com/problemset/problem/1287/C) | Set + complement counting |
| CF | [Balanced Ternary String](https://codeforces.com/problemset/problem/1104/C) | Greedy balancing |
| CF | [Balanced Rating Changes](https://codeforces.com/problemset) | XOR properties |
| CF | [Find Different Permutation](https://codeforces.com/problemset) | Bit XOR |
| CF | [Mocha and Math](https://codeforces.com/problemset/problem/1559/D) | Bitwise AND pattern |
| CF | [Raising Bacteria](https://codeforces.com/problemset/problem/579/A) | Popcount |
| CF | [AND 0, Sum Big](https://codeforces.com/problemset/problem/1758/B) | Bit distribution |
| CF | [Fedor and New Game](https://codeforces.com/problemset/problem/402/D) | XOR + popcount |
| CF | [AND, OR and Square Sum](https://codeforces.com/problemset/problem/1368/C) | Bit-level sorting |

---

### 📙 Week 3 : Number Theory & Combinatorics
**CP Handbook Chapters:** 21 (Number Theory), 22 (Combinatorics), 24 (Probability)

**Key Concepts:**
- Binary exponentiation in O(log n)
- Sieve of Eratosthenes for prime generation
- Modular arithmetic, Fermat's Little Theorem
- nCr with precomputed factorials and inverse factorials
- Euler's Totient Function φ(n)
- Möbius function and inclusion-exclusion
- Derangements, Catalan numbers

| Platform | Problem | Key Technique |
|----------|---------|---------------|
| CSES | [Exponentiation II](https://cses.fi/problemset/task/1712) | Binary exp + Fermat's LTT |
| CF | [742A](https://codeforces.com/problemset/problem/742/A) | Fast power |
| CSES | [Counting Primes](https://cses.fi/problemset/task/1163) | Sieve of Eratosthenes |
| LC | [Count Primes](https://leetcode.com/problems/count-primes/) | Sieve |
| CSES | [Binomial Coefficients](https://cses.fi/problemset/task/1079) | Modular nCr |
| CSES | [Distributing Apples](https://cses.fi/problemset/task/1716) | Stars and bars |
| CSES | [Christmas Party](https://cses.fi/problemset/task/1717) | Derangement DP |
| CSES | [Permutation Order](https://cses.fi/problemset/task/1713) | Combinatorics |
| CSES | [Bracket Sequences I](https://cses.fi/problemset/task/2189) | Catalan numbers |
| CSES | [Bracket Sequences II](https://cses.fi/problemset/task/2188) | Catalan + offset |
| CSES | [Euler's Totient](https://cses.fi/problemset/task/) | φ(n) formula |
| SPOJ | [SQFREE](https://www.spoj.com/problems/SQFREE/) | Möbius function |

---

### 📕 Week 4 : Dynamic Programming
**CP Handbook Chapter:** 7 (Dynamic Programming)

**Key Concepts:**
- State definition and transitions
- Memoization (top-down) vs Tabulation (bottom-up)
- Classical DP patterns: knapsack, LCS, LIS, edit distance
- DP on grids, intervals and bitmasks
- Counting problems modulo a prime

| Platform | Problem | Key Technique |
|----------|---------|---------------|
| CSES | [Dice Combinations](https://cses.fi/problemset/task/1633) | Linear DP |
| CSES | [Minimizing Coins](https://cses.fi/problemset/task/1634) | Unbounded knapsack |
| CSES | [Coin Combinations I](https://cses.fi/problemset/task/1635) | Counting — order matters |
| CSES | [Coin Combinations II](https://cses.fi/problemset/task/1636) | Counting — order doesn't matter |
| CSES | [Removing Digits](https://cses.fi/problemset/task/1637) | Digit DP / BFS |
| CSES | [Grid Paths](https://cses.fi/problemset/task/1638) | 2D DP with obstacles |
| CSES | [Book Shop](https://cses.fi/problemset/task/1158) | 0/1 Knapsack |
| CSES | [Array Description](https://cses.fi/problemset/task/1746) | DP with value constraint |
| CSES | [Edit Distance](https://cses.fi/problemset/task/1641) | Classic string DP |
| CSES | [LCS](https://cses.fi/problemset/task/1644) | Classic string DP |
| CSES | [LIS](https://cses.fi/problemset/task/1145) | Binary search O(n log n) |
| CF | [2115A - Gellyfish and Flaming Peony](https://codeforces.com/problemset/problem/2115/A) | GCD insight |
| CF | [2071D1 - Infinite Sequence (Easy)](https://codeforces.com/problemset/problem/2071/D1) | Simulation + DP |
| CF | [2121E - Sponsor of Your Problems](https://codeforces.com/problemset/problem/2121/E) | Greedy DP |
| CF | [2114F - Small Operations](https://codeforces.com/problemset/problem/2114/F) | DP with states |

---

### 📔 Week 5 : Graphs & Trees
**CP Handbook Chapters:** 11–15 (Basics of Graphs, Graph Traversal, Shortest Paths, Tree Algorithms, Spanning Trees), skimmed 16–19

**Key Concepts:**
- Graph representations: adjacency list/matrix
- BFS / DFS traversal, connected components, flood fill
- Bipartiteness (2 coloring), cycle detection (directed & undirected)
- Dijkstra's algorithm, Bellman Ford, Floyd Warshall
- Topological sort (Kahn's algorithm)
- Tree DP: subtree sizes, max matching, rerooting technique

| Platform | Problem | Key Technique |
|----------|---------|---------------|
| CSES | [Counting Rooms](https://cses.fi/problemset/task/1192) | Grid flood fill (BFS) |
| CSES | [Labyrinth](https://cses.fi/problemset/task/1193) | BFS + path reconstruction |
| CSES | [Building Roads](https://cses.fi/problemset/task/1666) | DSU — connect components |
| CSES | [Message Route](https://cses.fi/problemset/task/1667) | BFS shortest path + reconstruction |
| CSES | [Building Teams](https://cses.fi/problemset/task/1668) | Bipartite 2-coloring (BFS) |
| CSES | [Round Trip](https://cses.fi/problemset/task/1669) | Cycle detection, undirected graph |
| CSES | [Monsters](https://cses.fi/problemset/task/1194) | Multi-source BFS + escape BFS |
| CSES | [Shortest Routes I](https://cses.fi/problemset/task/1671) | Dijkstra |
| CSES | [Shortest Routes II](https://cses.fi/problemset/task/1672) | Floyd-Warshall, all-pairs |
| CSES | [High Score](https://cses.fi/problemset/task/1673) | Bellman-Ford, longest path + positive cycle |
| CSES | [Flight Discount](https://cses.fi/problemset/task/1195) | Dijkstra, expanded state space |
| CSES | [Cycle Finding](https://cses.fi/problemset/task/1197) | Bellman-Ford, negative cycle detection |
| CSES | [Flight Routes](https://cses.fi/problemset/task/1196) | k-shortest-paths Dijkstra |
| CSES | [Round Trip II](https://cses.fi/problemset/task/1678) | Cycle detection, directed graph |
| CSES | [Course Schedule](https://cses.fi/problemset/task/1679) | Topological sort (Kahn's) |
| CSES | [Subordinates](https://cses.fi/problemset/task/1674) | Tree DP — subtree size |
| CSES | [Tree Matching](https://cses.fi/problemset/task/1130) | Tree DP — max matching |
| CSES | [Distance in Tree](https://cses.fi/problemset/task/1131) | Tree DP — rerooting |

---

## 🛠️ How to Compile & Run

All solutions use standard C++17. To compile and run:

```bash
g++ -std=c++17 -O2 -o solution solution.cpp
./solution < input.txt
```

Or directly in terminal:
```bash
g++ -std=c++17 -O2 filename.cpp -o out && ./out
```

---

## 📌 Common Templates Used

### Fast I/O
```cpp
ios_base::sync_with_stdio(false);
cin.tie(NULL);
```

### Binary Exponentiation
```cpp
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}
```

### nCr Modular
```cpp
// Precompute fact[] and inv_fact[] using Fermat's little theorem
long long C(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n-r] % MOD;
}
```

### Sieve of Eratosthenes
```cpp
vector<bool> is_prime(N+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= N; i++)
    if (is_prime[i])
        for (int j = i*i; j <= N; j += i)
            is_prime[j] = false;
```

---

## 📖 Resources

| Resource | Link |
|----------|------|
| CP Handbook (Primary) | [cses.fi/book/book.pdf](https://cses.fi/book/book.pdf) |
| CP-Algorithms | [cp-algorithms.com](https://cp-algorithms.com) |
| CSES Problem Set | [cses.fi/problemset](https://cses.fi/problemset) |
| Codeforces | [codeforces.com](https://codeforces.com) |
| LeetCode | [leetcode.com](https://leetcode.com) |

---

## 👤 Author

**Yatharth**
IIT Bombay | SOC 2026 | Mastering CP Project
