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
        multiset<int> st;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            st.insert(x);
        }
        for (auto i : st)
            cout << i << ' ';
        cout << endl;
    }
}