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
        // L[i]: ptu lon nhat tu trai qua
        // R[i]: ptu nho nhat tu phai qua
        L[0] = a[0];
        for (int i = 1; i < n; i++)
            L[i] = max(a[i], L[i - 1]);
        R[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
            R[i] = min(a[i], R[i + 1]);

        vector<int> res;
        for (int i = 0; i < n - 1; i++) {
            if (L[i] <= R[i + 1])
                res.push_back(i);
        }
        cout << res.size() << endl;
        for (auto x : res)
            cout << x + 1 << ' ';
        cout << endl;
    }
}