#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> mp;
        int res = 0, ans;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mp[x]++;
            if (res < mp[x]) {
                res = mp[x];
                ans = x;
            }
        }
        if (res > n / 2)
            cout << ans << endl;
        else
            cout << "NO\n";
    }
}