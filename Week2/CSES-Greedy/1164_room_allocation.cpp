// CSES 1164 - Room Allocation
// Approach: Event sweep / greedy with multiset. Assign the room that frees up
// earliest but still after the current arrival. Track room assignments.
// Time: O(n log n)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<tuple<int,int,int>> guests(n);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        guests[i] = {a, b, i};
    }
    sort(guests.begin(), guests.end());

    // multiset of (end_time, room_id)
    multiset<pair<int,int>> rooms;
    vector<int> assign(n);
    int nextRoom = 1, maxRooms = 0;

    for (auto& [a, b, idx] : guests) {
        // Find room that freed up before arrival
        auto it = rooms.begin();
        if (it != rooms.end() && it->first < a) {
            assign[idx] = it->second;
            rooms.erase(it);
        } else {
            assign[idx] = nextRoom++;
        }
        rooms.insert({b, assign[idx]});
        maxRooms = max(maxRooms, (int)rooms.size());
    }

    cout << maxRooms << "\n";
    for (int i = 0; i < n; i++) cout << assign[i] << " \n"[i == n-1];
    return 0;
}
