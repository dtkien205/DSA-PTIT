#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<ll, int>

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    priority_queue<ii> pq;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        pq.push({ x + y, y });
    }
    ll res = 0;
    for (int i = 1; i <= min(n, m); i++) {
        auto [x, y] = pq.top();
        pq.pop();
        res += x;
        pq.push({ y, y });
    }
    
    if (m > n)
        res += pq.top().first * (m - n);
    cout << res;
}