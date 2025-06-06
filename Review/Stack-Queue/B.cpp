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

bool ope(string x)
{
    if (x == "+" || x == "-" || x == "*" || x == "/")
        return true;
    return false;
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
        for (string x : v) {
            if (!ope(x))
                st.push(x);
            else {
                string o1 = st.top();
                st.pop();
                string o2 = st.top();
                st.pop();
                st.push(to_string(cal(o2, o1, x)));
            }
        }
        cout << st.top() << endl;
    }
}