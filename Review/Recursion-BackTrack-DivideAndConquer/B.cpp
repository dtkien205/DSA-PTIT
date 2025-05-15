#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, x[20], used[20];
string ed, a[20];
set<string> res;

void Try(int i)
{
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            used[j] = 1;
            x[j] = i;
            if (i == n) {
                if (a[x[n]] == ed) {
                    string tmp = "";
                    for (int u = 1; u <= i; u++)
                        tmp += a[x[u]] + ' ';
                    res.insert(tmp);
                }
            } else
                Try(i + 1);
            used[j] = 0;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> ed;

    Try(1);
    for (auto x : res)
        cout << x << endl;
}