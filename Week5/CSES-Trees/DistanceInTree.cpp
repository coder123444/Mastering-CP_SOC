// CSES 1131 - Distance in Tree
// Technique: Rerooting DP. First pass (post-order) computes, for each node,
// the max distance down into its own subtree (down1) plus which child that
// max came through, and the second-best max through a different child
// (down2, for when we need "best excluding a given child"). Second pass
// (pre-order) propagates the best distance reachable by going "up" through
// the parent (up[u]), combining with down1/down2 of the parent as needed.
// Answer for each node = max(down1[u], up[u]).
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parent(n + 1, 0), order;
    vector<bool> visited(n + 1, false);
    vector<int> st = {1};
    visited[1] = true;
    while (!st.empty()) {
        int u = st.back(); st.pop_back();
        order.push_back(u);
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                st.push_back(v);
            }
        }
    }

    vector<int> down1(n + 1, 0), down2(n + 1, 0), downChild(n + 1, -1);

    // Post-order: process children before parents
    for (int i = (int)order.size() - 1; i >= 0; i--) {
        int u = order[i];
        for (int v : adj[u]) {
            if (v == parent[u]) continue;
            int candidate = down1[v] + 1;
            if (candidate > down1[u]) {
                down2[u] = down1[u];
                down1[u] = candidate;
                downChild[u] = v;
            } else if (candidate > down2[u]) {
                down2[u] = candidate;
            }
        }
    }

    vector<int> up(n + 1, 0);
    // Pre-order: process parents before children
    for (int u : order) {
        for (int v : adj[u]) {
            if (v == parent[u]) continue;
            // Best distance going "up" from v: either via u's up value,
            // or via u's best downward branch that does NOT go through v.
            int throughU;
            if (downChild[u] == v) throughU = down2[u] + 1;
            else throughU = down1[u] + 1;
            up[v] = max(throughU, up[u] + 1);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << max(down1[i], up[i]) << " \n"[i == n];
    return 0;
}
