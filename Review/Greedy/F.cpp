#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int a[n + 1];
    int max1 = 0, max2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        max1 = max(max1, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (max2 < a[i] && a[i] < max1)
            max2 = a[i];
    }

    cout << (n == 1 ? 0 : max2);
}