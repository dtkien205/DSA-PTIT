#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

// Bi = Bi-1 xor Gi
// B[0] = G[0]

string grayToBinary(string s)
{
    string res = "";
    res += s[0];
    for (int i = 1; i < s.size(); i++)
        res += to_string(res[i - 1] ^ s[i]);
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << grayToBinary(s) << endl;    
    }
}