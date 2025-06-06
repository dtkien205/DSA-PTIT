#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool check(string s)
{
    stack<char> st;
    for (auto x : s) {
        if (x == '(' || x == '[')
            st.push(x);
        else if (x == ')') {
            if (!st.empty() && st.top() == '(')
                st.pop();
            else
                return false;
        } else if (x == ']') {
            if (!st.empty() && st.top() == '[')
                st.pop();
            else
                return false;
        }
    }
    return st.empty();
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        string s;
        getline(cin >> ws, s);
        cout << (check(s) ? "YES\n" : "NO\n");
    }
}