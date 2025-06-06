#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n;
vector<string> v, tmp;
set<vector<string>> res;

void Try(int i)
{
    for (int j = i; j < n; j++) {
        tmp.push_back(v[j]);
        res.insert(tmp);
        Try(j + 1);
        tmp.pop_back();
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    Try(0);
    for (auto x : res) {
        for (auto y : x)
            cout << y;
        cout << endl;
    }
}