// CF - Balanced Rating Changes
// Approach: XOR-based bit manipulation to balance rating changes.
// For each bit position, track if counts are balanced.
// Time: O(n * 30) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

// ============================================================
// CF - Balanced Rating Changes
// Given array, find minimum number of elements to remove so
// that for each bit, count of numbers with that bit set is even.
// Approach: XOR of all elements. If XOR = 0, answer is 0.
// Otherwise find one element that equals the XOR.
// ============================================================
void balancedRatingChanges() {
    int n; cin >> n;
    vector<int> a(n);
    int xorAll = 0;
    for (int& x : a) { cin >> x; xorAll ^= x; }

    if (xorAll == 0) { cout << 0 << "\n"; return; }

    for (int x : a) {
        if (x == xorAll) { cout << 1 << "\n"; return; }
    }
    cout << 2 << "\n";
}

// ============================================================
// CF - Find the Different Permutation  
// Given two permutations, find the position where they differ
// using XOR properties.
// Approach: XOR corresponding elements; non-zero positions differ.
// ============================================================
void findDifferentPermutation() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    for (int i = 0; i < n; i++) {
        if ((a[i] ^ b[i]) != 0) {
            cout << i + 1 << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

// ============================================================
// CF - Time Management
// Use bit manipulation to efficiently manage time slots.
// Check if a given set of time intervals can be scheduled
// without conflict using bitmask representation.
// ============================================================
void timeManagement() {
    int n; cin >> n;
    long long mask = 0;
    bool possible = true;

    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        // Check if bits l to r-1 are all 0
        long long taskMask = ((1LL << r) - 1) ^ ((1LL << l) - 1);
        if (mask & taskMask) { possible = false; }
        mask |= taskMask;
    }

    cout << (possible ? "YES" : "NO") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Uncomment the function corresponding to the problem being solved:
    // balancedRatingChanges();
    // findDifferentPermutation();
    // timeManagement();

    return 0;
}
