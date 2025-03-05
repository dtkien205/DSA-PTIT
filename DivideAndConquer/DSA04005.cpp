#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll F[100];

void init()
{
    F[1] = F[2] = 1;
    for (int i = 2; i <= 93; i++)
        F[i] = F[i - 1] + F[i - 2];
}

char res(ll n, ll k)
{
    if (n == 1)
        return 'A';
    if (n == 2)
        return 'B';
    if (k <= F[n - 2])
        return res(n - 2, k);
    else
        return res(n - 1, k - F[n - 2]);
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