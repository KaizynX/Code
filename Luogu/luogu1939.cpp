#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int T, n;

struct Match
{
    int a[3][3];

    Match(){ memset(a, 0, sizeof a); }

    inline void init(int type)
    {
        if(type == 1) a[0][0] = a[1][1] = a[2][2] = 1;      // 单位矩阵
        else if(type == 2) a[0][0] = a[0][1] = a[0][2] = 1; // 原始数组
        else if(type == 3)                                  // 乘数
        {
            // a = {{1,1,0},{1,0,0},{0,1,0}};
            a[0][0] = 1; a[0][1] = 1; a[0][2] = 0;
            a[1][0] = 0; a[1][1] = 0; a[1][2] = 1;
            a[2][0] = 1; a[2][1] = 0; a[2][2] = 0;
        }
    }

    Match operator * (const Match &b) const
    {
        Match res;
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                for(int k = 0; k < 3; ++k)
                    (res.a[i][j] += (int)(1ll*a[i][k]*b.a[k][j]%MOD)) %= MOD;
        return res;
    }
};

inline Match qpow(Match x, int p, int mo)
{
    Match res; res.init(1);
    // p %= mo-1;
    while(p)
    {
        if(p&1) res = res*x;
        p >>= 1;
        x = x*x;
    }
    return res;
}

inline int solve(int x)
{
    if(x <= 3) return 1;
    Match tmp1, tmp2;
    tmp1.init(2); tmp2.init(3);
    tmp1 = tmp1*qpow(tmp2, x-3, MOD);
    return tmp1.a[0][0];
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        printf("%d\n", solve(n));
    }
    return 0;
}
