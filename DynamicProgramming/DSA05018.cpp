#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool F[1005][1005];

void solve()
{
    string s;
    cin >> s;
    memset(F, 0, sizeof(F));
    int n = s.size();
    s = " " + s;

    for (int i = 1; i <= n; i++)
        F[i][i] = 1;
    int res = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            if (len == 2)
                F[i][j] = (s[i] == s[j]);
            else
                F[i][j] = (s[i] == s[j]) && F[i + 1][j - 1];

            if (F[i][j])
                res = max(res, len);
        }
    }
    cout << res << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}