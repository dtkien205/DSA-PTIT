#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        string s;
        cin >> s;
        map<char, int> mp;
        for (char c : s)
            mp[c]++;
        priority_queue<int> pq;
        for (auto x : mp)
            pq.push(x.second);
        while (k--) {
            int cnt = pq.top();
            pq.pop();
            pq.push(cnt - 1);
        }
        ll sum = 0;
        while (pq.size() > 0) {
            int num = pq.top();
            pq.pop();
            sum += 1ll * num * num;
        }
        cout << sum << endl;
    }
}