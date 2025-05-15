#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    int test;
    cin >> test;
    while (test--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (auto& i : a)
            cin >> i;
        for (auto& i : b)
            cin >> i;
        ll res[n + m - 1];
        memset(res, 0, sizeof(res));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                res[i + j] += a[i] * b[j];

        for (auto x : res)
            cout << x << ' ';
        cout << endl;
    }
}