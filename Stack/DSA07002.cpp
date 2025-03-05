#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    vector<int> v;
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        if (s == "PUSH") {
            int x;
            cin >> x;
            v.push_back(x);
        } else if (s == "PRINT") {
            if (v.empty())
                cout << "NONE\n";
            else
                cout << v.back() << endl;
        } else {
            if (!v.empty())
                v.pop_back();
        }
    }
}