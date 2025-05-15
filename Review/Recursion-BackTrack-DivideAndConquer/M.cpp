#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, s, minCandy = 1e9;
int a[30], cnt;
string res;

void Try(int i, int sum)
{
    for (int j = 1; j <= s - sum; j++) {
        if (a[i - 1] >= j) {
            a[i] = j;
            if (i == n) {
                if (sum + j == s) {
                    cnt++;
                    if (a[1] - a[n] < minCandy) {
                        res = "";
                        for (int u = 1; u <= n; u++)
                            res += to_string(a[u]) + ' ';
                        minCandy = a[1] - a[n];
                    }
                }
            } else
                Try(i + 1, sum + j);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    a[0] = 1e9;
    cin >> n >> s;
    Try(1, 0);
    cout << cnt << '\n' << res;
}