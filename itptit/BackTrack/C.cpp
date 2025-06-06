#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, k;
vector<string> v;

void Try(int i, string s)
{
    if (s.size() == n) {
        v.push_back(s);
        return;
    }
    for (int j = 0; j <= 1; j++)
        Try(i + 1, s + to_string(j));
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    Try(1, "");
    for (int i = 0; i < v.size(); i++) {
        if (i % k == 0)
            cout << v[i] << endl;
    }
}