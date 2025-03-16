#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n;
vector<int> adj[1005];
vector<vector<int>> v;
vector<int> tmp;

void dfs(int u, int par)
{
    tmp.push_back(u);
    if (adj[u].size() == 1 && u != 1) // not la
        v.push_back(tmp);
    for (int v : adj[u]) {
        if (v != par)
            dfs(v, u);
    }
    tmp.pop_back();
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        tmp.clear();
        v.clear();
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1, -1);
        sort(v.begin(), v.end(), [](vector<int> a, vector<int> b) {
            return a.back() < b.back();
        });
        for (auto x : v) {
            for (auto y : x)
                cout << y << ' ';
            cout << endl;
        }
    }
}