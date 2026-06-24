// CSES 2217 - Collecting Numbers II
// Approach: For each swap (a, b), determine how many rounds are saved/added
// by checking boundary conditions between consecutive numbers.
// Time: O((n + m) log n) | Space: O(n)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    // Count initial rounds
    int rounds = 1;
    for (int i = 2; i <= n; i++)
        if (pos[i] < pos[i - 1]) rounds++;

    // Helper: does value v cause a new round? (pos[v] < pos[v-1])
    auto causesBreak = [&](int v) -> bool {
        return v > 1 && v <= n && pos[v] < pos[v - 1];
    };

    while (m--) {
        int u, v;
        cin >> u >> v;

        if (u == v) {
            cout << rounds << "\n";
            continue;
        }

        // Values at positions u and v
        int x = a[u], y = a[v];

        // Remove old contributions
        // Neighbors: x-1, x, x+1 and y-1, y, y+1 boundaries
        set<int> check = {x, x + 1, y, y + 1};
        for (int c : check)
            if (causesBreak(c)) rounds--;

        // Perform swap
        swap(a[u], a[v]);
        pos[x] = v;
        pos[y] = u;

        // Add new contributions
        for (int c : check)
            if (causesBreak(c)) rounds++;

        cout << rounds << "\n";
    }

    return 0;
}
