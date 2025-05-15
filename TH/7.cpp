#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[i] > a[st.top()]) {
                b[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            b[st.top()] = -1;
            st.pop();
        }

        for (int x : b)
            cout << x << ' ';
        cout << endl;
    }
}