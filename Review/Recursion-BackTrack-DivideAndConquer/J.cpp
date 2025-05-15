#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int f[50], len[50];

void init()
{
    f[0] = 1, f[1] = 0;
    len[0] = len[1] = 1;
    for (int i = 2; i <= 50; i++) {
        f[i] = f[i - 1] + f[i - 2];
        len[i] = len[i - 1] + len[i - 2];
    }
}

int res(int n, int k)
{
    if (k == len[n])
        return f[n];
    if (k > len[n - 1])
        return f[n - 1] + res(n - 2, k - len[n - 1]);
    else
        return res(n - 1, k);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    init();
    int test;
    cin >> test;
    while (test--) {
        int n, k;
        cin >> n >> k;
        cout << res(n, k) << endl;
    }
}