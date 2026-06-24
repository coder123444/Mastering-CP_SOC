// Extra Bit Manipulation Problems
// ============================================================

#include <bits/stdc++.h>
using namespace std;

// ============================================================
// Raising Bacteria
// Problem: You have n bacteria. Each day you can double the count
// or add 1. Find min days to reach exactly n bacteria starting from 1.
// Approach: Count set bits in n (number of 1s in binary representation).
// Each 1-bit requires one "add 1" operation, each bit position shift = double.
// Answer = (number of bits - 1) + (number of set bits)
//        = floor(log2(n)) + __builtin_popcount(n)
// Time: O(log n)
// ============================================================
void raisingBacteria() {
    int n; cin >> n;
    cout << __builtin_popcount(n) + (int)floor(log2(n)) << "\n";
}

// ============================================================
// AND 0, Sum Big
// Problem: Construct array of k elements such that AND of all = 0
// and sum is maximized.
// Approach: To maximize sum while AND = 0, use k copies of (2^n - 1)
// but flip one bit in each to ensure AND becomes 0.
// For n-bit numbers, use all 1s for k-1 elements and complement for 1.
// Greedy: all elements = 2^29 - 1, ensures AND = 0 if k >= 1.
// Actually: all (2^30 - 1), the AND over them = (2^30-1) != 0.
// Key insight: For each bit, at least one element must have it 0.
// So for each bit b, set exactly one element's bit b to 0.
// With k elements: if k >= 30, all elements can be (2^30-1) except we need
// at least one zero per bit. Assign bit b to element b%k.
// Each element misses at most ceil(30/k) bits.
// Max element value = all bits set minus the bits we must clear.
// ============================================================
void andZeroSumBig() {
    int n, k; cin >> n >> k;
    // Each element is all 1s in n bits, but we distribute the "zero" bits
    // Element i: all 1s except for bits where i is the designated "zero holder"
    // For bit b, element (b % k) must have bit b = 0
    vector<long long> a(k, (1LL << n) - 1);
    for (int b = 0; b < n; b++) {
        a[b % k] &= ~(1LL << b); // clear bit b in element (b%k)
    }
    long long sum = 0;
    for (long long x : a) sum += x;
    cout << sum << "\n";
}

// ============================================================
// Fedor and New Game
// Problem: Players choose classes using bitmasks. Two players can
// play together if (mask1 & mask2) = mask1 or mask2 (one contains other)
// or their XOR <= some threshold. Find max group size.
// Approach: For each player as "owner", count others compatible.
// ============================================================
void fedorAndNewGame() {
    int n, d; cin >> n >> d;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (__builtin_popcount(a[i] ^ a[j]) <= d)
                cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
}

// ============================================================
// AND, OR and square sum
// Problem: Given array, repeatedly pick two elements, replace with
// (a&b) and (a|b). Maximize sum of squares.
// Key Insight: a&b + a|b = a+b (sum preserved), but a^2+b^2 is maximized
// when values are as extreme as possible. Sorting + bit consolidation.
// Approach: For each bit, count how many numbers have it set.
// Reconstruct numbers greedily from MSB.
// ============================================================
void andOrSquareSum() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    
    // Count set bits at each position
    vector<int> bitCount(30, 0);
    for (int x : a) {
        for (int b = 0; b < 30; b++)
            if (x >> b & 1) bitCount[b]++;
    }
    
    // Reconstruct: greedily assign bits to make numbers as large as possible
    vector<long long> result(n, 0);
    for (int b = 29; b >= 0; b--) {
        for (int i = 0; i < bitCount[b]; i++)
            result[i] |= (1LL << b);
    }
    
    long long ans = 0;
    for (long long x : result) ans += x * x;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        // Call the relevant function
        andOrSquareSum();
    }
    return 0;
}
