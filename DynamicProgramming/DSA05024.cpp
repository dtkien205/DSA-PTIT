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
        int n, k;
        cin >> n >> k;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        ll F[k + 1];
        memset(F, 0, sizeof(F));
        F[0] = 1;
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                if (i >= a[j]) {
                    F[i] += F[i - a[j]];
                    F[i] %= mod;
                }
            }
        }
        cout << F[k] << endl;
    }
}