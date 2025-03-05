#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<char> st;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (auto c : s)
                st.insert(c);
        }
        for (auto i : st)
            cout << i << ' ';
        cout << endl;
    }
}