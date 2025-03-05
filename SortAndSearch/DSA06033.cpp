#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v.push_back({ x, i });
        }
        sort(v.begin(), v.end(), cmp);

        int res = INT_MIN, last = v[0].second;
        for (int i = 1; i < v.size(); i++) {
            res = max(res, v[i].second - last);
            last = min(last, v[i].second);
        }
        cout << res << endl;
    }
}