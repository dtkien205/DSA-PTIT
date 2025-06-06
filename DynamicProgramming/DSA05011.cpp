#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int MOD = 1e9 + 7;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int d = 1; d <= 9 && d <= k; ++d)
            dp[1][d] = 1;

        for (int i = 2; i <= n; ++i)
            for (int s = 0; s <= k; ++s)
                for (int d = 0; d <= 9 and s - d >= 0; ++d)
                    (dp[i][s] += dp[i - 1][s - d]) %= MOD;
        cout << dp[n][k] << endl;
    }
}