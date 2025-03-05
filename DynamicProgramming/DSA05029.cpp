#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int solve(string s)
{
    int n = s.size();
    if (s[0] == '0')
        return 0;
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    dp[n - 1] = (s[n - 1] != '0') ? 1 : 0;

    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == '0')
            continue;
        dp[i] = dp[i + 1];
        int num = stoi(s.substr(i, 2));
        if (num <= 26)
            dp[i] += dp[i + 2]; 
    }
    return dp[0];
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
}