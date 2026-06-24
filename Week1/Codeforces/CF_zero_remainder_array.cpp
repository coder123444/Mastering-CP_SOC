// CF 1374C - Zero Remainder Array
// Approach: For each element a[i], we need to add (k - a[i]%k) % k to it.
// The answer is 0 if all already divisible, else max over required additions + 1
// (the +1 accounts for the first operation incrementing prefix from 0).
// Time: O(n)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; long long k;
        cin >> n >> k;
        vector<long long> a(n);
        for (auto& x : a) cin >> x;

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long rem = a[i] % k;
            if (rem != 0) {
                long long need = k - rem;
                ans = max(ans, need + (long long)i);
            }
        }
        // If ans > 0, we need one more step for the operation itself
        // Actually ans already counts from position i=0
        // Recheck: we apply val from 0..pos, so for position i we need ops = need+i
        // But we must add 1 because we start counting from operation 1
        if (ans > 0) ans++;
        // Correction: ops needed = need + i means we apply val (need+i) times total,
        // but each operation increments by 1 starting from prefix 0..
        // Simpler: answer is max(need + i) + 1 only if any non-zero rem exists
        // The +1 handles the fact minimum operations = need+i+1 (0-indexed ops)
        // Let's re-derive cleanly:
        // After `ops` operations, prefix[i] = ops - i (if ops > i, else 0)
        // We need (ops - i) % k == (k - a[i]%k) % k
        // => ops % k == (k - a[i]%k + i) % k... complex; simpler direct formula:
        // ops = need + i + 1 (minimum ops so that prefix covers index i with value `need`)
        // => ans = max over all i of (need_i + i + 1), or 0 if all divisible
        // Recompute:
        ans = 0;
        for (int i = 0; i < n; i++) {
            long long rem = a[i] % k;
            if (rem != 0) {
                long long need = k - rem;
                ans = max(ans, need + (long long)i + 1);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
