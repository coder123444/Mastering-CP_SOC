// CSES Dynamic Programming Problems
// Covers: Dice Combinations, Minimizing Coins, Coin Combinations I & II,
//         Removing Digits, Grid Paths, Book Shop, Array Description,
//         Edit Distance, Rectangle Cutting, Money Sums, Counting Towers,
//         Counting Numbers, Longest Common Subsequence, Longest Increasing Subsequence

#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

// ============================================================
// CSES 1633 - Dice Combinations
// Count ways to get sum n by rolling dice (faces 1-6), order matters.
// dp[i] = sum of dp[i-1..i-6], dp[0]=1
// ============================================================
void diceCombinations() {
    int n; cin >> n;
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 6 && j <= i; j++)
            dp[i] = (dp[i] + dp[i-j]) % MOD;
    cout << dp[n] << "\n";
}

// ============================================================
// CSES 1634 - Minimizing Coins
// Minimum number of coins to make sum n.
// dp[i] = min coins to form sum i
// ============================================================
void minimizingCoins() {
    int n, x; cin >> n >> x;
    vector<int> c(n);
    for (int& coin : c) cin >> coin;
    vector<long long> dp(x + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
        for (int coin : c)
            if (coin <= i && dp[i - coin] != INF)
                dp[i] = min(dp[i], dp[i - coin] + 1);
    cout << (dp[x] == INF ? -1 : dp[x]) << "\n";
}

// ============================================================
// CSES 1635 - Coin Combinations I (order matters)
// Count ways to form sum x using coins (repetition allowed, order matters).
// ============================================================
void coinCombinationsI() {
    int n, x; cin >> n >> x;
    vector<int> c(n);
    for (int& coin : c) cin >> coin;
    vector<long long> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; i++)
        for (int coin : c)
            if (coin <= i)
                dp[i] = (dp[i] + dp[i - coin]) % MOD;
    cout << dp[x] << "\n";
}

// ============================================================
// CSES 1636 - Coin Combinations II (order doesn't matter)
// Classic 0/1 knapsack variant: iterate coins in outer loop.
// ============================================================
void coinCombinationsII() {
    int n, x; cin >> n >> x;
    vector<int> c(n);
    for (int& coin : c) cin >> coin;
    vector<long long> dp(x + 1, 0);
    dp[0] = 1;
    for (int coin : c)
        for (int i = coin; i <= x; i++)
            dp[i] = (dp[i] + dp[i - coin]) % MOD;
    cout << dp[x] << "\n";
}

// ============================================================
// CSES 1637 - Removing Digits
// Minimum steps to reduce n to 0 by subtracting one of its digits.
// BFS / DP: dp[i] = 1 + min(dp[i - digit] for each digit of i)
// ============================================================
void removingDigits() {
    int n; cin >> n;
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int temp = i;
        while (temp > 0) {
            int d = temp % 10;
            if (d > 0 && dp[i - d] != INT_MAX)
                dp[i] = min(dp[i], dp[i - d] + 1);
            temp /= 10;
        }
    }
    cout << dp[n] << "\n";
}

// ============================================================
// CSES 1638 - Grid Paths
// Count paths in n x n grid with obstacles from (1,1) to (n,n).
// Move only right or down.
// ============================================================
void gridPaths() {
    int n; cin >> n;
    vector<string> grid(n);
    for (auto& row : grid) cin >> row;
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    dp[0][0] = (grid[0][0] == '.') ? 1 : 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            if (grid[i][j] == '*') { dp[i][j] = 0; continue; }
            if (i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
        }
    cout << dp[n-1][n-1] << "\n";
}

// ============================================================
// CSES 1639 - Book Shop (0/1 Knapsack)
// Maximize pages within budget x.
// dp[j] = max pages achievable with budget j
// ============================================================
void bookShop() {
    int n, x; cin >> n >> x;
    vector<int> h(n), s(n);
    for (int& price : h) cin >> price;
    for (int& pages : s) cin >> pages;
    vector<long long> dp(x + 1, 0);
    for (int i = 0; i < n; i++)
        for (int j = x; j >= h[i]; j--)
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
    cout << dp[x] << "\n";
}

// ============================================================
// CSES 1746 - Array Description
// Count arrays matching constraints (known values, adjacent diff <= 1)
// dp[i][v] = ways to have value v at position i
// ============================================================
void arrayDescription() {
    int n, m; cin >> n >> m;
    vector<int> x(n);
    for (int& v : x) cin >> v;
    vector<vector<long long>> dp(n, vector<long long>(m + 2, 0));
    if (x[0] == 0) for (int v = 1; v <= m; v++) dp[0][v] = 1;
    else dp[0][x[0]] = 1;
    for (int i = 1; i < n; i++) {
        int lo = (x[i] == 0 ? 1 : x[i]);
        int hi = (x[i] == 0 ? m : x[i]);
        for (int v = lo; v <= hi; v++)
            dp[i][v] = (dp[i-1][v-1] + dp[i-1][v] + dp[i-1][v+1]) % MOD;
    }
    long long ans = 0;
    for (int v = 1; v <= m; v++) ans = (ans + dp[n-1][v]) % MOD;
    cout << ans << "\n";
}

// ============================================================
// CSES 1641 - Edit Distance (Classic DP)
// Min operations (insert, delete, replace) to convert s to t.
// dp[i][j] = edit distance of s[0..i-1] and t[0..j-1]
// ============================================================
void editDistance() {
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    cout << dp[n][m] << "\n";
}

// ============================================================
// CSES 1644 - Longest Common Subsequence
// dp[i][j] = LCS length of s[0..i-1] and t[0..j-1]
// ============================================================
void longestCommonSubsequence() {
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    cout << dp[n][m] << "\n";
    // Reconstruct
    string lcs = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s[i-1] == t[j-1]) { lcs += s[i-1]; i--; j--; }
        else if (dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs << "\n";
}

// ============================================================
// CSES 1645 - Longest Increasing Subsequence
// O(n log n) using patience sorting / binary search
// ============================================================
void longestIncreasingSubsequence() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    vector<int> tails;
    for (int x : a) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    cout << tails.size() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Uncomment the function for the problem you're solving:
    // diceCombinations();
    // minimizingCoins();
    // coinCombinationsI();
    // coinCombinationsII();
    // removingDigits();
    // gridPaths();
    // bookShop();
    // arrayDescription();
    // editDistance();
    // longestCommonSubsequence();
    // longestIncreasingSubsequence();

    return 0;
}
