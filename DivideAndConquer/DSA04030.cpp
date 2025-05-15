#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e15 + 7;

ll binMul(ll base, ll exp)
{
    ll res = 0;
    while (exp) {
        if (exp & 1)
            res = (res + base) % MOD;
        base = (base + base) % MOD;
        exp >>= 1;
    }
    return res;
}

class Matrix {
private:
    vector<vector<ll>> mat;

public:
    Matrix()
    {
        mat.assign(4, vector<ll>(4, 0));
    }

    Matrix(vector<vector<ll>> values)
    {
        mat = values;
    }

    Matrix operator*(const Matrix& other) const
    {
        Matrix res;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                for (int k = 0; k < 4; ++k)
                    res.mat[i][j] = (res.mat[i][j] + binMul(this->mat[i][k], other.mat[k][j])) % MOD;
        return res;
    }

    Matrix binPow(int exp)
    {
        if (exp == 1)
            return *this;
        Matrix res = binPow(exp >> 1);
        res = res * res;
        if (exp & 1)
            res = res * (*this);
        return res;
    }

    ll sumTribonacci()
    {
        int base[] = { 3, 2, 1, 6 };
        ll total = 0;
        for (int i = 0; i < 4; ++i)
            total = (total + binMul(this->mat[3][i], base[i])) % MOD;
        return total;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        if (N <= 3) {
            cout << (1LL * N * (N + 1) / 2) % MOD << endl;
            continue;
        }

        Matrix A({ { 1, 1, 1, 0 },
            { 1, 0, 0, 0 },
            { 0, 1, 0, 0 },
            { 1, 1, 1, 1 } });

        Matrix res = A.binPow(N - 3);
        cout << res.sumTribonacci() << endl;
    }
}