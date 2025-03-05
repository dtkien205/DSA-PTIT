#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        while (n--) {
            int x, y;
            cin >> x >> y;
            v.push_back({ x, y });
        }
        sort(v.begin(), v.end(), cmp);
        int cnt = 0, last = 0;
        for (auto x : v) {
            int start = x.first, end = x.second;
            if (start >= last) {
                cnt++;
                last = end;
            }
        }
        cout << cnt << endl;
    }
}