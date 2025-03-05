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
        stringstream ss(s);
        string w;
        stack<string> st;
        while (ss >> w)
            st.push(w);
        while (!st.empty()) {
            cout << st.top() << ' ';
            st.pop();
        }
        cout << endl;
    }
}