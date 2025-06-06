#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll F[100];
int n, k, vs[100];
vector<int> tmp;
vector<vector<int>> res;
set<ll> se;

void init()
{
    F[1] = 1, F[2] = 2;
    se.insert(1);
    se.insert(2);
    for (int i = 3; i <= 93; i++) {
        F[i] = F[i - 1] + F[i - 2];
        se.insert(F[i]);
    }
}

void Try(int i)
{
    if (tmp.size() == k) {
        res.push_back(tmp);
        return;
    }
    for (int j = i; j <= n; j++) {
        tmp.push_back(j);
        vs[j] = 1;
        Try(j + 1);
        tmp.pop_back();
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    init();
    Try(1);

    for (int i = 0; i < res.size(); i++) {
        if (se.count(i + 1)) {
            cout << i + 1 << ": ";
            for (auto x : res[i])
                cout << x << ' ';
            cout << endl;
        }
    }
}