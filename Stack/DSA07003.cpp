#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool check(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ')')
            st.push(s[i]);
        else {
            bool ok = true;
            while (!st.empty() && st.top() != '(') {
                char tmp = st.top();
                if (tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/')
                    ok = false;
                st.pop();
            }
            if (ok)
                return true;
            st.pop();
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        getline(cin >> ws, s);
        cout << (check(s) ? "Yes\n" : "No\n");
    }
}