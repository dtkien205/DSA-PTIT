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
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int L[n], R[n];
        stack<int> st;

        // trai dau tien nho hon
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
        // phai dau tien nho hon
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

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (R[i] - L[i] - 1 >= a[i])
                res = max(res, a[i]);
        }
        cout << res << endl;
    }
}