#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int cal(char c)
{
    if (c == 'H')
        return 1;
    else if (c == 'O')
        return 16;
    else if (c == 'C')
        return 12;
    return 0;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++) {
        cout << "Test #" << t << ": ";
        string s;
        getline(cin >> ws, s);

        stack<ll> st;

        for (auto x : s) {
            if (x == '(')
                st.push(-1);
            else if (x == 'C' || x == 'H' || x == 'O')
                st.push(cal(x));
            else if (isdigit(x)) {
                ll n = st.top();
                st.pop();
                st.push(n * (x - '0'));
            } else if (x == ')') {
                ll sum = 0;
                while (!st.empty() && st.top() != -1) {
                    sum += st.top();
                    st.pop();
                }
                st.pop();
                st.push(sum);
            }
        }

        ll res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        cout << res << endl;
    }
}
