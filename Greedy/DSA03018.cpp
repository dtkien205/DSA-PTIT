#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    int seven = n / 7;
    int four = n % 7;
    while (four % 4 != 0 && seven > 0 && four <= 28) {
        seven--;
        four += 7;
    }
    if (four % 4 == 0)
        four /= 4;
    else {
        cout << "-1" << endl;
        return;
    }
    while (four--)
        cout << "4";
    while (seven--)
        cout << "7";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}