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
        int F[n + 5];
        memset(F, 0, sizeof(F));
        F[1] = 1;
        for (int i = 2; i <= n; i++) {
            F[i] = i;
            for (int j = 1; j <= sqrt(i); j++)
                F[i] = min(F[i], 1 + F[i - j * j]);
        }
        cout << F[n] << endl;
    }
}