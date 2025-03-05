#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll dp[n + 1] = { 0 };
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                if (i >= j)
                    dp[i] += dp[i - j];
            }
        }
        cout << dp[n] << endl;
    }
}