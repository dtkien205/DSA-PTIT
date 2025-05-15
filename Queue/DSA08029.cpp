#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

string left(string v)
{
    string tmp = v;
    tmp[0] = v[3], tmp[1] = v[0], tmp[4] = v[1], tmp[3] = v[4];
    return tmp;
}

string right(string v)
{
    string tmp = v;
    tmp[1] = v[4], tmp[2] = v[1], tmp[4] = v[5], tmp[5] = v[2];
    return tmp;
}

string t_left(string v)
{
    string tmp = v;
    tmp[0] = v[1], tmp[1] = v[4], tmp[4] = v[3], tmp[3] = v[0];
    return tmp;
}

string t_right(string v)
{
    string tmp = v;
    tmp[1] = v[2], tmp[2] = v[5], tmp[4] = v[1], tmp[5] = v[4];
    return tmp;
}

int bfs(string s1, string s2)
{
    queue<pair<string, int>> q1, q2;
    unordered_map<string, int> mp1, mp2;
    q1.push({ s1, 0 });
    q2.push({ s2, 0 });
    mp1[s1] = 0;
    mp2[s2] = 0;
    while (!q1.empty() && !q2.empty()) {
        auto [cur1, cnt1] = q1.front();
        q1.pop();
        for (auto next : { left(cur1), right(cur1) }) {
            if (!mp1.count(next)) {
                mp1[next] = cnt1 + 1;
                q1.push({ next, cnt1 + 1 });
                if (mp2.count(next))
                    return cnt1 + 1 + mp2[next];
            }
        }

        auto [cur2, cnt2] = q2.front();
        q2.pop();
        for (auto next : { t_left(cur2), t_right(cur2) }) {
            if (!mp2.count(next)) {
                mp2[next] = cnt2 + 1;
                q2.push({ next, cnt2 + 1 });
                if (mp1.count(next))
                    return cnt2 + 1 + mp1[next];
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        for (int i = 0; i < 6; i++) {
            char x;
            cin >> x;
            if (x != ' ')
                s1 += x;
        }
        for (int i = 0; i < 6; i++) {
            char x;
            cin >> x;
            if (x != ' ')
                s2 += x;
        }
        cout << bfs(s1, s2) << endl;
    }
}
