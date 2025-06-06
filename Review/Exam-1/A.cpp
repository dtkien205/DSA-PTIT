#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m;
vector<vector<int>> res;
vector<int> tmp;
bool vs[15];

void Try(int i)
{
    if (i == n) {
        if (tmp[0] == m)
            res.push_back(tmp);
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (!vs[j]) {
            vs[j] = 1;
            tmp.push_back(j);
            Try(i + 1);
            tmp.pop_back();
            vs[j] = 0;
        }
    }
}

int main()
{
    cin >> n >> m;
    Try(0);
    for (auto v : res) {
        for (auto x : v)
            cout << x << ' ';
        cout << endl;
    }
}