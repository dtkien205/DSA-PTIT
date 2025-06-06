#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n;
int a[1005];
ll dp[1005][1005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            if (i == j)
                dp[i][j] = a[i];
            else
                dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
        }
    }

    ll total = accumulate(a, a + n, 0);
    ll ti = (total + dp[0][n - 1]) / 2;
    ll teo = total - ti;

    cout << ti << " " << teo << "\n";
}