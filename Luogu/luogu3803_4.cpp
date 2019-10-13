#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e6+5e4+7;
const double PI = acos(-1);

int n, m, bit, len = 1;
int rev[MAXN<<1];

struct complex
{
    double real = 0.0, imag = 0.0;
    complex () {}
    complex (int _real, int _imag) : real(_real), imag(_imag) {}
    complex (double _real, double _imag) : real(_real), imag(_imag) {}

    complex operator + (const complex &b)
    {
        return complex(this->real+b.real, this->imag+b.imag);
    }

    complex operator - (const complex &b)
    {
        return complex(this->real-b.real, this->imag-b.imag);
    }

    complex operator * (const complex &b)
    {
        return complex(this->real*b.real-this->imag*b.imag, this->real*b.imag+this->imag*b.real);
    }

    complex operator *= (const complex &b)
    {
        return *this = *this*b;
    }
} f[MAXN<<1], g[MAXN<<1];

void FFT(complex a[], int flag)
{
    for (int i = 0; i < len; ++i) {
        if (i < rev[i]) swap(a[i], a[rev[i]]);
    }
    for (int base = 1; base < len; base <<= 1) {
        complex w, wn = { cos(PI/base), flag*sin(PI/base) };
        for (int i = 0; i < len; i += base*2) {
            w = { 1.0, 0.0 };
            for (int j = 0; j < base; ++j) {
                complex x = a[i+j], y = w*a[i+j+base];
                a[i+j] = x+y;
                a[i+j+base] = x-y;
                w *= wn;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0, a; i <= n; ++i) {
        scanf("%d", &a);
        f[i] = { 1.0*a, 0.0 };
    }
    for (int i = 0, a; i <= m; ++i) {
        scanf("%d", &a);
        g[i] = { 1.0*a, 0.0 };
    }

    while (len <= n+m) len <<= 1, ++bit;
    for (int i = 0; i < len; ++i)
        rev[i] = (rev[i>>1]>>1)|((i&1)<<(bit-1));

    FFT(f, 1);
    FFT(g, 1);
    for (int i = 0; i <= len; ++i) {
        f[i] *= g[i];
    }
    FFT(f, -1);
    for (int i = 0; i <= n+m; ++i) {
        printf("%d%c", static_cast<int>(f[i].real/len+0.5), " \n"[i==n+m]);
    }
    return 0;
}
