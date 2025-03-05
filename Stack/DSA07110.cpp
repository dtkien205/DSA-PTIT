#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int check(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        else {
            if (st.empty())
                return false;
            else {
                char tmp = st.top();
                if (s[i] == ')' && tmp == '(' || s[i] == ']' && tmp == '[' || s[i] == '}' && tmp == '{')
                    st.pop();
            }
        }
    }
    return st.empty();
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << (check(s) ? "YES\n" : "NO\n");
    }
}