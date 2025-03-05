#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return a.second > b.second;
    else
        return a.first < b.first;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mp[x]++;
        }
        vector<pair<int, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), cmp);
        for (auto x : v) {
            for (int i = 0; i < x.second; i++)
                cout << x.first << ' ';
        }
        cout << endl;
    }
}