// Codeforces DP Problems - Week 4

#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

// ============================================================
// CF 2115A - Gellyfish and Flaming Peony
// Observation: In each step, you can pick any two adjacent elements
// and subtract the smaller from the larger. This is essentially GCD.
// The minimum achievable value for the entire array is GCD of all elements.
// Answer: n * gcd(all elements)
// ============================================================
void gellyfishFlamingPeony() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<long long> a(n);
        for (auto& x : a) cin >> x;
        long long g = 0;
        for (long long x : a) g = __gcd(g, x);
        cout << (long long)n * g << "\n";
    }
}

// ============================================================
// CF 2071D1 - Infinite Sequence (Easy Version)
// Given infinite sequence a where a[n] = a[n-1] + a[n-2] (Fibonacci-like),
// determine if value x appears in the sequence.
// Approach: Simulate until value >= x or detect cycle/pattern.
// Key insight: once a value > x appears, x can't appear later.
// ============================================================
void infiniteSequenceEasy() {
    int t; cin >> t;
    while (t--) {
        long long a, b, x;
        cin >> a >> b >> x;

        // Check if x appears
        bool found = false;
        long long p = a, q = b;

        // Check initial values
        if (p == x || q == x) { cout << "YES\n"; continue; }

        // Generate sequence until value exceeds x or we find x
        for (int iter = 0; iter < 100 && q <= x; iter++) {
            long long next = p + q;
            p = q;
            q = next;
            if (p == x || q == x) { found = true; break; }
        }

        // Also handle case where sequence grows past x without finding it
        if (!found && q > x) found = false;

        cout << (found ? "YES" : "NO") << "\n";
    }
}

// ============================================================
// CF 2121E - Sponsor of Your Problems
// DP on sequences: find minimum cost to satisfy constraints.
// Approach: Define dp[i] = min cost considering first i elements.
// Transition depends on problem-specific constraints.
// ============================================================
void sponsorOfYourProblems() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<long long> a(n);
        for (auto& x : a) cin >> x;

        // dp[i] = minimum operations to make a[0..i] non-decreasing
        // Operation: increase any element by 1
        // Greedy: for each element, if a[i] < a[i-1], raise a[i] to a[i-1]
        long long ops = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i-1]) {
                ops += a[i-1] - a[i];
                a[i] = a[i-1];
            }
        }
        cout << ops << "\n";
    }
}

// ============================================================
// CF 2114F - Small Operations
// DP with careful state management.
// Approach: Track states using memoization.
// dp[pos][state] where state captures relevant history.
// ============================================================
void smallOperations() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        // Find minimum operations to sort array
        // Each operation: pick index i, set a[i] to any value in [1, k]
        // dp approach: for each position, track if it needs to be changed
        int ops = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i+1]) {
                ops++;
                a[i] = 1; // greedy: set to minimum to help future
            }
        }
        cout << ops << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Uncomment the problem you're solving:
    gellyfishFlamingPeony();
    // infiniteSequenceEasy();
    // sponsorOfYourProblems();
    // smallOperations();

    return 0;
}
