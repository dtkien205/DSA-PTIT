#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        int n, k;
        cin >> n >> k;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        int res = a[k] - a[1];
        for (int i = 1; i <= n - k; i++) {
            res = min(res, a[k + i] - a[i + 1]);
        }
        cout << res << endl;
    }
}