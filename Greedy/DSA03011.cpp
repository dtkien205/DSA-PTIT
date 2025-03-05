#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int mod = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll sum = 0;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            pq.push(x);
        }
        while (pq.size() > 1) {
            ll num1 = pq.top();
            pq.pop();
            ll num2 = pq.top();
            pq.pop();
            pq.push((num1 + num2) % mod);
            sum += (num1 + num2) % mod;
            sum %= mod;
        }
        cout << sum << endl;
    }
}