#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int prime[10001]; // N = 10^7

void sieve()
{
    for (int i = 0; i <= 10000; i++)
        prime[i] = 1;
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= sqrt(10000); i++) {
        if (prime[i]) {
            for (int j = i * i; j <= 10000; j += i)
                prime[j] = 0;
        }
    }
}

int bfs(int s, int t)
{
    set<int> se;
    queue<pair<int, int>> q;
    q.push({ s, 0 });
    se.insert(s);
    while (!q.empty()) {
        auto [n, cnt] = q.front();
        q.pop();
        string u = to_string(n);
        if (n == t)
            return cnt;

        for (int i = 0; i < 4; i++) {
            string tmp = u;
            for (char c = '0'; c <= '9'; c++) {
                if (i == 0 && c == '0')
                    continue;
                tmp[i] = c;
                int num = stoi(tmp);

                if (prime[num] && !se.count(num)) {
                    se.insert(num);
                    q.push({ num, cnt + 1 });
                }
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    sieve();
    while (t--) {
        int s, t;
        cin >> s >> t;
        cout << bfs(s, t) << endl;
    }
}