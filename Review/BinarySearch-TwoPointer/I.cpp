#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int mp[1000000 + 5], cnt = 0;
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll n, k;
    cin >> n >> k;
    ll a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    ll res = 0, l = 1;
    for (int r = 1; r <= n; r++) {
        mp[a[r]]++;
        if (mp[a[r]] == 1)
            cnt++;
        while (cnt > k && l <= r) {
            mp[a[l]]--;
            if (mp[a[l]] == 0)
                cnt--;
            l++;
        }
        res += r - l + 1;
    }
    cout << res << endl;
}
