#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll getLength(ll n)
{
    if (n == 0 || n == 1)
        return 1;
    return 2 * getLength(n / 2) + 1;
}

void get_bits(ll n, ll l, ll r, ll left, ll right, vector<int>& res)
{
    if (n == 0 || n == 1) {
        if (l <= left && right <= r)
            res.push_back(n);
        return;
    }

    ll mid = left + getLength(n / 2);
    ll len = getLength(n / 2);

    // Left part
    if (l <= mid - 1 && r >= left)
        get_bits(n / 2, l, r, left, mid - 1, res);

    // Middle bit
    if (l <= mid && mid <= r)
        res.push_back(n % 2);

    // Right part
    if (l <= right && r >= mid + 1)
        get_bits(n / 2, l, r, mid + 1, right, res);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        ll n, l, r;
        cin >> n >> l >> r;
        vector<int> res;
        ll total = getLength(n);
        get_bits(n, l, r, 1, total, res);
        ll cnt = 0;
        for (int x : res)
            if (x == 1)
                cnt++;
        cout << cnt << endl;
    }
}