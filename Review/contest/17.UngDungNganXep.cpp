#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    a[0] = a[n + 1] = 1e9 + 5; // sentinel lớn

    vector<int> L(n + 2), R(n + 2);
    stack<int> st;

    // Tìm R[i]: vị trí gần nhất bên phải lớn hơn a[i]
    for (int i = n; i >= 1; --i) {
        while (!st.empty() && a[st.top()] <= a[i])
            st.pop();
        R[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += R[i] - i;
    }

    cout << ans << '\n';
}
