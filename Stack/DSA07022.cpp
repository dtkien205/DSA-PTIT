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
        int a[n];
        stack<int> st;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }
        int res[n];
        for (int i = 0; i < n; i++) {
            while (!st.empty() && mp[a[i]] > mp[a[st.top()]]) {
                res[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            res[st.top()] = -1;
            st.pop();
        }
        for (auto x : res)
            cout << x << ' ';
        cout << endl;
    }
}