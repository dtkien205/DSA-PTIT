#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, u, v;
    cin >> n >> u >> v;
    vector<int> a(n + 1, 0);
    vector<ll> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
        // cout << prefix[i] << ' ';
    }

    ll mx = 0;
    for (int len = u; len <= v; len++) {
        for (int i = len; i <= n; i++) {
            ll sum = prefix[i] - prefix[i - len];
            mx = max(mx, sum);
        }
    }
    cout << mx;
}