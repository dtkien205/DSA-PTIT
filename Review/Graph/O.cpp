#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, k, sz[100005];
bool vs[100005];
vector<int> adj[100005];
string s;
int res;

void dfs(int u)
{
    vs[u] = true;
    (s[u] == 'W' ? sz[u]++ : sz[u]--);
    for (int v : adj[u]) {
        if (!vs[v]) {
            dfs(v);
            sz[u] += sz[v];
        }
    }
    if (!sz[u])
        res++;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            sz[i] = 0;
            vs[i] = false;
        }

        for (int i = 2; i <= n; i++) {
            int x;
            cin >> x;
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
        getline(cin >> ws, s);
        s = " " + s;
        res = 0;
        dfs(1);
        cout << res << endl;
    }
}