#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> res;
void gen()
{
    queue<ll> q;
    for (int i = 1; i <= 5; i++)
        q.push(i);
    while (!q.empty()) {
        int d[10];
        memset(d, 0, sizeof(d));
        int x = q.front();
        if (x > 1e5)
            break;
        res.push_back(x);
        q.pop();
        int tmp = x;
        while (tmp) {
            d[tmp % 10] = 1;
            tmp /= 10;
        }
        for (int i = 0; i <= 5; i++) {
            if (!d[i])
                q.push(x * 10 + i);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    gen();
    while (t--) {
        int l, r;
        cin >> l >> r;

        int cnt = 0;
        for (auto x : res) {
            if (x >= l && x <= r)
                cnt++;
        }
        cout << cnt << endl;
    }
}