#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        string s;
        getline(cin >> ws, s);

        int cnt = 0;
        stack<int> st;
        for (auto x : s) {
            if (x == '(') {
                st.push(++cnt);
                cout << cnt << ' ';
            }
            if (x == ')') {
                cout << st.top() << ' ';
                st.pop();
            }
        }
        cout << endl;
    }
}