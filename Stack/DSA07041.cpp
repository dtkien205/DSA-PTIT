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
        stack<char> st;
        int cnt = 0;
        for (auto x : s) {
            if (x == '(')
                st.push(x);
            else if (!st.empty()) {
                cnt++;
                st.pop();
            }
        }
        cout << cnt * 2 << endl;
    }
}