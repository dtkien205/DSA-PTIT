#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        getline(cin >> ws, s);
        int i = s.size() - 1;
        while (i >= 0 && s[i] == '0') {
            s[i] = '1';
            i--;
        }
        if (i >= 0)
            s[i] = '0'; 
        cout << s << endl;
    }
}