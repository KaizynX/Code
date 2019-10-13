#include <cmath>
#include <complex>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e6+5e4+7;
const double PI = acos(-1);

int n, m;
complex<double> f[MAXN<<1], g[MAXN<<1];

void FFT(complex<double> *a, int len, int flag)
{
    if (len <= 1) return;
    static complex<double> tmp[MAXN<<1];
    for (int i = 0; i < len/2; ++i) {
        tmp[i] = a[i*2];
        tmp[i+len/2] = a[i*2+1];
    }
    for (int i = 0; i < len; ++i) a[i] = tmp[i];
    FFT(a, len>>1, flag);
    FFT(a+len/2, len>>1, flag);
    complex<double> w = { 1, 0 }, wn = { cos(2.0*PI/len), flag*sin(2.0*PI/len) };
    for (int i = 0; i < len/2; ++i) {
        tmp[i] = a[i]+w*a[i+len/2];
        tmp[i+len/2] = a[i]-w*a[i+len/2];
        w *= wn;
    }
    for (int i = 0; i < len; ++i) a[i] = tmp[i];
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
