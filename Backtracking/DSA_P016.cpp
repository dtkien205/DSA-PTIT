#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int c[10] = {}, c1[10] = {}, c2[10] = {};
int ans, a[10][10];

void Try(int i, int sum)
{
    for (int j = 1; j <= 8; j++) {
        if (!c[j] && !c1[i + j - 1] && !c2[i - j + 8]) {
            c[j] = c1[i + j - 1] = c2[i - j + 8] = 1;
            if (i == 8)
                ans = max(ans, sum + a[i][j]);
            else
                Try(i + 1, sum + a[i][j]);
            c[j] = c1[i + j - 1] = c2[i - j + 8] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for (int l = 1; l <= t; l++) {
        for (int i = 1; i <= 8; i++)
            for (int j = 1; j <= 8; j++)
                cin >> a[i][j];
        ans = 0;
        Try(1, 0);
        cout << "Test " << l << ": " << ans << endl;
    }
}