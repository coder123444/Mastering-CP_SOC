// CSES 1197 - Cycle Finding
// Technique: Bellman-Ford from a virtual source connected to all nodes with
// weight 0 (so every node is "reachable"). If relaxation still happens on the
// n-th round, the relaxed node lies on (or downstream of) a negative cycle -
// walk back n steps via parent pointers to land inside the cycle, then trace
// it out.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = LLONG_MAX / 4;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<array<ll,3>> edges(m);
    for (int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    vector<ll> dist(n + 1, 0); // start everyone at 0, equivalent to a virtual source
    vector<int> parent(n + 1, -1);
    int x = -1;

    for (int iter = 0; iter < n; iter++) {
        x = -1;
        for (auto &e : edges) {
            int a = (int)e[0], b = (int)e[1]; ll w = e[2];
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                parent[b] = a;
                x = b;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
        return 0;
    }

    // Walk back n steps to guarantee landing on the cycle
    for (int i = 0; i < n; i++) x = parent[x];

    vector<int> cycle;
    for (int v = x; ; v = parent[v]) {
        cycle.push_back(v);
        if (v == x && cycle.size() > 1) break;
    }
    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for (size_t i = 0; i < cycle.size(); i++)
        cout << cycle[i] << " \n"[i + 1 == cycle.size()];
    return 0;
}
