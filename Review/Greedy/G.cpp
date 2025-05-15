#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> v;
    ll res = 0;
    for (int i = 1; i <= 2 * n; i++) {
        int x, y;
        cin >> x >> y;
        res += x;
        v.push_back(x - y);
    }
    sort(v.begin(), v.end(), greater<>());
    for (int i = 0; i < n; i++)
        res -= v[i];
    cout << res << endl;
}