#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[10][10];
int c[10] = {}, d1[10] = {}, d2[10] = {};
int ans;

void Try(int i, int s)
{
    for (int j = 1; j <= 8; j++) {
        if (!c[j] && !d1[i + j - 1] && !d2[i - j + 8]) {
            c[j] = d1[i + j - 1] = d2[i - j + 8] = 1;
            if (i == 8)
                ans = max(ans, s + a[i][j]);
            else
                Try(i + 1, s + a[i][j]);
            c[j] = d1[i + j - 1] = d2[i - j + 8] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        for (int i = 1; i <= 8; i++)
            for (int j = 1; j <= 8; j++)
                cin >> a[i][j];
        ans = 0;
        Try(1, 0);
        cout << ans << endl;
    }
}