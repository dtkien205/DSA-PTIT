#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll cal(string A, string B, string x)
{
    ll a = stoll(A), b = stoll(B);
    if (x == "+")
        return a + b;
    else if (x == "-")
        return a - b;
    else if (x == "*")
        return a * b;
    else
        return a / b;
}

bool check(string s)
{
    if (s == "+" || s == "-" || s == "*" || s == "/")
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
        string s, w;
        getline(cin >> ws, s);
        stringstream ss(s);
        vector<string> v;
        while (ss >> w)
            v.push_back(w);

        if (check(v[0])) {
            stack<string> st;
            for (int i = v.size() - 1; i >= 0; i--) {
                if (!check(v[i]))
                    st.push(v[i]);
                else {
                    string o1 = st.top();
                    st.pop();
                    string o2 = st.top();
                    st.pop();
                    st.push(to_string(cal(o1, o2, v[i])));
                }
            }
            cout << st.top() << endl;
        } else {
            stack<string> st;
            for (int i = 0; i < v.size(); i++) {
                if (!check(v[i]))
                    st.push(v[i]);
                else {
                    string o1 = st.top();
                    st.pop();
                    string o2 = st.top();
                    st.pop();
                    st.push(to_string(cal(o2, o1, v[i])));
                }
            }
            cout << st.top() << endl;
        }
    }
}