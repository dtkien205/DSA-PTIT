#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[1005][1005], tmp[1005][1005];
int n, m;

tuple<int, int, int> Smax(int a[], int n)
{
    vector<int> L(n + 1), R(n + 1);
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
    int S = 0, h = 0, w = 0;
    for (int i = 0; i < n; i++) {
        int r = R[i] - L[i] - 1;
        int s = r * a[i];
        if (s > S || (s == S && abs(h - w) > abs(r - a[i]))) {
            S = s;
            w = r;
            h = a[i];
        }
    }
    return { S, w, h };
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                if (a[i][j] == 1)
                    tmp[i][j] = (i == 0 ? 1 : tmp[i - 1][j] + 1);
                else
                    tmp[i][j] = 0;
            }
        }
        int S = 0, h = 0, w = 0;
        for (int i = 0; i < n; i++) {
            auto [x, y, z] = Smax(tmp[i], m);
            if (x > S || (x == S && abs(h - w) > abs(y - z))) {
                S = x;
                w = y;
                h = z;
            }
        }
        cout << min(w, h) << ' ' << max(w, h) << endl;
    }
}