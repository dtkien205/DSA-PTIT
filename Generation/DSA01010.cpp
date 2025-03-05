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
        map<int, int> mp;
        int a[k + 1];
        for (int i = 1; i <= k; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }

        // sinh
        int i = k;
        while (i >= 1 && a[i] == n - k + i)
            i--;
        a[i]++;
        for (int j = i + 1; j <= k; j++)
            a[j] = a[j - 1] + 1;
        int res = 0;
        for (int j = 1; j <= k; j++) {
            if (!mp[a[j]])
                res++;
        }
        cout << res << endl;
    }
}