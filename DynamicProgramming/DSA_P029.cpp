#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        int N;
        cin >> N;

        vector<vector<int>> mat(N, vector<int>(N));
        for (auto& row : mat)
            for (auto& cell : row)
                cin >> cell;

        vector<vector<int64_t>> dp(1 << N, vector<int64_t>(N, INT_MAX));
        for (int i = 0; i < N; ++i)
            dp[1 << i][i] = 0;

        for (int mask = 1; mask < (1 << N); ++mask) {
            for (int row = 0; row < N; ++row) {
                if (mask & (1 << row)) {
                    for (int col = 0; col < N; ++col) {
                        if (!(mask & (1 << col))) {
                            int new_mask = mask | (1 << col);
                            dp[new_mask][col] = min(dp[new_mask][col], dp[mask][row] + mat[row][col]);
                        }
                    }
                }
            }
        }

        cout << *min_element(dp[(1 << N) - 1].begin(), dp[(1 << N) - 1].end()) << endl;
    }
}
