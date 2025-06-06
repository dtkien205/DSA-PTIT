#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        string s;
        getline(cin >> ws, s);
        string res = "";
        stack<string> st;
        for (auto x : s) {
            if (x != ')') {
                st.push(string(1, x));
            } else {
                string tmp = "";
                while (!st.empty() && st.top() != "(") {
                    tmp = st.top() + tmp;
                    st.pop();
                }
                st.pop();
                if (!st.empty() && st.top() == "-" && tmp.size() > 1) {
                    st.push("(" + tmp + ")");
                } else
                    st.push(tmp);
            }
        }
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        cout << res << endl;
    }
}