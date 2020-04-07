/*
 * @Author: Kaizyn
 * @Date: 2020-04-06 16:48:59
 * @LastEditTime: 2020-04-07 11:05:02
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#define DEBUG
using namespace std;
typedef long long ll;
const int N = (1<<18) + 5, mo = 1e6+3, P = 1e6+3;
const double PI = acos(-1.0);
inline int read() {
    char c=getchar(); int x=0,f=1;
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
    return x*f;
}
 
struct meow{
    double x, y;
    meow(double a=0, double b=0):x(a), y(b){}
};
meow operator +(meow a, meow b) {return meow(a.x+b.x, a.y+b.y);}
meow operator -(meow a, meow b) {return meow(a.x-b.x, a.y-b.y);}
meow operator *(meow a, meow b) {return meow(a.x*b.x-a.y*b.y, a.x*b.y+a.y*b.x);}
meow conj(meow a) {return meow(a.x, -a.y);}
typedef meow cd;
 
namespace fft {
    int maxlen, rev[N];
    cd omega[N], omegaInv[N];
    void init(int lim) {
        maxlen = 1; while(maxlen < lim) maxlen<<=1;
        for(int i=0; i<maxlen; i++) {
            omega[i] = cd(cos(2*PI/maxlen*i), sin(2*PI/maxlen*i));
            omegaInv[i] = conj(omega[i]);
        }
    }
    void dft(cd *a, int n, int flag) {
        cd *w = flag == 1 ? omega : omegaInv;
        int k = 0; while((1<<k) < n) k++;
        for(int i=0; i<n; i++) {
            rev[i] = (rev[i>>1]>>1) | ((i&1)<<(k-1));
            if(i < rev[i]) swap(a[i], a[rev[i]]);
        }
        for(int l=2; l<=n; l<<=1) {
            int m = l>>1;
            for(cd *p = a; p != a+n; p += l) 
                for(int k=0; k<m; k++) {
                    cd t = w[maxlen/l*k] * p[k+m];
                    p[k+m] = p[k] - t;
                    p[k] = p[k] + t;
                }
        }
        if(flag == -1) for(int i=0; i<n; i++) a[i].x /= n;
    }
 
    cd a[N], b[N], c[N], d[N];
    
    void mul_any(int *x, int *y, int lim) {
        int n = maxlen;
        for(int i=0; i<lim; i++) {
            a[i] = cd(x[i]>>15), b[i] = cd(x[i]&32767);
            c[i] = cd(y[i]>>15), d[i] = cd(y[i]&32767);
        }
        for(int i=lim; i<n; i++) a[i] = b[i] = c[i] = d[i] = cd();
        dft(a, n, 1); dft(b, n, 1); dft(c, n, 1); dft(d, n, 1);
        for(int i=0; i<n; i++) {
            cd _a = a[i], _b = b[i], _c = c[i], _d = d[i];
            a[i] = _a * _c;
            b[i] = _a * _d + _b * _c;
            c[i] = _b * _d;
        }
        dft(a, n, -1); dft(b, n, -1); dft(c, n, -1);
        for(int i=0; i<lim; i++) x[i] = ( (ll(a[i].x + 0.5) %mo <<30) + (ll(b[i].x + 0.5) %mo <<15) + ll(c[i].x + 0.5)%mo) %mo;
    }
}
 
inline ll Pow(ll a, int b) {
    ll ans = 1;
    for(; b; b>>=1, a=a*a%P)
        if(b&1) ans=ans*a%P;
    return ans;
}
int n, a[N], b, c, d, p[N], g[N], f[N], c2[N];
ll inv[N], fac[N], facInv[N];
int main() {
    // freopen("in", "r", stdin);
    n=read(); b=read(); c=read(); d=read();
    for(int i=0; i<n; i++) a[i] = read();
    fft::init(n+n+1);
    
    inv[1] = fac[0] = facInv[0] = 1;
    for(int i=1; i<=n; i++) {
        if(i != 1) inv[i] = (P-P/i) * inv[P%i] %P;
        fac[i] = fac[i-1] * i %P;
        facInv[i] = facInv[i-1] * inv[i] %P;
    }
 
    ll mi = 1;
    for(int i=0; i<=n; i++, mi = mi * d %P) p[i] = a[n-i] * fac[n-i] %P, g[i] = mi * facInv[i] %P;
    fft::mul_any(p, g, n+1);
    for(int i=0; i<=n>>1; i++) swap(p[i], p[n-i]);
    #ifdef DEBUG
    for (int i = 0; i < n; ++i) cout << p[i] << " \n"[i==n-1];
    #endif
 
    mi = 1;
    memset(g, 0, sizeof(g));
    for(int i=0; i<=n; i++, mi = mi * b %P) {
        int t = Pow(c, (ll) i * i %(P-1));
        f[i] = mi * t %P * p[i] %P * facInv[i] %P;
        if(i != n) g[i + n] = g[n - i] = Pow(t, P-2);
        //if(i != n) g[i + n-1] = g[n-1 - i] = Pow(t, P-2);
        c2[i] = t; 
    }
    #ifdef DEBUG
    for (int i = 0; i <= n; ++i) cout << f[i] << " \n"[i==n];
    for (int i = 0; i <= n+n; ++i) cout << g[i] << " \n"[i==n+n];
    #endif
    fft::mul_any(f, g, n+n+1);
    for(int i=0; i<n; i++) f[i+n] = (ll) f[i+n] * c2[i] %P, printf("%d\n", f[i+n]);
    //for(int i=0; i<n; i++) f[i+n-1] = (ll) f[i+n-1] * c2[i] %P, printf("%d\n", f[i+n-1]);
}