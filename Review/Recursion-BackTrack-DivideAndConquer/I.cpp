#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve1()
{
    int n, j, k;
    cin >> n >> j >> k;
    int a[n + 1], p[n + 1] = { 0 };
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }

    for (int i = 1; i <= j; i++) {
        if (p[j] - p[i - 1] <= k) {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}

void solve2()
{
    int n, j, k;
    cin >> n >> j >> k;
    int a[n + 1], p[n + 1] = { 0 };
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }

    int l = 1, r = j, i = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (p[j] - p[m - 1] <= k) {
            i = m;
            r = m - 1;
        } else
            l = m + 1;
    }
    cout << i << endl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        solve2();
    }
}