#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<int> A[200005];
ll child[200005], path[200005];

void dfs(int u)
{
    child[u] = 1;
    path[u] = 1;
    for (int v : A[u]) {
        dfs(v);
        child[u] += child[v];
        path[u] += path[v] + child[v];
    }
}

int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        A[u].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
        cout << path[i] << ' ';
}
