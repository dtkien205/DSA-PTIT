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
        getline(cin >> ws, s);
        stack<string> st;
        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i]))
                st.push(string(1, s[i]));
            else {
                string o1 = st.top();
                st.pop();
                string o2 = st.top();
                st.pop();
                st.push(s[i] + o2 + o1);
            }
        }
        cout << st.top() << endl;
    }
}