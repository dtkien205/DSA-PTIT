#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;

    string res = "";
    stack<char> st;

    for (auto x : s) {
        if (isalnum(x))
            res += x;
        else if (x == '<') {
            if (!res.empty()) {
                st.push(res.back());
                res.pop_back();
            }
        } else if (x == '>') {
            if (!st.empty()) {
                res += st.top();
                st.pop();
            }
        } else {
            if (!res.empty())
                res.pop_back();
        }
    }

    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    cout << res;
}