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
        int a[n + 1];
        ll F[n + 1];
        memset(F, 0, sizeof(F));
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        F[1] = a[1];
        for (int i = 2; i <= n; i++)
            F[i] = max(F[i - 1], F[i - 2] + a[i]);
        cout << F[n] << endl;
    }
}