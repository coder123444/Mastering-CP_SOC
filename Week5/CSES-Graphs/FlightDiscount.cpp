// CSES 1195 - Flight Discount
// Technique: Dijkstra over an expanded state space (node, discountUsed).
// From each state we can either take a full-price edge (state unchanged, if
// discount not yet used) or use the discount on this edge (halve the cost,
// only allowed once, moves to discountUsed = true).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = LLONG_MAX / 2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    // dist[node][0] = best cost without discount used, dist[node][1] = with discount used
    vector<array<ll,2>> dist(n + 1, {INF, INF});
    dist[1][0] = 0;

    priority_queue<array<ll,3>, vector<array<ll,3>>, greater<>> pq; // {dist, node, discountUsed}
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        ll d = top[0]; int u = (int)top[1]; int used = (int)top[2];
        if (d > dist[u][used]) continue;

        for (auto [v, w] : adj[u]) {
            // Option 1: don't use discount on this edge
            if (d + w < dist[v][used]) {
                dist[v][used] = d + w;
                pq.push({dist[v][used], v, used});
            }
            // Option 2: use discount on this edge (only if not used yet)
            if (used == 0 && d + w / 2 < dist[v][1]) {
                dist[v][1] = d + w / 2;
                pq.push({dist[v][1], v, 1});
            }
        }
    }

    cout << min(dist[n][0], dist[n][1]) << "\n";
    return 0;
}
