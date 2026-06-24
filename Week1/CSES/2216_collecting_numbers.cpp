// CSES 2216 - Collecting Numbers
// Approach: Count positions of each number. A new round starts whenever
// position[i] <= position[i-1], meaning we must restart a sweep.
// Time: O(n) | Space: O(n)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pos[x] = i;
    }

    int rounds = 1;
    for (int i = 2; i <= n; i++)
        if (pos[i] < pos[i - 1]) rounds++;

    cout << rounds << "\n";
    return 0;
}
