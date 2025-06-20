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

        vector<float> A(N), B(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i] >> B[i];

        vector<int> dp(N + 1, 1);
        for (int i = 1; i < N; ++i)
            for (int j = 0; j < i; ++j)
                if (A[j] < A[i] and B[j] > B[i])
                    dp[i] = max(dp[i], dp[j] + 1);

        cout << *max_element(dp.begin(), dp.end()) << endl;
    }
}