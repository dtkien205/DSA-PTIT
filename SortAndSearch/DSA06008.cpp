#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int count(int x, vector<int>& y, int cnt[])
{
    if (x == 0)
        return 0;
    if (x == 1)
        return cnt[0];

    auto upper = upper_bound(y.begin(), y.end(), x);
    ll res = y.end() - upper; // so luong lon hon x trong vector y
    res += cnt[0] + cnt[1];

    if (x == 2)
        res -= cnt[3] + cnt[4];
    if (x == 3)
        res += cnt[2];
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> x(n), y(m);
        int cnt[5] = { 0 };
        for (int i = 0; i < n; i++)
            cin >> x[i];
        for (int i = 0; i < n; i++) {
            cin >> y[i];
            if (y[i] < 5)
                cnt[y[i]]++;
        }
        sort(y.begin(), y.end());

        ll res = 0;
        for (int i = 0; i < n; i++)
            res += count(x[i], y, cnt);
        cout << res << endl;
    }
}