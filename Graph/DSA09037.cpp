#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m, k;
vector<int> adj[1005];
bool visited[1005];
map<int, int> mp;

void dfs(int u)
{
    mp[u]++;
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int main()
{
    cin >> k >> n >> m;
    vector<int> people(k);
    for (int& i : people)
        cin >> i;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    for (auto x : people) {
        memset(visited, 0, sizeof(visited));
        dfs(x);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (mp[i] == k)
            cnt++;
    }
    cout << cnt << endl;
}