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
        string s;
        cin >> k >> s;
        priority_queue<int> pq;
        map<char, int> mp;
        for (auto x : s)
            mp[x]++;
        for (auto x : mp)
            pq.push(x.second);
        while (k--) {
            if (pq.empty())
                break;
            int x = pq.top();
            pq.pop();
            pq.push(--x);
        }
        ll sum = 0;
        while (!pq.empty()) {
            sum += 1ll * pq.top() * pq.top();
            pq.pop();
        }
        cout << sum << endl;
    }
}