#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, s, res;
int a[100];

void Try(int i, int bd, int sum)
{
    for (int j = bd; j < n; j++) {
        if (sum + a[j] <= s) {
            if (sum + a[j] == s)
                res = min(res, i);
            else
                Try(i + 1, j + 1, sum + a[j]);
        } else
            return;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        res = INT_MAX;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Try(0, 0, 0);
        if (res == INT_MAX)
            cout << "-1\n";
        else
            cout << res + 1 << endl;
    }
}