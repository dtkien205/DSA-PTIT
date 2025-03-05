#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void insertionSort(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        int pos = i;
        while (pos > 0 && a[pos] < a[pos - 1]) {
            swap(a[pos], a[pos - 1]);
            pos--;
        }

        cout << "Buoc " << i << ": ";
        for (int j = 0; j <= i; j++)
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
    insertionSort(a, n);
}