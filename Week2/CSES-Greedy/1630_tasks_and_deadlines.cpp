// CSES 1630 - Tasks and Deadlines
// Approach: Greedy - sort by duration ascending. The reward for a task is
// deadline - finish_time. Shortest Job First maximizes total reward.
// Time: O(n log n) | Space: O(n)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<pair<long long, long long>> tasks(n);
    for (auto& [d, dl] : tasks) cin >> d >> dl;

    // Sort by duration
    sort(tasks.begin(), tasks.end());

    long long time = 0, reward = 0;
    for (auto& [d, dl] : tasks) {
        time += d;
        reward += dl - time;
    }

    cout << reward << "\n";
    return 0;
}
