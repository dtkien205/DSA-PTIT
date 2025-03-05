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
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            a[i] = i;
        int ok = 1;
        while (ok) {
            for (int i = 1; i <= n; i++)
                cout << a[i];
            cout << ' ';
            int i = n - 1;
            while (i >= 1 && a[i] > a[i + 1])
                i--;
            if(i == 0) ok = 0;
            int j = n;
            while(a[i] > a[j]) j--;
            swap(a[i], a[j]);
            int l = i + 1, r = n;
            while(l < r){
                swap(a[l], a[r]);
                l++; r--;
            }
        }
        cout << endl;
    }
}