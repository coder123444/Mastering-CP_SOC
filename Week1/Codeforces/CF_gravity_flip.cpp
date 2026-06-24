// CF 405B - Gravity Flip
// Approach: When gravity flips right, columns sort in non-decreasing order.
// Simply sort the array.
// Time: O(n log n)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
        cout << a[i] << " \n"[i == n - 1];
    return 0;
}
