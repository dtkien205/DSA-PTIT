#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int mod = 1e9 + 7;
ll F[1000005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    F[0] = F[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i >= j) {
                F[i] += F[i - j] % mod;
                F[i] %= mod;
            }
        }
    }

    cout << F[n];
}