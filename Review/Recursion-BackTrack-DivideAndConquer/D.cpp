#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, k, a[20], used[20], x[20];
set<string> res;

void Try(int i)
{
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            if (x[i - 1] < j) {
                used[j] = 1;
                x[i] = j;
                if (i == k) {
                    string tmp = "";
                    for (int u = 1; u <= i; u++)
                        tmp += to_string(a[x[u]]);
                    res.insert(tmp);
                } else
                    Try(i + 1);
                used[j] = 0;
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Try(1);
    for (auto x : res)
        cout << x << endl;
}