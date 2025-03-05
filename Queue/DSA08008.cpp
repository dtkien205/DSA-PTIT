#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int check(string S, ll n)
{
    ll s = 0;
    for (auto x : S)
        s = s * 10 + (x - '0');
    return s % n == 0;
}

string solve(ll n)
{
    queue<string> q;
    q.push("1");
    while (true) {
        string tmp = q.front();
        q.pop();
        
        if(check(tmp, n)) return tmp;
        q.push(tmp + "0");
        q.push(tmp + "1");
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        ll n; cin >> n;
        cout << solve(n) << endl;
    }
}