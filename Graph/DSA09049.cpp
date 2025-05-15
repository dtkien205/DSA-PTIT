#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<int> A[200005];
ll M[200005], h[200005];

ll dfs1(int u) // tinh so luong con v cua u
{
    M[u] = 1;
    for (int v : A[u])
        M[u] += dfs1(v);
    return M[u];
}

ll dfs2(int u)
{
    h[u] = 1;
    for (int v : A[u])
        h[u] += dfs2(v) + M[v];
    return h[u];
}

int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        A[u].push_back(i);
    }
    dfs1(1);
    dfs2(1);
    for (int i = 1; i <= n; i++)
        cout << h[i] << " ";
}
