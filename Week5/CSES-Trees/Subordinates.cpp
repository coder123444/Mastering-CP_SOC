// CSES 1674 - Subordinates
// Technique: Tree DP. For each employee, the number of subordinates equals
// the size of their subtree minus themselves. Compute via post-order DFS
// (implemented iteratively to avoid stack overflow on skewed trees, n <= 2e5).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> children(n + 1);
    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        children[boss].push_back(i);
    }

    vector<ll> subtreeSize(n + 1, 1);
    vector<int> order;

    // Iterative pre-order traversal to get a discovery order
    vector<int> st = {1};
    while (!st.empty()) {
        int u = st.back(); st.pop_back();
        order.push_back(u);
        for (int c : children[u]) st.push_back(c);
    }

    // Process in reverse BFS/DFS discovery order so children are done before parents
    for (int i = (int)order.size() - 1; i >= 0; i--) {
        int u = order[i];
        for (int c : children[u]) subtreeSize[u] += subtreeSize[c];
    }

    for (int i = 1; i <= n; i++)
        cout << subtreeSize[i] - 1 << " \n"[i == n];
    return 0;
}
