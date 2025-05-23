#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int F[105][105];

int main()
{
    int test;
    cin >> test;
    while (test--) {
        string s, t;
        cin >> s >> t;
        int n = s.length(), m = t.length();
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = i + j;
                else if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
        cout << dp[n][m] << endl;
    }
}