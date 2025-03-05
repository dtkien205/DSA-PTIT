#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, s, a[100], x[100];
vector<vector<int>> res;

void Try(int i, int bd, int sum)
{
    for (int j = bd; j <= n; j++) {
        if (sum + a[j] <= s) {
            x[i] = a[j];
            if (sum + a[j] == s) {
                vector<int> v;
                for (int u = 1; u <= i; u++)
                    v.push_back(x[u]);
                res.push_back(v);
            } else
                Try(i + 1, j + 1, sum + a[j]);
        }
    }
}

int main()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Try(1, 1, 0);
    sort(res.begin(), res.end(), greater<vector<int>>());
    for (auto x : res) {
        for (auto i : x)
            cout << i << ' ';
        cout << endl;
    }
    cout << res.size();
}