#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool check(string s, int n)
{
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
        sum = sum * 10 + (s[i] - '0');
    return sum % n == 0;
}

void gen(int n)
{
    queue<string> q;
    q.push("9");
    while (1) {
        string s = q.front();
        q.pop();
        if (check(s, n)) {
            cout << s << endl;
            return;
        }
        q.push(s + "0");
        q.push(s + "9");
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        gen(n);
    }
}