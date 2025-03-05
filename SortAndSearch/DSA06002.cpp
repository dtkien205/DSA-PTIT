#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, x;

int cmp(int a, int b)
{
    return abs(x - a) < abs(x - b);
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        int a[n];
        for (int& i : a)
            cin >> i;
        stable_sort(a, a + n, cmp);
        for (auto i : a)
            cout << i << ' ';
        cout << endl;
    }
}