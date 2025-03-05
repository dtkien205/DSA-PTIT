#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, a[20], tmp[20], used[20] = { 0 }, res;
bool ok;

void check()
{
    res++;
    for (int i = 1; i <= n; i++) {
        if (tmp[i] != a[i])
            return;
    }
    ok = true;
}

void Try(int i)
{
    if (ok)
        return;
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            a[i] = j;
            used[j] = 1;
            if (i == n)
                check();
            else
                Try(i + 1);
            used[j] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        res = 0, ok = false;
        for (int i = 1; i <= n; i++)
            cin >> tmp[i];
        Try(1);
        cout << res << endl;
    }
}