#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, k;
vector<string> v;

bool check(string s)
{
    string tmp = string(k, 'A');
    int pos = s.find(tmp);
    if (pos != string::npos && (pos + k == s.size() || s[pos + k] == 'B'))
        return true;
    return false;
}

void Try(string s, int i)
{
    if (s.size() == n) {
        if (check(s))
            v.push_back(s);
        return;
    }
    Try(s + 'A', i + 1);
    Try(s + 'B', i + 1);
}

int main()
{
    cin >> n >> k;
    Try("", 0);
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (auto x : v)
        cout << x << endl;
}