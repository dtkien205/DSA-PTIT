#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int search(vector<ll> a, int n, int x)
{
    int l = 0, r = n - 1;
    int ans = -2;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] > x)
            r = m - 1;
        else {
            ans = m;
            l = m + 1;
        }
    }
    return ans + 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        cout << search(a, n, x) << endl;
    }
}