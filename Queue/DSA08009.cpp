#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int bfs(int s, int t)
{
    queue<pair<int, int>> q;
    set<int> se;
    q.push({ s, 0 });
    se.insert(s);
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == t)
            return y;

        // tru 1
        if (x > 1 && !se.count(x - 1)) {
            se.insert(x - 1);
            q.push({ x - 1, y + 1 });
        }
        // nhan 2
        if (x < t && !se.count(x * 2)) {
            se.insert(x * 2);
            q.push({ x * 2, y + 1 });
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int s, t;
        cin >> s >> t;
        cout << bfs(s, t) << endl;
    }
}