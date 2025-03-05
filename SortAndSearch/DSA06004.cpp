#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        set<int> hop, giao;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            hop.insert(x);
        }
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            if (hop.count(x))
                giao.insert(x);
            hop.insert(x);
        }
        for (auto i : hop)
            cout << i << ' ';
        cout << endl;
        for (auto i : giao)
            cout << i << ' ';
        cout << endl;
    }
}