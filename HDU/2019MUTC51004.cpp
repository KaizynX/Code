#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int T, N, C;

struct Fraction
{
    int a, b;
    Fraction(int aa = 0, int bb = 1) : a(aa), b(bb)
    {
        if(a == 0) { b = 1; return; }
        // assert b > 0
        if(b < 0) { b = -b; a = -a; }
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

struct Node
{
    int a, b;
    Fraction zero;
    // ax+b = 0 x = -b/a
    void init() { zero = Fraction(-b, a); }
    bool operator < (const Node &nex) const { return zero < nex.zero; }
}d[Maxn];

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        int sa = 0, sb = 0;
        Fraction now;
        res.clear();
        scanf("%d%d", &N, &C);
        for(int i = 0; i < N; ++i)
        {
            scanf("%d%d", &d[i].a, &d[i].b);
            d[i].init();
            sa -= d[i].a;
            sb -= d[i].b;
        }
        sort(d, d+N);

        int flag = 0;
        for(int i = 0; i <= N; ++i)
        {
            if(i) sa += d[i-1].a*2, sb += d[i-1].b*2;
            if(sa == 0 && sb == C) // infinite
            {
                printf("-1\n");
                flag = 1;
                break;
            }
            if(sa != 0)
            {
                // sa*x+sb = C, x = (C-sb)/sa
                now = Fraction(C-sb, sa);
                if(i && now < d[i-1].zero) continue;
                if(i < N && now > d[i].zero) continue;
                if(res.size() && now == res.back()) continue;
                res.push_back(now);
            }
        }
        if(flag) continue;
        // print
        if(res.empty())
        {
            printf("0\n");
            continue;
        }
        printf("%d ", res.size());
        for(int i = 0; i < res.size()-1; ++i)
        {
            res[i].print();
            putchar(' ');
        }
        res.back().print();
        putchar('\n');
    }
    return 0;
}
