// CF 1351B - Two Arrays And Swaps
// Approach: To maximize sum of array a, greedily replace smallest elements of a
// with largest elements of b (do this k times).
// Time: O(n log n)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;

        sort(a.begin(), a.end());       // ascending
        sort(b.rbegin(), b.rend());     // descending

        for (int i = 0; i < k; i++)
            if (b[i] > a[i]) a[i] = b[i];

        long long sum = 0;
        for (int x : a) sum += x;
        cout << sum << "\n";
    }
    return 0;
}
