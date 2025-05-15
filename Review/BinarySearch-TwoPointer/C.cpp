#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    int a[n + 1], b[m + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    for (int i = 1; i <= m; i++) {
        auto x = lower_bound(a + 1, a + n + 1, b[i]) - (a + 1);
        cout << x << ' ';
    }
}