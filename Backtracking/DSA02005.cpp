#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

string s;
int used[100] = { 0 };
char x[100];

void Try(int i)
{
    if (i == s.size()) {
        for (int u = 0; u < i; u++)
            cout << x[u];
        cout << ' ';
        return;
    }

    for (int j = 0; j < s.size(); j++) {
        if (!used[j]) {
            x[i] = s[j];
            used[j] = 1;
            Try(i + 1);
            used[j] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        Try(0);
        cout << endl;
    }
}