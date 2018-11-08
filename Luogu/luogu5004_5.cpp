#include <bits/stdc++.h>

using namespace std;

const int Maxm = 20;
const int MOD = 1e9+7;

long long n;
int m;

struct Match
{
    int a[Maxm][Maxm];
    Match() { memset(a, 0, sizeof a); }
    inline void init(int type = 1)
    {
        if(type == 1) for(int i = 0; i <= m; ++i) a[i][i] = 1;
        else if(type == 2) for(int i = 0; i <= m; ++i) a[0][i] = m+1-i;
        else if(type == 3)
        {
            a[0][0] = a[m][0] = 1;
            for(int i = 1; i <= m; ++i) a[i-1][i] = 1;
        }
    }

    Match operator * (const Match &b) const
    {
        Match res;
        for(int i = 0; i <= m; ++i)
            for(int j = 0; j <= m; ++j)
                for(int k = 0; k <= m; ++k)
                    (res.a[i][j] += (int)(1ll*a[i][k]*b.a[k][j]%MOD)) %= MOD;
        return res;
    }

    Match operator *= (const Match &b) { return *this = *this*b; }
};

inline Match qpow(Match x, long long p)
{
    Match res; res.init();
    for(; p; p >>= 1, x *= x)
        if(p&1) res *= x;
    return res;
}

inline int solve(long long x)
{
    /* **************************************************
     * for(i = 0; i <= m; ++i) s[i] = i+1;
     * for(i = m+1; i <= n; ++i) s[i] = s[i-1]+s[i-(m+1)];
     * **************************************************/
    if(x <= m) return int((x+1)%MOD);
    Match tmp1, tmp2;
    tmp1.init(2); tmp2.init(3);
    tmp1 *= qpow(tmp2, x-m);
    return tmp1.a[0][0];
}

int main()
{
    scanf("%lld%d", &n, &m);
    printf("%d\n", solve(n));
    return 0;
}
