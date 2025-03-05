#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[k + 1];
        map<int, int> mp;
        for (int i = 1; i <= k; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }
        int ans = 0, i = k;
        while (i >= 1 && a[i] == n - k + i)
            i--;
        a[i]++;
        if (i == 0) {
            cout << k << endl;
            continue;
        }
        for (int j = i + 1; j <= k; j++)
            a[j] = a[j - 1] + 1;

        for (int j = 1; j <= k; j++) {
            if (mp[a[j]] == 0)
                ans++;
        }
        cout << ans << endl;
    }
}