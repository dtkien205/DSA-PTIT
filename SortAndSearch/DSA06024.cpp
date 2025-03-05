#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minPos])
                minPos = j;
        }
        swap(a[i], a[minPos]);
        
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
    selectionSort(a, n);
}