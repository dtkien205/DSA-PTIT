#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int check(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

ll cal(ll a, ll b, char x)
{
    if (x == '-')
        return a - b;
    else if (x == '+')
        return a + b;
    else if (x == '*')
        return a * b;
    return a / b;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        getline(cin >> ws, s);
        stack<ll> st1;
        stack<char> st2;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                st2.push(s[i]);
            else if (isdigit(s[i])) {
                ll num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                st1.push(num);
            } else if (s[i] == ')') {
                while (!st2.empty() && st2.top() != '(') {
                    ll o1 = st1.top();
                    st1.pop();
                    ll o2 = st1.top();
                    st1.pop();
                    st1.push(cal(o2, o1, st2.top()));
                    st2.pop();
                }
                if (!st2.empty())
                    st2.pop();
            } else {
                while (!st2.empty() && check(s[i]) <= check(st2.top())) {
                    ll o1 = st1.top();
                    st1.pop();
                    ll o2 = st1.top();
                    st1.pop();
                    st1.push(cal(o2, o1, st2.top()));
                    st2.pop();
                }
                st2.push(s[i]);
            }
        }
        while (!st2.empty()) {
            ll o1 = st1.top();
            st1.pop();
            ll o2 = st1.top();
            st1.pop();
            st1.push(cal(o2, o1, st2.top()));
            st2.pop();
        }
        cout << st1.top() << endl;
    }
}