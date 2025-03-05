#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll Swap(string s, char a, char b)
{
    ll n = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == a)
            s[i] = b;
        n = n * 10 + (s[i] - '0');
    }
    return n;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << Swap(s1, '6', '5') + Swap(s2, '6', '5') << " " << Swap(s1, '5', '6') + Swap(s2, '5', '6') << endl;
}