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
        ll a[n], b[n], sum = 0;
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;
        sort(a, a + n);
        sort(b, b + n, greater<int>());
        for (int i = 0; i < n; i++)
            sum += a[i] * b[i];
        cout << sum << endl;
    }
}