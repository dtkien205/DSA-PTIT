#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, k;
ll F[100], len[100];

void init()
{
    len[0] = len[1] = 1;
    F[0] = 1, F[1] = 0;
    for (int i = 2; i <= 50; i++) {
        len[i] = len[i - 1] + len[i - 2];
        F[i] = F[i - 1] + F[i - 2];
    }
}

int solve(int n, int k)
{
    if (k == len[n])
        return F[n];
    if (k <= len[n - 1])
        return solve(n - 1, k);
    else
        return F[n - 1] + solve(n - 2, k - len[n - 1]);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    init();
    while (test--) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
}