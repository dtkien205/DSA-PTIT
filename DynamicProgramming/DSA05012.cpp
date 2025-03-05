#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int mod = 1e9 + 7;
ll F[1005][1005];

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 && i == j)
                    F[i][j] = 1;
                else
                    F[i][j] = (F[i - 1][j] + F[i - 1][j - 1]) % mod;
            }
        }

        cout << F[n][k] << endl;
    }
}