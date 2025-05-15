#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, s, a[25], x[25], cnt;

void Try(int i, int bd, int sum)
{
    if (sum == s && i > 1)
        cnt++;
    for (int j = bd; j <= n; j++) {
        if (sum + a[j] <= s)
            Try(i + 1, j + 1, sum + a[j]);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Try(1, 1, 0);
    cout << cnt;
}