#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int mod = 1e9 + 7;
int n, k;
ll F[1005][1005];

void init()
{
    for (int i = 1; i <= 1000; i++)
        F[i][1] = i;
    for (int i = 2; i <= 1000; i++)
        for (int j = 2; j <= 1000; j++)
            F[i][j] = i * F[i - 1][j - 1] % mod;
}

int main()
{
    int t;
    cin >> t;
    init();
    while (t--) {
        cin >> n >> k;
        cout << F[n][k] << endl;
    }
}