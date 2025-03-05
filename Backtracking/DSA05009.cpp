#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, a[105], x[105], ok;
ll s;

void Try(int i, int bd, int sum)
{
    if (ok)
        return;
    for (int j = bd; j < n; j++) {
        if (sum + a[j] <= s) {
            x[i] = a[j];
            if (sum + a[j] == s) {
                ok = 1;
                return;
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
        cin >> n;
        s = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        if (s % 2) {
            cout << "NO" << endl;
            continue;
        }
        s /= 2;
        // cout << s << endl;
        ok = 0;
        Try(0, 0, 0);
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}