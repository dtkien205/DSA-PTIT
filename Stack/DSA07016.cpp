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
        stack<int> st;
        st.push(1);
        int cnt = 1;
        for (auto x : s) {
            if (x == 'D')
                st.push(++cnt);
            else {
                while (!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
                st.push(++cnt);
            }
        }
        while (!st.empty()) {
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }
}