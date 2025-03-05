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
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[i] >= a[st.top()])
                st.pop();
            cout << (st.empty() ? i + 1 : i - st.top()) << ' ';
            st.push(i);
        }
        cout << endl;
    }
}