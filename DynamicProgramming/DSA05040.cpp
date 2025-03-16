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
        int a[n + 1] = {}, L[n + 1] = {}, R[n + 2] = {};
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++) {
            L[i] = 1;
            if (a[i] > a[i - 1])
                L[i] = L[i - 1] + 1;
        }
        for (int i = n; i >= 1; i--) {
            R[i] = 1;
            if (a[i] > a[i + 1])
                R[i] = R[i + 1] + 1;
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
            res = max(res, L[i] + R[i] - 1);
        cout << res << endl;
    }
}