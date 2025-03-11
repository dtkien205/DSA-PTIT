#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> ke[1005];
 
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int v, e;
        cin >> v >> e;
        for (int i = 1; i <= v; i++)
            ke[i].clear();

        for (int i = 1; i <= e; i++) {
            int x, y;
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        for (int i = 1; i <= v; i++) {
            sort(ke[i].begin(), ke[i].end());
            cout << i << ": ";
            for (auto v : ke[i])
                cout << v << ' ';
            cout << endl;
        }
    }
}