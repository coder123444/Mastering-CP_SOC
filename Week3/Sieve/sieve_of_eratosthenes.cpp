// Sieve of Eratosthenes
// Finds all primes up to N in O(N log log N) time.

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
bool isComposite[MAXN];
vector<int> primes;

void sieve(int n) {
    fill(isComposite, isComposite + n + 1, false);
    isComposite[0] = isComposite[1] = true;
    for (int i = 2; i <= n; i++) {
        if (!isComposite[i]) {
            primes.push_back(i);
            for (long long j = (long long)i * i; j <= n; j += i)
                isComposite[j] = true;
        }
    }
}

// CSES 1163 - Counting Primes
// Count primes in range [a, b]
void countPrimes() {
    long long a, b;
    cin >> a >> b;
    sieve(b);
    int count = 0;
    for (long long i = a; i <= b; i++)
        if (!isComposite[i]) count++;
    cout << count << "\n";
}

// LeetCode 204 - Count Primes
// Count primes strictly less than n
int countPrimesLC(int n) {
    if (n <= 2) return 0;
    vector<bool> comp(n, false);
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (!comp[i]) {
            count++;
            for (long long j = (long long)i * i; j < n; j += i)
                comp[j] = true;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    countPrimes();
    return 0;
}
