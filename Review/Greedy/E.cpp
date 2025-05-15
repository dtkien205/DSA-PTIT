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
        ll res = 0;
        int b[n + 1], idx = 1;
        for (int i = 1; i <= k; i++) {
            for (int j = i; j <= n; j += k)
                b[j] = a[idx++];
        }
        for (int i = 1; i <= n - k; i++)
            res += abs(b[i] - b[i + k]);
        cout << res << endl;
    }
}