// CSES 1673 - High Score
// Technique: Longest path = shortest path on negated weights via Bellman-Ford.
// After n-1 relaxation rounds, run extra rounds to flag nodes still relaxing
// (i.e. reachable from a positive cycle); if such a node can also reach n,
// the answer is unbounded (-1).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = LLONG_MAX / 4;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<array<ll,3>> edges(m); // {a, b, -x} negated for longest-path via shortest-path BF
    vector<vector<int>> adj(n + 1); // forward graph, for reachability to n
    vector<vector<int>> radj(n + 1); // reverse graph, for "can reach n"

    for (int i = 0; i < m; i++) {
        ll a, b, x;
        cin >> a >> b >> x;
        edges[i] = {a, b, -x};
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    // Reachable from 1
    vector<bool> reachFrom1(n + 1, false);
    {
        queue<int> q; q.push(1); reachFrom1[1] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) if (!reachFrom1[v]) { reachFrom1[v] = true; q.push(v); }
        }
    }
    // Can reach n
    vector<bool> canReachN(n + 1, false);
    {
        queue<int> q; q.push(n); canReachN[n] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : radj[u]) if (!canReachN[v]) { canReachN[v] = true; q.push(v); }
        }
    }

    vector<ll> dist(n + 1, INF);
    dist[1] = 0;

    for (int iter = 0; iter < n - 1; iter++)
        for (auto &e : edges) {
            ll a = e[0], b = e[1], w = e[2];
            if (dist[a] < INF && dist[a] + w < dist[b])
                dist[b] = dist[a] + w;
        }

    vector<bool> onPosCycle(n + 1, false);
    for (int iter = 0; iter < n; iter++)
        for (auto &e : edges) {
            ll a = e[0], b = e[1], w = e[2];
            if (dist[a] < INF && dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                onPosCycle[b] = true;
            }
        }

    bool unbounded = false;
    for (int i = 1; i <= n; i++)
        if (onPosCycle[i] && reachFrom1[i] && canReachN[i]) unbounded = true;

    if (unbounded) cout << -1 << "\n";
    else cout << -dist[n] << "\n";
    return 0;
}
