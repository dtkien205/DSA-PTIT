#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int a[n];
        for (int &i : a) cin >> i;
        sort(a, a + n);
        for (auto i : a) cout << i << ' ';
        cout << endl; 
    }
}