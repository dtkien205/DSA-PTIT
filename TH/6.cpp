#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    int test;
    cin >> test;
    while (test--) {
        string s;
        getline(cin >> ws, s);
        stack<string> st;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (isalpha(s[i]))
                st.push(string(1, s[i]));
            else {
                string o1 = st.top(); st.pop();
                string o2 = st.top(); st.pop();
                st.push("(" + o1 + s[i] + o2 +")");
            }
        }
        cout << st.top() << endl;
    }
}