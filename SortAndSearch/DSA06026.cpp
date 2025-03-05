#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int check = 1;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                check = 0;
            }
        }
        if (check)
            continue;
        cout << "Buoc " << i + 1 << ": ";
        for (int j = 0; j < n; j++)
            cout << a[j] << ' ';
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bubbleSort(a, n);
}