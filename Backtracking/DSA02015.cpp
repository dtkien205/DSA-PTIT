#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool check(string s)
{
    if (s.size() < 2)
        return false;
    stack<char> st;
    for (char c : s) {
        if (c == '(')
            st.push(c);
        else if (c == ')') {
            if (st.empty())
                return false;
            else
                st.pop();
        }
    }
    return st.empty();
}

string s;
int maxLen;
set<string> se;

void Try(string s, int i)
{
    if (s.size() < maxLen)
        return;
    if (check(s)) {
        if (s.size() > maxLen) {
            maxLen = s.size();
            se.clear();
        }
        se.insert(s);
        return;
    }
    for (int j = i; j < s.size(); j++) {
        if (s[j] == '(' || s[j] == ')') {
            string tmp = s;
            tmp.erase(j, 1);
            Try(tmp, j);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        getline(cin >> ws, s);
        maxLen = 0;
        se.clear();
        Try(s, 0);
        if (se.size()) {
            for (auto x : se)
                cout << x << ' ';
        } else
            cout << -1;
        cout << endl;
    }
}