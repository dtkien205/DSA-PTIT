#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int mod = 1e9 + 7;
ll F[1000][1000];

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(F, 0, sizeof(F));

        for (int i = 0; i <= n + 9; i++) {
            for (int j = 0; j <= n + 9; j++) {
                if (i == 0 || i == j)
                    F[i][j] = 1;
                else
                    F[i][j] = (F[i - 1][j] + F[i - 1][j - 1]) % mod;
            }
        }
        cout << F[n + 9][n] << endl;
    }
}