#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

string solve(string s)
{
    stack<string> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ')')
            st.push(string(1, s[i]));
        else {
            string tmp = "";
            while (!st.empty() && st.top() != "(") {
                tmp = st.top() + tmp;
                st.pop();
            }
            st.pop();
            if (!st.empty() && st.top() == "-") {
                for (auto& x : tmp) {
                    if (x == '+')
                        x = '-';
                    else if (x == '-')
                        x = '+';
                }
            }
            st.push(tmp);
        }
    }
    string res = "";
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;
        cout << (solve(s) == solve(t) ? "YES" : "NO") << endl;
    }
}