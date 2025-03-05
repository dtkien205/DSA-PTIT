#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int chuyen(string s)
{
    int res = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        int pos = s.size() - i - 1;
        res += (s[i] - '0') * (1 << pos);
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int i = chuyen(s);
        // cout << i << endl;
        int value = i ^ (i >> 1);
        bitset<11> res(value);
        cout << res.to_string().substr(11 - s.size()) << endl;
    }
}