#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n;
string s;
vector<string> v;

bool check(string s)
{
    return s.size() >= 6 && s.front() == '8' && s.back() == '6'
        && s.find("88") == string::npos && s.find("6666") == string::npos;
}

void Try(string s, int i)
{
    if (i == n) {
        if (check(s))
            v.push_back(s);
        return;
    }
    Try(s + '6', i + 1);
    Try(s + '8', i + 1);
}

int main()
{
    cin >> n;
    s.resize(n);
    Try("", 0);
    sort(v.begin(), v.end());
    for (auto x : v)
        cout << x << endl;
    return 0;
}
