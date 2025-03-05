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
        int F[n + 1], S[n + 1];
        vector<pair<int, int>> v;
        for (int i = 1; i <= n; i++)
            cin >> F[i];
        for (int i = 1; i <= n; i++)
            cin >> S[i];
        for (int i = 1; i <= n; i++)
            v.push_back({ F[i], S[i] });
        sort(v.begin(), v.end(), cmp);
        int cnt = 0;
        int last = 0;
        for (auto x : v) {
            int start = x.first, end = x.second;
            if (start >= last) {
                cnt++;
                last = end;
                // cout << x.first << " " << x.second << endl;
            }
        }
        cout << cnt << endl;
    }
}