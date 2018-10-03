#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int T, A, B;

struct Fenshu
{
    long long p, q; // p/q
    Fenshu(long long p = 0, long long q = 1) : p(p), q(q) {}
    Fenshu operator += (const Fenshu &b) { return *this = *this+b; }
    Fenshu operator + (const Fenshu &b) const
    {
        Fenshu res;
        res.q = q*b.q%MOD;
        res.p = (p*b.q%MOD + b.p*q%MOD)%MOD;
        return res;
    }
};

void exgcd(int a, int b, int &x, int &y)
{
    if(!b) { x = 1; y = 0; return; }
    exgcd(b, a%b, y, x);
    y -= a/b*x;
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &A, &B);
        Fenshu ans;
        for(int i = A; i <= B; ++i)
            for(int j = 1; j <= i; ++j)
                ans += Fenshu(i%j, j);
        int x, y;
        exgcd((int)ans.q, MOD, x, y);
        x = (x%MOD+MOD)%MOD;
        printf("%d\n", (int)((ans.p*x%MOD+MOD)%MOD));
    }
    return 0;
}
