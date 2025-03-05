#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll F[100];

void init()
{
    F[0] = 1;
    for (int i = 1; i <= 63; i++)
        F[i] = F[i - 1] * 2;
}

ll res(ll n, ll k)
{
    while (n > 0) {
        if (k == F[n - 1])
            return n;
        if (k > F[n - 1])
            k -= F[n - 1];
        n--;
    }
    return 1;
}

int main()
{
    int t;
    cin >> t;
    init();
    while (t--) {
        ll n, k;
        cin >> n >> k;
        cout << res(n, k) << endl;
    }
}