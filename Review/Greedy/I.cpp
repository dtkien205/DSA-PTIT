#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    int x = a[(n + 1) / 2], y = b[(n + 1) / 2];
    ll res = 0;
    for (int i = 1; i <= n; i++)
        res += abs(x - a[i]) + abs(y - b[i]);
    cout << res << endl;
}