#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n + 1, 1);
    s = " " + s;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (s[i] >= s[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *max_element(dp.begin() + 1, dp.end());
}