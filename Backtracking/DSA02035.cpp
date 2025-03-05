#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, k, res;
int vs[10], hv[10];
string a[10], b[10];

void solve()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            b[i][j] = a[i][hv[j]];
    sort(b, b + n);
    res = min(res, stoi(b[n - 1]) - stoi(b[0]));
}

void Try(int i)
{
    for (int j = 0; j < k; j++) {
        if (!vs[j]) {
            hv[i] = j;
            vs[j] = 1;
            if (i == k - 1)
                solve();
            else
                Try(i + 1);
            vs[j] = 0;
        }
    }
}

int main()
{
    cin >> n >> k;
    memset(vs, 0, sizeof(vs));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    res = INT_MAX;
    Try(0);
    cout << res << endl;
}