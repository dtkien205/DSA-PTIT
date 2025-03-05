#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int& i : v)
            cin >> i;
        sort(v.begin(), v.end());
        int res = INT_MAX;
        for (int i = 1; i < n; i++)
            res = min(res, v[i] - v[i - 1]);
        cout << res << endl;
    }
}