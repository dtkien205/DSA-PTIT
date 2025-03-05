#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<string> ans;

bool check(const string& a)
{
    return ((a[0] != '0' || a[1] != '0') && a[2] != '2' && a[3] != '0' && a[4] != '0');
}

void Try(int i, string s)
{
    if (i == 8) {
        if (check(s))
            ans.push_back(s);
        return;
    }
    s[i] = '0';
    Try(i + 1, s + "0");
    s[i] = '2';
    Try(i + 1, s + "2");
}

int main()
{
    Try(0, "");
    for (auto x : ans) {
        x.insert(2, "/");
        x.insert(5, "/");
        cout << x << endl;
    }
}