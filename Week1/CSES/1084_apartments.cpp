// CSES 1084 - Apartments
// Approach: Sort both arrays. Greedily match each applicant to the
// smallest apartment within their tolerance range.
// Time: O(n log n + m log m) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0, count = 0;
    while (i < n && j < m) {
        if (b[j] >= a[i] - k && b[j] <= a[i] + k) {
            count++;
            i++; j++;
        } else if (b[j] < a[i] - k) {
            j++;
        } else {
            i++;
        }
    }

    cout << count << "\n";
    return 0;
}
