#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll cal(string x, string y, string c)
{
    ll a = stoll(x), b = stoll(y);
    if (c == "+")
        return a + b;
    else if (c == "-")
        return a - b;
    else if (c == "*")
        return a * b;
    else
        return a / b;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        vector<string> v;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            v.push_back(s);
        }

        stack<string> st;
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i] != "+" && v[i] != "-" && v[i] != "*" && v[i] != "/")
                st.push(v[i]);
            else {
                string o1 = st.top();
                st.pop();
                string o2 = st.top();
                st.pop();
                // cout << cal(o1, o2, v[i]) << endl;
                st.push(to_string(cal(o1, o2, v[i])));
            }
        }
        cout << st.top() << endl;
    }
}