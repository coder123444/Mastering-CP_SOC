// CSES 1678 - Round Trip II
// Technique: DFS with a "currently in recursion stack" marker. If we reach a
// node that's on the current DFS path (state == IN_STACK), we've found a
// directed cycle - reconstruct it via parent pointers.
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> state_; // 0 = unvisited, 1 = in stack, 2 = done
vector<int> parent_;
int cycleStart = -1, cycleEnd = -1;

void dfs(int u) {
    state_[u] = 1;
    for (int v : adj[u]) {
        if (cycleStart != -1) return;
        if (state_[v] == 0) {
            parent_[v] = u;
            dfs(v);
        } else if (state_[v] == 1) {
            cycleStart = v;
            cycleEnd = u;
            return;
        }
    }
    state_[u] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    adj.assign(n + 1, {});
    state_.assign(n + 1, 0);
    parent_.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n && cycleStart == -1; i++)
        if (state_[i] == 0) dfs(i);

    if (cycleStart == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> cycle;
    cycle.push_back(cycleStart);
    for (int v = cycleEnd; v != cycleStart; v = parent_[v]) cycle.push_back(v);
    cycle.push_back(cycleStart);
    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << "\n";
    for (size_t i = 0; i < cycle.size(); i++)
        cout << cycle[i] << " \n"[i + 1 == cycle.size()];
    return 0;
}
