#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<vector<int>> v;
vector<int> tmp;
int n, k, vs[100];

void Try(int i, int sum)
{
    if (tmp.size() == k) {
        if (sum % 2 == 0)
            v.push_back(tmp);
        return;
    }
    for (int j = i; j <= n; j++) {
        tmp.push_back(j);
        Try(j + 1, sum + j);
        tmp.pop_back();
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    Try(1, 0);
    for (auto x : v) {
        for (auto y : x)
            cout << y << ' ';
        cout << endl;
    }
}