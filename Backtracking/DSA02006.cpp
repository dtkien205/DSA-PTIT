#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, s, a[20], x[20], ok;

void Try(int i, int bd, int sum)
{
    for (int j = bd; j <= n; j++) {
        if (sum + a[j] <= s) {
            x[i] = a[j];
            if (sum + a[j] == s) {
                ok = 1;
                cout << '[';
                for (int u = 1; u <= i; u++) {
                    cout << x[u];
                    if (u != i)
                        cout << ' ';
                }
                cout << "] ";
            } else
                Try(i + 1, j + 1, sum + a[j]);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        ok = 0;
        sort(a + 1, a + n + 1);
        Try(1, 1, 0);
        if (!ok)
            cout << "-1";
        cout << endl;
    }
}