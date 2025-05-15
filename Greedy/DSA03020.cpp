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
        int res = 0, d1 = 0, d2 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[') d1++;
            else d2++;
            if(d2 > d1) {
                for (int j = i + 1; j < s.size(); j++){
                    if(s[i] != s[j]){ //tim cai ']' gan nhat de doi cho
                        swap(s[i], s[j]);
                        d1++; d2--;
                        res += j - i;
                        break;
                    }
                }
            }
        }
        cout << res << endl;
    }
}