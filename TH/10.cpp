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
        for (char x : s) {
            if (isalpha(x))
                st.push(string(1, x));
            else {
                string o1 = st.top();
                st.pop();
                string o2 = st.top();
                st.pop();
                st.push("(" + o2 + x + o1 + ")");
            }
        }
        cout << st.top() << endl;
    }
}