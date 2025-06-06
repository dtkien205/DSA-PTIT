#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

tuple<int, int, int> Smax(int a[], int n)
{
    vector<int> L(n + 1, 0);
    vector<int> R(n + 1, n + 1);
    stack<int> st;

    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[i] < a[st.top()]) {
            L[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty())
        st.pop();

    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[i] < a[st.top()]) {
            R[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    int x = 0, y = 0, z = 0;
    for (int i = 1; i <= n; i++) {
        int r = R[i] - L[i] - 1;
        int s = r * a[i];
        if (s > z || (s == z && abs(r - a[i]) < abs(x - y))) {
            z = s;
            x = r;
            y = a[i];
        }
    }
    return { x, y, z };
}

int a[1005][1005], tmp[1005][1005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        int n, m;

        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> tmp[i][j];
                if (tmp[i][j])
                    a[i][j] = a[i - 1][j] + 1;
                else
                    a[i][j] = 0;
            }
        }

        int x, y, z;
        x = y = z = 0;
        for (int i = 1; i <= n; i++) {
            auto [r, h, s] = Smax(a[i], m);
            if (s > z || (s == z && abs(r - h) < abs(x - y))) {
                z = s;
                x = r;
                y = h;
            }
        }
        cout << min(x, y) << ' ' << max(x, y) << endl;
    }
}