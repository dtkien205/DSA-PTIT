#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[505][505], tmp[505][505];
int n, m;

int Smax(int a[], int n)
{
    int L[n], R[n];
    stack<int> st;
    // ben phai dau tien nho nhat
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
    // ben trai dau tien nho nhat
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
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, (R[i] - L[i] - 1) * a[i]);
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0)
                    tmp[i][j] = a[i][j];
                else
                    tmp[i][j] = tmp[i - 1][j] + a[i][j];
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++)
            res = max(res, Smax(tmp[i], m));
        cout << res << endl;
    }
}