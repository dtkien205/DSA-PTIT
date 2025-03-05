#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int bfs(int n)
{
    queue<pair<int, int>> q;
    set<int> se;
    q.push({ n, 0 });
    se.insert(n);
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == 1)
            return y;

        // tru 1
        if (x > 1 && !se.count(x - 1)) {
            se.insert(x - 1);
            q.push({ x - 1, y + 1 });
        }
        // max(u, v)
        int tmp = x;
        for (int i = 2; i <= sqrt(tmp); i++) {
            if (tmp % i == 0) {
                int num = max(i, tmp / i);
                if (!se.count(num)) {
                    se.insert(num);
                    q.push({ num, y + 1 });
                }
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << bfs(n) << endl;
    }
}