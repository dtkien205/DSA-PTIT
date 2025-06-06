#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0), dp(n + 1, 1e9);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i >= j)
                dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
        }
    }
    cout << dp[n];
}