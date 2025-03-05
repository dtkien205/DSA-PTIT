#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int check(vector<int> a, int n, int k)
{
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n; j++) {
            if (binary_search(a.begin() + j + 1, a.end(), k - a[i] - a[j]))
                return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());

        if (check(a, n, k))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}