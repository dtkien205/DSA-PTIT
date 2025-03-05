#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

string solve(int n)
{
    queue<string> q;
    q.push("9");

    while (!q.empty()) {
        string num = q.front();
        q.pop();

        if (stoll(num) % n == 0)
            return num;
        q.push(num + "0");
        q.push(num + "9");
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
}