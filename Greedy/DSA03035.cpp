#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

// tìm dãy con tăng dần dài nhất

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 5, 0);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        dp[x] = dp[x - 1] + 1;
    }
    cout << n - *max_element(dp.begin(), dp.end());
}