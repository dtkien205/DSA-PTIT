#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll n, s;
    cin >> n >> s;
    ll a[n + 1], pre[n + 1] = {};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    ll res = 0, sum = 0, l = 1;
    for (int r = 1; r <= n; r++) {
        sum += a[r];
        while (sum > s && l <= r) {
            sum -= a[l];
            l++;
        }
        res += r - l + 1;
    }
    cout << res;
}
