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
        vector<int> a(n), prefixSum(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i == 0)
                prefixSum[i] = a[i];
            else
                prefixSum[i] = a[i] + prefixSum[i - 1];
        }
        int res = 0;
        bool check = false;
        for (int i = 1; i < n - 1; i++) {
            // cout << prefixSum[i - 1] << ' ' << prefixSum[n - 1] - prefixSum[i] << endl;
            if (prefixSum[i - 1] == prefixSum[n - 1] - prefixSum[i]) {
                res = i + 1;
                check = true;
            }
        }
        if (check)
            cout << res << endl;
        else
            cout << "-1\n";
    }
}