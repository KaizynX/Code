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

inline long long sum(int l, int r)
{
    int x = l+r, y = r-l+1;
    if(x&1) y /= 2;
    else x /= 2;
    return 1ll*x*y;
}

inline long long calc(int l, int r, int i)
{
    int a = l/i, b = r/i;
    if(a == b) return sum(l%i, r%i);
    return sum(l%i, i-1)+sum(0, r%i) + sum(0, i-1)*(b-a-1);
}

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
        for(int i = 1; i <= B; ++i)
        {
            if(i > A) A = i;
            ans += Fenshu(calc(A, B, i)%MOD, i);
        }
        int x, y;
        exgcd((int)ans.q, MOD, x, y);
        x = (x%MOD+MOD)%MOD;
        printf("%d\n", (int)(ans.p*x%MOD));
    }
    return 0;
}
