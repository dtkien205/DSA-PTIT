// TN01021
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, k;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> k;
        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= k; j++)
                if (i >= j)
                    dp[i] += dp[i - j];

        cout << dp[n] << endl;
    }
}