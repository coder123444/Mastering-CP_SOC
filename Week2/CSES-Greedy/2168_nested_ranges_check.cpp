// CSES 2168 - Nested Ranges Check
// Approach: Sort by left ascending, then right descending.
// Use prefix max of right to check containment.
// Time: O(n log n) | Space: O(n)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<tuple<int,int,int>> ranges(n);
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        ranges[i] = {l, r, i};
    }

    // Sort: left asc, right desc (so wider ranges come first for same left)
    sort(ranges.begin(), ranges.end(), [](auto& a, auto& b) {
        if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
        return get<1>(a) > get<1>(b);
    });

    vector<int> contained(n, 0), contains(n, 0);

    // Check if range i is contained in some previous range
    int maxR = INT_MIN;
    for (auto& [l, r, idx] : ranges) {
        if (r <= maxR) contained[idx] = 1;
        maxR = max(maxR, r);
    }

    // Check if range i contains some later range
    // Reverse: sort by left desc, right asc; check suffix max
    sort(ranges.begin(), ranges.end(), [](auto& a, auto& b) {
        if (get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b);
        return get<1>(a) < get<1>(b);
    });

    int minR = INT_MAX;
    for (auto& [l, r, idx] : ranges) {
        if (r >= minR) contains[idx] = 1;
        minR = min(minR, r);
    }

    for (int i = 0; i < n; i++) cout << contained[i] << " \n"[i == n-1];
    for (int i = 0; i < n; i++) cout << contains[i] << " \n"[i == n-1];

    return 0;
}
