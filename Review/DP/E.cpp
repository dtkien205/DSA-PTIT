#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool F[10000][10000];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;

    for (int i = 1; i <= n; i++)
        F[i][i] = true;

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                if (len == 2)
                    F[i][j] = true;
                else
                    F[i][j] = F[i + 1][j - 1];
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (F[l][r] ? "Yes\n" : "No\n");
    }
}