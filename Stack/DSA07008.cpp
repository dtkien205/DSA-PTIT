#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int check(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '^')
        return 3;
    else if (x == '*' || x == '/')
        return 2;
    else
        return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        getline(cin >> ws, s);
        string res = "";
        stack<char> st;
        for (auto x : s) {
            if (isalpha(x))
                res += x;
            else if (x == '(')
                st.push(x);
            else if (x == ')') {
                while (st.top() != '(') {
                    res += st.top();
                    st.pop();
                }
                st.pop();
            } else {
                while (!st.empty() && check(st.top()) >= check(x)) {
                    res += st.top();
                    st.pop();
                }
                st.push(x);
            }
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        cout << res << endl;
    }
}