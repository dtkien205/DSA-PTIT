#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int v, e;
        cin >> v >> e;
        vector<int> ke[v + 1];
        for (int i = 0; i < e; i++) {
            int x, y;
            cin >> x >> y;
            ke[x].push_back(y);
        }
        for (int i = 1; i <= v; i++) {
            cout << i << ": ";
            for (auto x : ke[i])
                cout << x << ' ';
            cout << endl;
        }
    }
}