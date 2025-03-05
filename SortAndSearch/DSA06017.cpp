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
        vector<int> v;
        while (n--) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        while (m--) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        for (auto i : v)
            cout << i << ' ';
        cout << endl;
    }
}