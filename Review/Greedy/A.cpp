#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    ll res = 0;
    for (int i = 1; i <= n / 2; i++)
        res -= a[i];
    for (int i = n / 2 + 1; i <= n; i++)
        res += a[i];
    cout << abs(res);
}