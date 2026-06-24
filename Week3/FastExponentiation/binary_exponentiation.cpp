// Binary Exponentiation (Fast Power)
// Computes base^exp % mod in O(log exp) time.
// Core idea: if exp is even, base^exp = (base^(exp/2))^2
//            if exp is odd,  base^exp = base * base^(exp-1)

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

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

// CSES 1712 - Exponentiation II: compute a^(b^c) % MOD
// Trick: b^c % (MOD-1) by Fermat's little theorem (since MOD is prime)
void exponentiationII() {
    int n; cin >> n;
    while (n--) {
        long long a, b, c;
        cin >> a >> b >> c;
        long long exp = power(b, c, MOD - 1);
        cout << power(a, exp, MOD) << "\n";
    }
}

// CF 742A - Arpa's letter-marked tree and Mehrdad's Dokhtar-kosh paths
// (Fast exponentiation warmup)
void cf742A() {
    // This problem uses basic power computation
    long long n; cin >> n;
    cout << power(2, n, MOD) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // CSES Exponentiation II
    exponentiationII();

    // CF 742A
    // cf742A();

    return 0;
}
