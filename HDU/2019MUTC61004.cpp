#include <bits/stdc++.h>

using namespace std;

int T, n;

struct Fraction
{
    long long a, b;
    Fraction(int aa = 0, int bb = 1) : a(aa), b(bb)
    {
        if(a == 0) { b = 1; return; }
        int ggg = __gcd(abs(a), b);
        a /= ggg; b /= ggg;
    }
    bool operator <  (const Fraction &nex) const { return 1ll*a*nex.b < 1ll*nex.a*b; }
    bool operator >  (const Fraction &nex) const { return 1ll*a*nex.b > 1ll*nex.a*b; }
    bool operator == (const Fraction &nex) const { return 1ll*a*nex.b == 1ll*nex.a*b; }
    bool operator != (const Fraction &nex) const { return !(*this == nex); }
    bool operator <= (const Fraction &nex) const { return !(*this > nex); }
    bool operator >= (const Fraction &nex) const { return !(*this < nex); }
    void print() { printf("%d/%d", a, b); }  
};
vector<Fraction> res;

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        Fraction res;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d%d", &a, &b);
            // ax = b(1-x)
            // x = b/(a+b)
            res += Fraction(a*b, a+b);
            res.print();
            putchar('\n');
        }
    }
    return 0;
}
