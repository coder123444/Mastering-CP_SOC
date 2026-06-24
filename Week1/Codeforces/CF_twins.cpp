// CF 318B - Twins
// Approach: Sort descending, greedily take coins until first person has > half total.
// Time: O(n log n)

#include <bits/stdc++.h>
using namespace std;

void twins() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    long long total = 0;
    for (int x : a) total += x;
    sort(a.rbegin(), a.rend());
    long long sum = 0;
    int count = 0;
    for (int x : a) {
        sum += x;
        count++;
        if (sum * 2 > total) break;
    }
    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    twins();
    return 0;
}
