// CF 1A - Theatre Square (Ordinary Numbers variant)
// Approach: Greedy ceil division. Count tiles needed for n x m square using a x a tiles.
// Time: O(1) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, a;
    cin >> n >> m >> a;
    cout << ((n + a - 1) / a) * ((m + a - 1) / a) << "\n";
    return 0;
}
