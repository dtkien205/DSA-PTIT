#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<int> st;
        st.push(-1);
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                st.push(i);
            else {
                st.pop();
                if (!st.empty()) {
                    res = max(res, i - st.top());
                } else
                    st.push(i);
            }
        }
        cout << res << endl;
    }
}