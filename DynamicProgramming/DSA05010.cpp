#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n + 5], F[n + 5][105] = {};
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] %= k;
        }
        for (int i = 0; i < k; i++)
            F[1][i] = INT_MIN;
        F[1][a[1]] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 0; j < k; j++)
                F[i][j] = max(F[i - 1][j], F[i - 1][(j - a[i] + k) % k] + 1); //(j -a[i]) cong them k de dam bao no khong am
        cout << F[n][0] << endl;
    }
}