#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n;
int cal(string s)
{
    int res = 0;
    for (char c : s) {
        res = res * 10 + (c - '0');
        res %= n;
    }
    return res;
}

void solve()
{
    map<string, int> mp;
    mp["6"] = cal("6");
    mp["8"] = cal("8");
    queue<string> q;
    q.push("6");
    q.push("8");

    while (!q.empty()) {
        string tmp = q.front();
        q.pop();

        if (tmp.size() > 200)
            break;

        if (!mp[tmp]) {
            cout << tmp;
            return;
        }

        string next6 = tmp + "6";
        if (!mp[next6]) {
            mp[next6] = cal(next6);
            q.push(next6);
        }

        string next8 = "8" + tmp;
        if (!mp[next8]) {
            mp[next8] = cal(next8);
            q.push(next8);
        }
    }

    cout << -1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    solve();
}