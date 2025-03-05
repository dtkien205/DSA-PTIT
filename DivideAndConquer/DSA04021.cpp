#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll F[100];

void init()
{
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i <= 92; i++)
        F[i] = F[i - 1] + F[i - 2];
}

int binary(ll n, ll k)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (k <= F[n - 2])
        return binary(n - 2, k);
    else
        return binary(n - 1, k - F[n - 2]);
}

int main()
{
    int t;
    cin >> t;
    init();
    while (t--) {
        ll n, k;
        cin >> n >> k;
        cout << binary(n, k) << endl;
    }
}