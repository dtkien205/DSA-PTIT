#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m, s;
        cin >> n >> s >> m;
        int totalFood = m * s;
        int day = s - s / 7; // trừ chủ nhật
        int dayMin = (totalFood + (n - 1)) / n;
        if (dayMin <= day)
            cout << dayMin << endl;
        else
            cout << "-1" << endl;
    }
}