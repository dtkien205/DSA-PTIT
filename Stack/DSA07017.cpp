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
        int a[n], nextGreater[n], rightSmaller[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        stack<int> st;

        // lon hon dau tien ben phai
        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[i] > a[st.top()]) {
                nextGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }

        // nho hon dau tien ben phai
        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[i] < a[st.top()]) {
                rightSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            rightSmaller[st.top()] = -1;
            st.pop();
        }

        for (int i = 0; i < n; i++) {
            if (nextGreater[i] == -1 || rightSmaller[nextGreater[i]] == -1)
                cout << -1 << ' ';
            else
                cout << a[rightSmaller[nextGreater[i]]] << ' ';
        }
        cout << endl;
    }
}