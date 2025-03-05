#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << x << ' ';
        string s;
        cin >> s;

        // gen
        int n = s.size() - 1;
        int i = n - 1;
        while (s[i] >= s[i + 1] && i >= 0)
            i--;
        if (i == -1)
            cout << "BIGGEST" << endl;
        else {
            int j = n;
            while (s[i] >= s[j])
                j--;
            swap(s[i], s[j]);

            int l = i + 1, r = n;
            while (l < r) {
                swap(s[l], s[r]);
                l++;
                r--;
            }
            cout << s << endl;
        }
    }
}