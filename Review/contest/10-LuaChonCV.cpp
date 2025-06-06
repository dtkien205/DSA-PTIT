#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({ x, y });
    }

    sort(v.begin(), v.end(), cmp);
    ll res = 0;
    map<int, int> chosen;
    // for (auto [x, y] : v)
    //     cout << x << ' ' << y << endl;
    for (int i = 0; i < n; i++) {
        for (int j = v[i].first; j >= 1; j--) {
            if (!chosen[j]) {
                chosen[j] = 1;
                res += v[i].second;
                break;
            }
        }
    }
    cout << res << endl;
}