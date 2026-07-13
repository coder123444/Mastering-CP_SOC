// CSES 1666 - Building Roads
// Technique: Union-Find (DSU) to find connected components, then link one
// representative of each pair of components together with a new road.
#include <bits/stdc++.h>
using namespace std;

vector<int> parent_, rnk;

int find(int x) {
    while (parent_[x] != x) {
        parent_[x] = parent_[parent_[x]];
        x = parent_[x];
    }
    return x;
}

void unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (rnk[a] < rnk[b]) swap(a, b);
    parent_[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    parent_.resize(n + 1);
    rnk.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) parent_[i] = i;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }

    vector<int> reps;
    for (int i = 1; i <= n; i++)
        if (find(i) == i) reps.push_back(i);

    cout << (int)reps.size() - 1 << "\n";
    for (size_t i = 1; i < reps.size(); i++) {
        cout << reps[0] << " " << reps[i] << "\n";
        unite(reps[0], reps[i]);
    }
    return 0;
}
