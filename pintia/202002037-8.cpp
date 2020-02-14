#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

struct Rt
{
    int n, m;
    int v[N][N];
    Rt() { memset(v, 0, sizeof v); }
    friend istream& operator >> (istream &is, Rt &rt) {
        is >> rt.n >> rt.m;
        for (int i = 1; i <= rt.n; ++i)
            for (int j = 1; j <= rt.m; ++j)
                is >> rt.v[i][j];
        return is;
    }
    friend ostream& operator << (ostream &os, Rt &rt) {
        os << rt.n << " " << rt.m << endl;
        for (int i = 1; i <= rt.n; ++i)
            for (int j = 1; j <= rt.m; ++j)
                os << rt.v[i][j] << " \n"[j == rt.m];
        return os;
    }
    friend Rt operator * (const Rt &r1, const Rt &r2) {
        Rt res;
        res.n = r1.n; res.m = r2.m;
        for (int i= 1; i <= res.n; ++i)
            for (int j = 1; j <= res.m; ++j)
                for (int k = 1; k <= r1.m; ++k)
                    res.v[i][j] += r1.v[i][k]*r2.v[k][j];
        return res;
    }
} a, b;

int main()
{
    cin >> a >> b;
    if (a.m != b.n) {
        cout << "Error: " << a.m << " != " << b.n << endl;
    } else {
        a = a*b;
        cout << a;
    }
    return 0;
}
