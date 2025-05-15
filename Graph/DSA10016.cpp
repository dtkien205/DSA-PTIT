#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct edges {
    int u, v;
    double w;
};

struct Point {
    double x, y;
};

int n;
int sz[1005], parent[1005];

double dist(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void init()
{
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if (u == v)
        return false;
    if (sz[u] < sz[v])
        swap(u, v);
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}

int main()
{
    int test;
    cin >> test;
    while (test--) {
        cin >> n;
        init();
        vector<Point> p;
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            p.push_back({ x, y });
        }

        vector<edges> adj;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                adj.push_back({ i, j, dist(p[i], p[j]) });

        sort(adj.begin(), adj.end(), [](edges a, edges b) -> bool {
            return a.w < b.w;
        });

        double res = 0;
        int cnt = 0;
        for (auto [u, v, w] : adj) {
            if (cnt == n - 1)
                break;
            if (Union(u, v)) {
                res += w;
                cnt++;
            }
        }
        cout << fixed << setprecision(6) << res << endl;
    }
}