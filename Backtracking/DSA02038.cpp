#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, k, a[100], x[100], used[105] = {};

void Try(int i, int bd)
{
    if (i > k) {
        for (int u = 1; u < i; u++)
            cout << x[u] << ' ';
        cout << endl;
        return;
    }
    for (int j = bd; j <= n; j++) {
        if (!used[a[j]]) {
            used[a[j]] = 1;
            x[i] = a[j];
            Try(i + 1, j + 1);
            used[a[j]] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        Try(1, 1);
    }
}