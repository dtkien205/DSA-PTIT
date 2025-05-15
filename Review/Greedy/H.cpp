#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mp[x % k]++;
    }
    int res = 0;
    for (int i = 1; i <= k / 2; i++) {
        if (i < k - i)
            res += max(mp[i], mp[k - i]);
        else if (mp[k / 2]) res++;
    }
    if(mp[0]) res++;
    cout << res << endl;
}