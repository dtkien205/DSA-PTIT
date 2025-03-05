#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m, x;
        cin >> n >> m >> x;
        int a[n + m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = n; i < n + m; i++)
            cin >> a[i];
        sort(a, a + n + m);
        cout << a[x - 1] << endl;
    }
}