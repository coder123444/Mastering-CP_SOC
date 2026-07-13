// CSES 1130 - Tree Matching
// Technique: Tree DP with two states per node, computed bottom-up (iterative
// post-order to avoid recursion-depth issues on skewed trees):
//   dp[u][0] = max matching in u's subtree, u NOT matched to any child
//   dp[u][1] = max matching in u's subtree, u IS matched to one of its children
// At the root the answer is max(dp[root][0], dp[root][1]).
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

    // dp0[u]: best matching in subtree(u) where u is unmatched
    // dp1[u]: best matching in subtree(u) where u may be matched (the actual max)
    vector<int> dp0(n + 1, 0), dp1(n + 1, 0);

    for (int i = (int)order.size() - 1; i >= 0; i--) {
        int u = order[i];
        int sumBest = 0;      // sum of dp1[child] over all children, if none matched to u
        int bestGain = 0;     // best extra gain from matching u to one child instead
        for (int v : adj[u]) {
            if (v == parent[u]) continue;
            sumBest += dp1[v];
            // If we match u-v, we gain 1 + dp0[v] instead of dp1[v] for this child
            int gain = 1 + dp0[v] - dp1[v];
            bestGain = max(bestGain, gain);
        }
        dp0[u] = sumBest;                  // u left unmatched
        dp1[u] = sumBest + bestGain;        // best overall (matched or not)
    }

    cout << dp1[1] << "\n";
    return 0;
}
