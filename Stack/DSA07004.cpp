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
        int cnt = 0;
        stack<char> st;
        for (auto x : s) {
            if (x == '(')
                st.push(x);
            else if (st.empty()) {
                st.push('(');
                cnt++;
            } else
                st.pop();
        }
        cout << st.size() / 2 + cnt << endl;
    }
}