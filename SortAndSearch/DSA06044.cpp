#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        if(i % 2 == 0) a.push_back(x);
        else b.push_back(x); 
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());
    for (int i = 0; i < a.size(); i++)
        cout << b[i] << ' ' << a[i] << ' ';
    if(n % 2) cout << b[b.size() - 1] << ' ';
}