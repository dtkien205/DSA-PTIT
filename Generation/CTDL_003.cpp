#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, w, f[105], a[105];
vector<int> x;
vector<vector<int>> ans;
int MAX = 0;

void gen()
{
    x.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        x[i] = 0;
    while (1) {
        int sum = 0, res = 0;
        for (int i = 1; i <= n; i++) {
            sum += a[i] * x[i];
            res += f[i] * x[i];
        }
        if (sum <= w) {
            if (res >= MAX) {
                MAX = res;
                ans.clear();
                ans.push_back(x);
            }
        }

        int i = n;
        while (i >= 1 && x[i] == 1) {
            x[i] = 0;
            i--;
        }
        if (i == 0)
            return;
        x[i] = 1;
    }
}

int main()
{
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
        cin >> f[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    gen();
    cout << MAX << endl;
    for (auto x : ans) {
        for (int i = 1; i <= n; i++)
            cout << x[i] << ' ';
        cout << endl;
    }
}