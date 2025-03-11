#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

string s, res;
char ope[] = { '+', '-' };
bool ok;

int cal(int a, int b, char x)
{
    return (x == '+') ? (a + b) : (a - b);
}

bool check(string s)
{
    int o1 = stoi(s.substr(0, 2));
    int o2 = stoi(s.substr(5, 2));
    int res = stoi(s.substr(10, 2));
    if (o1 < 10 || o2 < 10 || res < 10) 
        return false;
    return cal(o1, o2, s[3]) == res;
}

void Try(int i)
{
    if (ok)
        return;
    if (i == s.size()) {
        if (check(s)) {
            ok = true;
            cout << s << endl;
        }
        return;
    }

    if (s[i] == '?') {
        if (i == 3) {
            for (int j = 0; j < 2; j++) {
                s[i] = ope[j];
                Try(i + 1);
            }
        } else {
            for (char j = '0'; j <= '9'; j++) {
                s[i] = j;
                Try(i + 1);
            }
        }
        s[i] = '?';
    } else
        Try(i + 1);
}

void solve()
{
    ok = false;
    getline(cin, s);
    if (s[3] == '*' || s[3] == '/') {
        cout << "WRONG PROBLEM!\n";
        return;
    }
    Try(0);
    if (!ok)
        cout << "WRONG PROBLEM!\n";
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        solve();
    }
}