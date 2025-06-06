#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n;
vector<string> v;

void Try(int i, string s, int cnt)
{
    if (s.size() == n) {
        if (cnt % 2 == 0)
            v.push_back(s);
        return;
    }
    Try(i + 1, s + "0", cnt);
    Try(i + 1, s + "1", cnt + 1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    Try(1, "", 0);
    for (auto s : v) {
        for (auto x : s)
            cout << x << ' ';
        cout << endl;
    }
}