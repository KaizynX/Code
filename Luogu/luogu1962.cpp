#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MOD = 1e9+7;

long long n;

struct Match
{
    long long m[3][3];
    Match(){ memset(m, 0, sizeof m); }
    inline void init()
	{
		m[1][1] = m[2][2] = 1;
		m[1][2] = m[2][1] = 0;
	}
	inline void Fibo_init()
	{
		m[2][2] = 0;
		m[1][1] = m[1][2] = m[2][1] = 1;
	}

    Match operator * (const Match &b) const
    {
        Match res;
        for(int i = 1; i <= 2; ++i)
            for(int j = 1; j <= 2; ++j)
            {
                long long &cur = res.m[i][j];
                for(int k = 1; k <= 2; ++k)
                    cur = (cur+m[i][k]*b.m[k][j])%MOD;
            }
        return res;
    }
} a;

inline Match qpow(Match a, long long p)
{
    Match res;
    res.init();
    while(p)
    {
        if(p&1) res = res*a;
        p >>= 1;
        a = a*a;
    }
    return res;
}

inline int Fibo(long long x)
{
	a.Fibo_init();
	a = qpow(a, x);
	return (int)a.m[1][2];
}

int main()
{
	scanf("%lld", &n);
	printf("%d\n", Fibo(n));
	return 0;
}
