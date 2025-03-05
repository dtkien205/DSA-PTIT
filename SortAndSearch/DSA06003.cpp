#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int cnt = 0;

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        int pos = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[pos])
                pos = j;
        }
        if (pos != i) {
            swap(a[pos], a[i]);
            cnt++;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int& i : a)
            cin >> i;
        cnt = 0;
        selectionSort(a, n);
        cout << cnt << endl;
    }
}