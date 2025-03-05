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
        set<int> st;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            st.insert(x);
        }
        if (st.size() < 2)
            cout << "-1" << endl;
        else {
            auto pos = st.begin();
            cout << *pos << " " << *(++pos) << endl;
        }
    }
}