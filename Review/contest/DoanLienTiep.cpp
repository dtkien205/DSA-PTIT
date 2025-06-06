// TN04003
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> res(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[st.top()] <= a[i]) {
                st.pop();
            }
            if (st.empty())
                res[i] = i + 1;
            else
                res[i] = i - st.top();
            st.push(i);
        }
        for (int i = 0; i < n; i++)
            cout << res[i] << ' ';
        cout << endl;
    }
}