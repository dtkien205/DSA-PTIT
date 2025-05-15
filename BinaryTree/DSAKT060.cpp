#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;
    int q;
    cin >> q;
    while (q--) {
        char c, x;
        int l, r, u;
        cin >> c;
        if (c == 'q') {
            cin >> l >> r;
            string tmp = s;
            reverse(tmp.begin() + l - 1, tmp.begin() + r);
            cout << (tmp == s ? "YES" : "NO") << endl;
        } else {
            cin >> u >> x;
            s[u - 1] = x;
        }
    }
}