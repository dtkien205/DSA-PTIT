#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int mod = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ll sum = 0;
        sort(a, a + n);
        for (int i = 0; i < n; i++) {
            sum += a[i] * i;
            sum %= mod;
        }
        cout << sum << endl;
    }
}