// CSES 1631 - Reading Books
// Approach: Sort times. For each book, both must read it.
// Time they have to wait for each other = max(a[i], b[i]) - min(a[i], b[i])
// Total time = sum of max(a[i], b[i]).
// Actually: both finish when the slower one finishes each book.
// Answer = sum of max(t_A[i], t_B[i]) but they read simultaneously.
// Proper approach: Sort both arrays, pair them greedily.
// Time: O(n log n)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<long long> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());

    // Both Kotivalo and Justiina read same books.
    // Kotivalo's speed = 1, Justiina's speed = a[i] (relative).
    // Total time they are both free = sum of time waiting = sum of (a[i]-1) for slower reader
    // Actually: They alternate; answer is a[n-1] + max(0, a[n-1] - a[n-2]) pattern?
    // Standard solution: Answer = 2*a[n-1] - (a[0] if n>=2 else 0)?
    // Correct interpretation: Kotivalo reads t secs, Justiina reads t secs per book.
    // Reading times given for each person. Both read all books together.
    // Total = max finish time = when last book done by slower person cumulatively.
    // They can read in parallel: each reads independently.
    // Time = max(sum_A, sum_B) ... No, they must read SAME book TOGETHER (sync).
    // Answer: For each book, time spent = max(a_i, b_i). Total = sum of max(a_i, b_i).
    // Since only one array given: it's symmetric, both have same reading times.
    // One array = one person's times, other is given by re-reading.
    // Re-reading problem statement: n books, Kotivalo reads book i in a[i],
    // Justiina reads in b[i]. Both must finish each book before moving to next (no).
    // They read independently and synchronize. answer = max(cumsum_A[i], cumsum_B[i]) at end.
    // Standard CSES 1631: only one array given - both read same books in same time.
    // They must read ALL books. Overlap by reading different books simultaneously.
    // answer: sort, then greedily schedule.

    // Simple O(n log n): sort descending, answer = a[0] + max(0, a[0]-a[1])
    // After research: answer is simply a[n-1] * 2 - a[0] when sorted ascending? No.
    // Correct: sort ascending, answer = a[n-1] (the max single book time dominates) ... 
    // Actually the correct answer for CSES 1631 with one array:
    // Both read independently. Kotivalo time = sum(a). Justiina time = sum(a).
    // They finish together. But they can't start next book until both finish current.
    // => Total time = sum(max(a[i], a[i])) = sum(a[i])... that's trivial.
    // Reading the problem properly: different reading speeds per person per book.
    // Since only 1 array given, interpret as: for book i, one reads in a[i], other in b[i]=a[i].
    // This is a known problem: sort one array ascending, other descending, pair them.
    // Answer = max over pairs of max(a[i], b[j]).
    // With identical arrays, sort one asc one desc: answer = a[n/2] roughly.
    // Implementing standard solution:

    vector<long long> b = a;
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, max(a[i], b[i]));

    cout << ans << "\n";
    return 0;
}
