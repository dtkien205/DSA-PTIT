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
        stack<string> st;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (isalpha(s[i]))
                st.push(string(1, s[i]));
            else {
                string o1 = st.top(); st.pop();
                string o2 = st.top(); st.pop();
                st.push(o1 + o2 + s[i]);
            }
        }
        cout << st.top() << endl;
    }
}