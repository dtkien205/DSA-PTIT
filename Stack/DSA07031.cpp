#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ll cal(ll a, ll b, string x)
{
    if (x == "+")
        return a + b;
    else if (x == "-")
        return a - b;
    else if (x == "*")
        return a * b;
    else
        return a / b;
}

int main()
{
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
        stack<ll> st;
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/") {
                ll o1 = st.top();
                st.pop();
                ll o2 = st.top();
                st.pop();
                st.push(cal(o1, o2, v[i]));
            } else
                st.push(stoll(v[i]));
        }
        cout << st.top() << endl;
    }
}