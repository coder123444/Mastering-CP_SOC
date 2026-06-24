// Euler's Totient Function φ(n)
// φ(n) = count of integers in [1, n] that are coprime to n.
// Formula: φ(n) = n * ∏(1 - 1/p) for each prime p dividing n
// Time: O(sqrt(n)) per query, O(N log log N) for sieve version

#include <bits/stdc++.h>
using namespace std;

// Single value
long long eulerTotient(long long n) {
    long long result = n;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            result -= result / p;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}

// Sieve version for all values 1..N
vector<long long> totientSieve(int n) {
    vector<long long> phi(n + 1);
    iota(phi.begin(), phi.end(), 0);
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) { // i is prime
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
}

// CSES - Euler's Totient Function
void csesTotient() {
    int n; cin >> n;
    while (n--) {
        long long x; cin >> x;
        cout << eulerTotient(x) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    csesTotient();
    return 0;
}
