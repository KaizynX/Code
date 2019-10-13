#include <bits/stdc++.h>

using namespace std;

const int N = 3e3+7;

int n;
int a[N], m[N][N];

template <typename T> inline double qsqrt(T x)
{
    static const double efs = 1e-1;
    double k = 1.0;
    while (abs(k*k-x) > efs)
        k = (k+x/k)/2;
    return k;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        a[i] = static_cast<int>(qsqrt(1ll*m[i][(i+1)%n]*m[i][(i+2)%n]/m[(i+1)%n][(i+2)%n])+0.5);
        cout << a[i] << " \n"[i==n-1];
    }
    return 0;
}
