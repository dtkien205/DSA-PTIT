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
        string s = "";
        for (int i = n; i >= 1; i--)
            s += to_string(i);
        do {
            cout << s << " ";
        } while (prev_permutation(s.begin(), s.end()));
        cout << endl;
    }
}