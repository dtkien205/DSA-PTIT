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
        int F[n + 1];
        memset(F, 0, sizeof(F));
        F[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                if (i >= j) {
                    F[i] += F[i - j];
                    F[i] %= mod;
                }
            }
        }
        cout << F[n] << endl;
    }
}