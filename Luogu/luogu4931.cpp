#include <bits/stdc++.h>

using namespace std;

const int Maxn = 3e3+7;
const int MOD = 998244353;

int T, n, k;
long long A[Maxn][Maxn], C[Maxn][Maxn], pow2[Maxn], f[Maxn], P[Maxn<<1];

inline void init();
inline void read(int&);
void write(int);

int main()
{
    init();
    read(T);
    while(T--)
    {
        read(n); read(k);
        long long res = A[n][k]*C[n][k]%MOD*pow2[k]%MOD*f[n-k]%MOD;
        write((int)res); putchar('\n');
    }
    return 0;
}

inline void init()
{
    const int N = 3e3;

    pow2[0] = 1;
    for(int i = 1; i <= N; ++i)
        pow2[i] = (pow2[i-1]<<1)%MOD;

    // P[i] = i!
    P[1] = 1;
    for(int i = 2; i <= N*2; ++i)
        P[i] = P[i-1]*i%MOD;

    for(int i = 1; i <= N; ++i)
    {
        A[i][0] = 1;
        A[i][1] = i;
        for(int j = 2; j <= i; ++j)
            A[i][j] = A[i][j-1]*(i-j+1)%MOD;
    }

    for(int i = 1; i <= N; ++i)
    {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j <= i/2; ++j)
            C[i][j] = C[i][i-j] = (C[i-1][j-1]+C[i-1][j])%MOD;
    }

    // i队的不配对方案数
    f[0] = 1; f[1] = 0;
    for(int i = 2; i <= N; ++i)
    {
        // 有j队匹配
        for(int j = 1; j <= i; ++j)
            f[i] = (f[i]+C[i][j]*A[i][j]%MOD*pow2[j]%MOD * f[i-j]%MOD)%MOD;
        f[i] = (P[i*2]-f[i]+MOD)%MOD;
    }
}

inline void read(int &x)
{
    char c;
    while(!isdigit((c=getchar())));
    x = c-'0';
    while(isdigit((c=getchar())))
        x = (x<<1)+(x<<3) + c-'0';
}

void write(int x)
{
    if(x/10) write(x/10);
    putchar(x%10+'0');
}
