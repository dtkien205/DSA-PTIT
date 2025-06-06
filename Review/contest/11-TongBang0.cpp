#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<ll> a(n + 1, 0), prefix(n + 1, 0);
    map<int, int> cnt;
    ll res = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }

    for (int i = 0; i <= n; i++) {
        if (cnt[prefix[i]])
            res += cnt[prefix[i]];
        cnt[prefix[i]]++;
    }

    cout << res << endl;
}