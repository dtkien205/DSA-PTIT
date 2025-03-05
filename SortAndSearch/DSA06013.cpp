#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int a[n];
        map<int, int> mp;
        for (int& i : a) {
            cin >> i;
            mp[i]++;
        }
        int ans = (mp[x]) ? mp[x] : -1;
        cout << ans << endl;
    }
}