#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    set<int> se;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        se.insert(x);
    }
    vector<int> v(se.begin(), se.end());

    while (q--) {
        int x;
        cin >> x;
        auto l = lower_bound(v.begin(), v.end(), x) - v.begin();
        auto r = upper_bound(v.begin(), v.end(), x) - v.begin();

        cout << (l != 0 ? v[l - 1] : 0) << ' ' << (r == n ? 0 : v[r]) << endl;
    }
}