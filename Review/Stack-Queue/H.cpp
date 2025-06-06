#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        queue<int> q;
        q.push(n);
        set<int> se;

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            int c = sqrt(x);
            for (int u = 1; u <= c; u++) {
                if (x % u == 0) {
                    int v = x / u;
                    int num = (u - 1) * (v + 1);
                    if (!se.count(num)) {
                        se.insert(num);
                        q.push(num);
                    }
                }
            }
        }

        cout << se.size() << endl;
        for (auto x : se)
            cout << x << ' ';
        cout << endl;
    }
}