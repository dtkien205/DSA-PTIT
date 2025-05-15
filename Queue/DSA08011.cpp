#include <bits/stdc++.h>
using namespace std;

unordered_set<string> dictionary;

int bfs(string s, string t)
{
    queue<pair<string, int>> q;
    q.push({ s, 1 });

    while (!q.empty()) {
        auto [cur, cnt] = q.front();
        q.pop();
        for (int i = 0; i < cur.size(); i++) {
            char x = cur[i];

            for (char c = 'A'; c <= 'Z'; c++) {
                if (c == x)
                    continue;
                cur[i] = c;
                if (cur == t)
                    return cnt + 1;

                if (dictionary.count(cur)) {
                    dictionary.erase(cur);
                    q.push({ cur, cnt + 1 });
                }
            }
            cur[i] = x;
        }
    }

    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        dictionary.clear();
        int n;
        string s, t;
        cin >> n >> s >> t;
        for (int i = 0; i < n; i++) {
            string word;
            cin >> word;
            dictionary.insert(word);
        }
        cout << bfs(s, t) << endl;
    }
    return 0;
}
