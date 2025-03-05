#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        queue<int> q;
        int n;
        cin >> n;
        while (n--) {
            int choice;
            cin >> choice;
            if (choice == 1)
                cout << q.size() << endl;
            else if (choice == 2)
                cout << (q.empty() ? "YES\n" : "NO\n");
            else if (choice == 3) {
                int x;
                cin >> x;
                q.push(x);
            } else if (choice == 4) {
                if (!q.empty())
                    q.pop();
            } else if (choice == 5) {
                if (!q.empty())
                    cout << q.front() << endl;
                else
                    cout << -1 << endl;
            } else {
                if (!q.empty())
                    cout << q.back() << endl;
                else
                    cout << -1 << endl;
            }
        }
    }
}