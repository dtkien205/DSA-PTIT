#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int count(int s, int t)
{
    queue<pair<int, int>> q;
    set<int> se;
    q.push({ s, 0 });
    se.insert(s);

    while (!q.empty()) {
        auto [x, cnt] = q.front();
        q.pop();

        if (x == t)
            return cnt;

        if (!se.count(x - 1) && s >= 1) {
            se.insert(x - 1);
            q.push({ x - 1, cnt + 1 });
        }

        if (!se.count(x * 2) && x < t) {
            se.insert(x * 2);
            q.push({ x * 2, cnt + 1 });
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    cout << count(n, m) << endl;
}