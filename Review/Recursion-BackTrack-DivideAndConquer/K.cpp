#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll f[100];
void init()
{
    f[1] = f[2] = 1;
    for (int i = 3; i <= 90; i++)
        f[i] = f[i - 1] + 1 + f[i - 2];
}

char res(ll n, ll k)
{
    if (n == 1)
        return 'L';
    if (n == 2)
        return 'V';
    if (k <= f[n - 1])
        return res(n - 1, k);
    else if (k == f[n - 1] + 1)
        return (n % 2 ? 'L' : 'V');
    else
        return res(n - 2, k - 1 - f[n - 1]);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    init();
    int test;
    cin >> test;
    while (test--) {
        ll n, k;
        cin >> n >> k;
        cout << res(n, k) << endl;
    }
}