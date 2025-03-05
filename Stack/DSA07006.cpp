#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

set<string> se;

void gen(string s)
{
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            st.push(i);
        else if (s[i] == ')') {
            string res = s;
            res.erase(i, 1);
            res.erase(st.top(), 1);
            st.pop();

            if (!se.count(res)) {
                se.insert(res);
                gen(res);
            }
        }
    }
}

int main()
{
    string s;
    cin >> s;
    gen(s);
    for (auto x : se)
        cout << x << endl;
}