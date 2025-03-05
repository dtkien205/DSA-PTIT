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
        int a[n], L[n], R[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        stack<int> st;

        // nho hon dau tien ben phai
        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[i] < a[st.top()]) {
                R[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            R[st.top()] = n;
            st.pop();
        }

        // nho hon dau tien ben trai
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && a[i] < a[st.top()]) {
                L[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            L[st.top()] = -1;
            st.pop();
        }

        ll res = 0;
        for (int i = 0; i < n; i++)
            res = max(res, 1ll * (R[i] - L[i] - 1) * a[i]);
        cout << res << endl;
    }
}