#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int& i : a)
            cin >> i;
        for (int& i : b)
            cin >> i;
        int res[n + m - 1];
        memset(res, 0, sizeof(res));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                res[i + j] += a[i] * b[j];
        for (int x : res)
            cout << x << ' ';
        cout << endl;
    }
}