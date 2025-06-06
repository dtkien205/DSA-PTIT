#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n;
vector<vector<int>> res;
vector<int> tmp;
bool vs[10];

void Try(int i)
{
    if (i == n) {
        if (tmp[0] > tmp[n - 1]) {
            res.push_back(tmp);
        }
        return;
    }

    for (int j = 1; j <= n; j++) {
        if (!vs[j]) {
            vs[j] = true;
            tmp.push_back(j);
            Try(i + 1);
            tmp.pop_back();
            vs[j] = false;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    Try(0);

    for (auto v : res) {
        for (auto x : v)
            cout << x << ' ';
        cout << endl;
    }
}