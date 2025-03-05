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
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans;
        for (int i = 0; i < n; i++) {
            if (a[i] == x)
                ans = i + 1;
        }
        cout << ans << endl;
    }
}