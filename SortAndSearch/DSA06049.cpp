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
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        ll res = 0;
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            res += lower_bound(v.begin() + i + 1, v.end(), k + v[i]) - (v.begin() + i + 1);
        }
        cout << res << endl;
    }
}