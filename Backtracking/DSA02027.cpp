#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n;
int a[20][20], x[50], visited[50];
int cmin = INT_MAX, res = INT_MAX, dis = 0;

void Try(int i)
{
    for (int j = 2; j <= n; j++) {
        if (!visited[j]) {
            visited[j] = 1;
            x[i] = j;
            dis += a[x[i - 1]][x[i]];

            if (i == n)
                res = min(res, dis + a[x[n]][1]);
            else if (dis + (n - i + 1) * cmin < res)
                Try(i + 1);

            visited[j] = 0;
            dis -= a[x[i - 1]][x[i]];
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j])
                cmin = min(cmin, a[i][j]);
        }
    }
    x[1] = 1;
    visited[1] = 1;
    Try(2);
    cout << res << endl;
}