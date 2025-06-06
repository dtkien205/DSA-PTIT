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
        int N, X, Y, Z;
        cin >> N >> X >> Y >> Z;

        vector<int> dp(N + 1, 0);
        for (int i = 1; i <= N; ++i) {
            dp[i] = dp[i - 1] + X;
            if (i % 2 == 0)
                dp[i] = min(dp[i], dp[i / 2] + Z);
            else
                dp[i] = min(dp[i], dp[(i + 1) / 2] + Y + Z);
        }

        cout << dp[N] << '\n';
    }
}