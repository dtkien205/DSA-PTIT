#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> res;
string s;

void Try(int i)
{
    if (i == n) {
        res.push_back(s);
        return;
    }
    for (char c : { 'A', 'B', 'C' }) {
        s += c;
        Try(i + 1);
        s.pop_back();
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;

    Try(0);

    for (int i = 0; i < res.size(); i++) {
        if ((i + 1) % 2 == 1)
            cout << i + 1 << ": " << res[i] << endl;
    }
}
