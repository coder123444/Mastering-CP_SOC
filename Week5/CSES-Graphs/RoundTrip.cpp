// CSES 1669 - Round Trip
// Technique: DFS with parent-edge tracking to find a cycle in an undirected
// graph. When we reach an already-visited vertex that isn't our immediate
// parent, we've found a cycle - reconstruct it via the DFS parent array.
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> parent_, order_;
vector<bool> visited;
int cycleStart = -1, cycleEnd = -1;

void dfs(int u, int p) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (v == p) continue; // skip the edge we came from (single edge, not multi-edge)
        if (cycleStart != -1) return;
        if (visited[v]) {
            cycleEnd = u;
            cycleStart = v;
            return;
        }
        parent_[v] = u;
        dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    adj.assign(n + 1, {});
    parent_.assign(n + 1, -1);
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n && cycleStart == -1; i++)
        if (!visited[i]) dfs(i, -1);

    if (cycleStart == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> cycle;
    cycle.push_back(cycleStart);
    for (int v = cycleEnd; v != cycleStart; v = parent_[v]) cycle.push_back(v);
    cycle.push_back(cycleStart);

    cout << cycle.size() << "\n";
    for (size_t i = 0; i < cycle.size(); i++)
        cout << cycle[i] << " \n"[i + 1 == cycle.size()];
    return 0;
}
