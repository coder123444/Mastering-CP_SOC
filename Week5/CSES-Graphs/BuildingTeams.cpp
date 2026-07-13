// CSES 1668 - Building Teams
// Technique: Bipartite check via BFS 2-coloring (handles disconnected graph)
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

    vector<int> color(n + 1, 0); // 0 = unvisited, 1 or 2 = team
    bool possible = true;

    for (int start = 1; start <= n && possible; start++) {
        if (color[start] != 0) continue;
        color[start] = 1;
        queue<int> q;
        q.push(start);
        while (!q.empty() && possible) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (color[v] == 0) {
                    color[v] = 3 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    possible = false;
                    break;
                }
            }
        }
    }

    if (!possible) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int i = 1; i <= n; i++)
        cout << color[i] << " \n"[i == n];
    return 0;
}
