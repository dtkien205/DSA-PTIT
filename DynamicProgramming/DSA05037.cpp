#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll F[120][120];
const int mod = 1e9 + 7;

void init()
{
    for (int i = 1; i <= 110; i++) {
        for (int j = 1; j <= 110; j++) {
            if (j == 1 || i == j)
                F[i][j] = 1;
            else
                F[i][j] = F[i - 1][j - 1] + F[i - 1][j];
            F[i][j] %= mod;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    init();
    while (t--) {
        int n;
        cin >> n;
        cout << F[9 + n + 1][n + 1] << endl;
    }
}