#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    ll a[n];
    map<ll, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (mp[a[i]] > 1) {
            cout << a[i] << endl;
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}