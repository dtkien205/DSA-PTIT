#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, h[1005];
vector<int> adj[1005];
bool visited[1005];

void dfs(int u)
{
    h[u] = 1;
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
            h[u] += h[v] + 1;
        }
    }
}   

int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << h[i] << ' ';
}