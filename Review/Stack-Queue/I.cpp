#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    ll a[n];
    for (ll& i : a)
        cin >> i;

    stack<ll> st;
    for (int i = 0; i < n; i++) {
        if (st.empty())
            st.push(a[i]);
        else if ((a[i] + st.top()) % 2 == 0) {
            st.pop();
        } else
            st.push(a[i]);
    }
    // while (!st.empty()) {
    //     cout << st.top() << ' ';
    //     st.pop();
    // }
    cout << st.size() << endl;
}