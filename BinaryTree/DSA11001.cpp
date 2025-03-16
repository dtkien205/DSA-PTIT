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
        for (auto x : s) {
            if (isalpha(x))
                st.push(string(1, x));
            else {
                string o1 = st.top();
                st.pop();
                string o2 = st.top();
                st.pop();
                st.push(o2 + x + o1);
            }
        }
        cout << st.top() << endl;
    }
}