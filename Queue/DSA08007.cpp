#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll gen(ll n)
{
    queue<ll> q;
    ll cnt = 0;
    q.push(1);
    while (true) {
        ll tmp = q.front();
        q.pop();
        
        if(tmp > n)
            return cnt;

        cnt++;
        q.push(tmp * 10);
        q.push(tmp * 10 + 1);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << gen(n) << endl;
    }
}