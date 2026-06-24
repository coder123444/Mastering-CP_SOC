// CSES 2183 - Missing Coin Sum
// Approach: Sort coins. Track the smallest sum we cannot represent.
// If next coin > reach+1, the answer is reach+1.
// Time: O(n log n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());

    long long reach = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > reach + 1) break;
        reach += a[i];
    }

    cout << reach + 1 << "\n";
    return 0;
}
