#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ll n;
    cin >> n;
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        mp[u] += 1;
        mp[v + 1] -= 1;
    }
    int q;
    cin >> q;
    vector<int> Q(q);
    for (int i = 0; i < q; ++i) {
        cin >> Q[i];
        mp[Q[i]] += 0;
    }

    map<int, int> prefix;
    int cur = 0;
    for (auto [pos, val] : mp) {
        cout << pos << ' ' << val << endl;
        cur += val;
        prefix[pos] = cur;
    }
    cout << endl;
    for (auto [pos, val] : prefix) {
        cout << pos << ' ' << val << endl;
    }

    // for (int c : Q) {
    //     auto it = prefix.upper_bound(c);
    //     if (it == prefix.begin()) {
    //         cout << 0 << endl;
    //     } else {
    //         --it;
    //         cout << it->second << endl;
    //     }
    // }
}
