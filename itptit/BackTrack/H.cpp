#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<vector<int>> v;
vector<int> tmp;
int n, vs[100];

void Try(int i)
{
    if (tmp.size() == n) {
        if (tmp[0] < tmp[n - 1])
            v.push_back(tmp);
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
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    Try(1);
    for (auto x : v) {
        for (auto y : x)
            cout << y << ' ';
        cout << endl;
    }
}