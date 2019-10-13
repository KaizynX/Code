#include <cmath>
#include <complex>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e6+7;
const double PI = acos(-1);

int n, m;
complex<double> f[MAXN<<1], g[MAXN<<1];

void FFT(complex<double> *a, int len, int flag)
{
    if (len <= 1) return;
    complex<double> a1[len>>1], a2[len>>1];
    for (int i = 0; i < len/2; ++i) {
        a1[i] = a[i*2];
        a2[i] = a[i*2+1];
    }
    FFT(a1, len>>1, flag);
    FFT(a2, len>>1, flag);
    complex<double> w = { 1, 0 }, wn = { cos(2.0*PI/len), flag*sin(2.0*PI/len) };
    for (int i = 0; i < len/2; ++i) {
        a[i] = a1[i]+w*a2[i];
        a[i+len/2] = a1[i]-w*a2[i];
        w *= wn;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0, a; i <= n; ++i) {
        cin >> a;
        f[i] = { 1.0*a, 0.0 };
    }
    for (int i = 0, a; i <= m; ++i) {
        cin >> a;
        g[i] = { 1.0*a, 0.0 };
    }
    int len = 1;
    while (len <= n+m) len <<= 1;
    FFT(f, len, 1);
    FFT(g, len, 1);
    for (int i = 0; i <= len; ++i) {
        f[i] *= g[i];
    }
    FFT(f, len, -1);
    for (int i = 0; i <= n+m; ++i) {
        cout << static_cast<int>(f[i].real()/len+0.5) << " ";
    }
    cout << endl;
    return 0;
}
