#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct edges {
    int x, y;
    double w;
};

struct Point {
    int x, y;
};

int n, m;
int par[1005];

void init()
{
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        par[i] = i;
}

int Find(int u)
{
    if (u == par[u])
        return u;
    return par[u] = Find(par[u]);
}

bool Union(int u, int v)
{
    u = Find(u), v = Find(v);
    if (u == v)
        return false;
    par[v] = u;
    return true;
}

bool cmp(edges a, edges b)
{
    return a.w < b.w;
}

double dis(Point a, Point b)
{
    return sqrt(1ll * (a.x - b.x) * (a.x - b.x) + 1ll * (a.y - b.y) * (a.y - b.y));
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    init();
    int cnt = 0;
    vector<edges> e;
    vector<Point> p(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y;

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        e.push_back({ x, y, 0 });
    }

    for (int i = 1; i <= n - 1; i++)
        for (int j = i + 1; j <= n; j++)
            e.push_back({ i, j, dis(p[i], p[j]) });

    sort(e.begin(), e.end(), cmp);

    double res = 0;
    for (auto [x, y, w] : e) {
        if (cnt == n - 1)
            break;

        if (Union(x, y)) {
            res += w;
            cnt++;
        }
    }
    cout << fixed << setprecision(2) << res << endl;
}