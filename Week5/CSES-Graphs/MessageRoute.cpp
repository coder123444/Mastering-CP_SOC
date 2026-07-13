// CSES 1667 - Message Route
// Technique: BFS shortest path (unweighted graph) + parent reconstruction
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist(n + 1, -1), parent(n + 1, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (dist[n] == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> path;
    for (int v = n; v != -1; v = parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int i = 0; i < (int)path.size(); i++)
        cout << path[i] << " \n"[i + 1 == (int)path.size()];
    return 0;
}
