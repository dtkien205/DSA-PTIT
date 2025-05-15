#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int n, m;
int a[105][105];

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = (i == j ? 0 : 1e9);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
}

void Floy()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
}

int main()
{
    int test;
    cin >> test;
    while (test--) {
        init();
        Floy();
        int sum = 0, cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i][j] != 1e9 && i != j) {
                    sum += a[i][j];
                    cnt++;
                }
            }
        }
        cout << setprecision(2) << fixed << (1.0 * sum / cnt) << endl;
    }
}