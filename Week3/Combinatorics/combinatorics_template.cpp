// Combinatorics - nCr with Modular Arithmetic
// Precompute factorials and inverse factorials using Fermat's little theorem.
// Time: O(N) precomputation, O(1) per query

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

long long fact[MAXN], inv_fact[MAXN];

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

void precompute(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % MOD;
    inv_fact[n] = power(fact[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; i--) inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
}

long long C(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] % MOD * inv_fact[r] % MOD * inv_fact[n-r] % MOD;
}

// CSES 1079 - Binomial Coefficients
void binomialCoefficients() {
    precompute(MAXN - 1);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        cout << C(n, k) << "\n";
    }
}

// CSES 1716 - Distributing Apples
// Distribute n apples to k children (stars and bars): C(n+k-1, k-1)
void distributingApples() {
    precompute(MAXN - 1);
    long long n, k; cin >> n >> k;
    cout << C(n + k - 1, k - 1) << "\n";
}

// CSES 1717 - Christmas Party
// Derangement: D(n) = (n-1)*(D(n-1) + D(n-2))
void christmasParty() {
    precompute(MAXN - 1);
    int n; cin >> n;
    vector<long long> D(n + 1, 0);
    D[0] = 1; D[1] = 0;
    for (int i = 2; i <= n; i++)
        D[i] = (long long)(i-1) * ((D[i-1] + D[i-2]) % MOD) % MOD;
    cout << D[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Uncomment relevant function:
    binomialCoefficients();
    // distributingApples();
    // christmasParty();

    return 0;
}
