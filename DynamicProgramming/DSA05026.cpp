#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int c, n;
    cin >> c >> n;
    int w[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    ll F[n + 1][c + 1];
    memset(F, 0, sizeof(F));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= c; j++) {
            if (j >= w[i])
                F[i][j] = fmax(F[i - 1][j - w[i]] + w[i], F[i - 1][j]);
            else
                F[i][j] = F[i - 1][j];
        }
    }
    cout << F[n][c] << endl;
}