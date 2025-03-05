#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        map<char, int> mp;
        for (auto i : s)
            mp[i]++;
        int ok = 0;
        for (auto x : mp) {
            if (x.second * 2 - 1 > s.size()) {
                ok = 1;
                break;
            }
        }
        if (ok)
            cout << "-1" << endl;
        else
            cout << 1 << endl;
    }
}