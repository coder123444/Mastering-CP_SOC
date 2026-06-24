// CSES 1643 - Maximum Subarray Sum
// Approach: Kadane's algorithm. Track current sum and reset to 0 if negative.
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long best = LLONG_MIN, curr = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        curr += x;
        best = max(best, curr);
        if (curr < 0) curr = 0;
    }

    cout << best << "\n";
    return 0;
}
