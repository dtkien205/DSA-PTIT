#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (auto& i : a)
            cin >> i;
        ll currentSum = 0, maxSum = 0;
        for (auto i : a) {
            currentSum = max(i, currentSum + i);
            maxSum = max(maxSum, currentSum);
        }
        cout << maxSum << endl;
    }
}