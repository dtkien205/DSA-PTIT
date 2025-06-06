// TN01025
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        string s;
        cin >> s;
        int n = s.size();
        s = " " + s;
        vector<ll> dp(n + 1, 0);
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] * 10 + (s[i] - '0') * i;
            sum += dp[i];
        }

        cout << sum << endl;
    }
}