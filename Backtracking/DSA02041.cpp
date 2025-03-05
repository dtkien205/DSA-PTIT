#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int minStep(int n)
{
    if (n == 1)
        return 0;

    queue<pair<int, int>> q;
    q.push({ n, 0 });

    while (!q.empty()) {
        auto [x, cnt] = q.front();
        q.pop();

        if (x == 1)
            return cnt;

        q.push({ x - 1, cnt + 1 });
        if (x % 2 == 0)
            q.push({ x / 2, cnt + 1 });
        if (x % 3 == 0)
            q.push({ x / 3, cnt + 1 });
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << minStep(n) << endl;
    }
}