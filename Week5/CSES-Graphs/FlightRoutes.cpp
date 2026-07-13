// CSES 1196 - Flight Routes
// Technique: k-shortest-paths Dijkstra variant. Instead of stopping once a
// node is finalized, allow up to k "visits" (pops) per node from the heap -
// the j-th time node n is popped gives the j-th shortest route price.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int,ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<int> visitCount(n + 1, 0);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pq.push({0, 1});

    vector<ll> answers;

    while (!pq.empty() && (int)answers.size() < k) {
        auto [d, u] = pq.top(); pq.pop();
        if (visitCount[u] >= k) continue;
        visitCount[u]++;
        if (u == n) answers.push_back(d);
        for (auto [v, w] : adj[u]) {
            if (visitCount[v] < k) pq.push({d + w, v});
        }
    }

    for (size_t i = 0; i < answers.size(); i++)
        cout << answers[i] << " \n"[i + 1 == answers.size()];
    return 0;
}
