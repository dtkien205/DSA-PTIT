#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, test;
    cin >> n >> test;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (test--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            cout << (binary_search(a + 1, a + n + 1, x) ? "YES" : "-1") << endl;
        } else if (t == 2) {
            auto k = lower_bound(a + 1, a + n + 1, x) - a;
            cout << ((k <= n && a[k] == x) ? k : -1) << endl;
        } else {
            auto k = upper_bound(a + 1, a + n + 1, x) - a - 1;
            cout << ((k <= n && a[k] == x) ? k : -1) << endl;
        }
    }
}