#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
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
            int x, y, z;
            cin >> x >> y >> z;
            v.push_back({ y, z });
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> check(1001, 0);
        int cnt = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = v[i].first; j >= 1; j--) {
                if (check[j] == 0) {
                    check[j] = 1;
                    cnt++;
                    ans += v[i].second;
                    break;
                }
            }
        }
        cout << cnt << ' ' << ans << endl;
    }
}