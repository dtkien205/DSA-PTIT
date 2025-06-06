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
        int n;
        cin >> n;

        vector<pair<int, int>> v(n);
        for (auto& [x, y] : v)
            cin >> x >> y;

        sort(v.begin(), v.end());

        vector<int64_t> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                auto [a, b] = v[j];
                auto [c, d] = v[i];
                if (b < c)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << endl;
    }
}