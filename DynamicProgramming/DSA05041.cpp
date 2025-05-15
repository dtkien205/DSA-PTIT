#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int F[1005][1005];

void solve()
{
    string s;
    cin >> s;
    memset(F, 0, sizeof(F));
    int n = s.size();
    s = " " + s;

    for (int i = 1; i <= n; i++)
        F[i][i] = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            if (s[i] == s[j])
                F[i][j] = F[i + 1][j - 1] + 2;
            else
                F[i][j] = max(F[i + 1][j], F[i][j - 1]);
        }
    }
    cout << n - F[1][n] << endl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
}