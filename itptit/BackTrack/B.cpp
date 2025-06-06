#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n;
vector<string> v;

void Try(int i, string s)
{
    if (s.size() == n) {
        v.push_back(s);
        return;
    }
    Try(i + 1, s + "0");
    Try(i + 1, s + "1");
    Try(i + 1, s + "2");
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    Try(1, "");
    for (int i = 0; i < v.size(); i++) {
        if ((i + 1) % 2 == 0)
            cout << i + 1 << ": " << v[i] << endl;
    }
}