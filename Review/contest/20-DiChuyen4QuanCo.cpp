#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define State vector<pair<int, int>>

int dx[] = { -1, 0, 1, 0 }; // Lên, Phải, Xuống, Trái
int dy[] = { 0, 1, 0, -1 };

bool check(int x, int y)
{
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

bool bfs(State st, State en)
{
    queue<pair<State, int>> q;
    set<State> vs;

    sort(st.begin(), st.end());
    sort(en.begin(), en.end());

    q.push({ st, 0 });
    vs.insert(st);

    while (!q.empty()) {
        auto [cur, step] = q.front();
        q.pop();

        if (cur == en)
            return true;
        if (step >= 8)
            continue;

        for (int i = 0; i < 4; ++i) {
            for (int dir = 0; dir < 4; ++dir) {
                auto [x, y] = cur[i];
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                bool hasPiece = false;
                for (int j = 0; j < 4; ++j)
                    if (j != i && cur[j].first == nx && cur[j].second == ny)
                        hasPiece = true;

                if (check(nx, ny) && !hasPiece) {
                    State next = cur;
                    next[i] = { nx, ny };
                    sort(next.begin(), next.end());
                    if (!vs.count(next)) {
                        vs.insert(next);
                        q.push({ next, step + 1 });
                    }
                } else if (hasPiece) {
                    int jx = nx + dx[dir];
                    int jy = ny + dy[dir];
                    bool blocked = false;
                    for (int j = 0; j < 4; ++j)
                        if (cur[j].first == jx && cur[j].second == jy)
                            blocked = true;

                    if (check(jx, jy) && !blocked) {
                        State next = cur;
                        next[i] = { jx, jy };
                        sort(next.begin(), next.end());
                        if (!vs.count(next)) {
                            vs.insert(next);
                            q.push({ next, step + 1 });
                        }
                    }
                }
            }
        }
    }

    return false;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        State st(4), en(4);
        for (int i = 0; i < 4; ++i)
            cin >> st[i].first >> st[i].second;
        for (int i = 0; i < 4; ++i)
            cin >> en[i].first >> en[i].second;

        cout << (bfs(st, en) ? "YES\n" : "NO\n");
    }
}
