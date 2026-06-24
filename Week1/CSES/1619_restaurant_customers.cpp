// CSES 1619 - Restaurant Customers
// Approach: Event sweep. Mark each arrival as +1, departure as -1.
// Sort events by time, process to find peak simultaneous customers.
// Time: O(n log n) | Space: O(n)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        events.push_back({a, +1});
        events.push_back({b, -1});
    }

    sort(events.begin(), events.end());

    int cur = 0, best = 0;
    for (auto& [t, d] : events) {
        cur += d;
        best = max(best, cur);
    }

    cout << best << "\n";
    return 0;
}
