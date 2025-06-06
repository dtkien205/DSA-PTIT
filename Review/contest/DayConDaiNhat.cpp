// TN01024
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        double a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i] >> b[i];

        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j] && b[i] < b[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << endl;
    }
}