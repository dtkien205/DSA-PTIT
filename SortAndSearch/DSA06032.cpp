#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= k)
                break;
            for (int j = i + 1; j < n; j++) {
                auto it = lower_bound(a + j + 1, a + n, k - a[i] - a[j]);
                cnt += it - a - j - 1;
            }
        }
        cout << cnt << endl;
    }
}