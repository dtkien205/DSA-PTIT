#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

// ct tạo số gray: i xor (i >> 1)

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < (1 << n); i++) {
            // (1 << n) : pow(2, n)
            int value = i ^ (i >> 1);
            bitset<11> tmp(value); // chuyển từ số thập phân sang nhị phân
            string res = tmp.to_string();
            cout << res.substr(11 - n) << " ";
        }
        cout << endl;
    }
}