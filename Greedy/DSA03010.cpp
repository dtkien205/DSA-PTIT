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
        priority_queue<int, vector<int>, greater<int>> pq;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            pq.push(x);
        }
        while (pq.size() > 1) {
            int num1 = pq.top();
            pq.pop();
            int num2 = pq.top();
            pq.pop();
            sum += num1 + num2;
            pq.push(num1 + num2);
        }
        cout << sum << endl;
    }
}