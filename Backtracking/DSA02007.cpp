#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

string ans;

void Try(string& s, int k)
{
    if (k == 0)
        return;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            if (s[i] < s[j]) {
                swap(s[i], s[j]);
                ans = max(ans, s);
                Try(s, k - 1);
                swap(s[i], s[j]);
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        string s;
        cin >> s;
        ans = s;
        Try(s, k);
        cout << ans << endl;
    }
}