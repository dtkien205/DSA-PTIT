#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int ans = 0;
        for (int i = 9; i >= 0; i--){
            ans += n / a[i];
            n %= a[i];
        }
        cout << ans << endl;
    }
}