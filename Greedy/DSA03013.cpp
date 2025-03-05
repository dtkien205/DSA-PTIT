#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<char, int> mp;
        int maxFre = 0;
        for (auto c : s) {
            mp[c]++;
            maxFre = max(maxFre, mp[c]);
        }
        if ((maxFre - 1) * n < s.size())
            cout << "1" << endl;
        else
            cout << "-1" << endl;
    }
}