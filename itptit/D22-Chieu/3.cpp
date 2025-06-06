#include <bits/stdc++.h>
using namespace std;

int a[200005], n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int len = 1; len <= n; ++len) {
        int maxMin = INT_MIN;
        for (int i = 1; i <= n - len + 1; ++i) {
            int curMin = a[i];
            for (int j = i + 1; j < i + len; ++j) {
                curMin = min(curMin, a[j]);
            }
            maxMin = max(maxMin, curMin);
        }
        cout << maxMin << ' ';
    }
    cout << '\n';
}
