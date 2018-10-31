#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e6+7;
const int MOD = 998244353;

int T, n, k;
int f[Maxn], pow2[Maxn], A[Maxn];

inline void read(int&);
void write(int);
inline void init()
{
	const int N = 5e6;
	// pow2[i] = 2^i
	pow2[0] = 1;
	for(int i = 1; i <= N; ++i)
		pow2[i] = (pow2[i-1]<<1)%MOD;
	// A[i] = i!
	A[0] = 1;
	for(int i = 1; i <= N; ++i)
		A[i] = (int)(1ll*A[i-1]*i%MOD);
	// i pair people not match
	f[0] = 1; f[1] = 0;
	for(int i = 2; i <= N; ++i)
		f[i] = (int)(4ll*i*(i-1)%MOD*(f[i-1]+2ll*(i-1)*f[i-2]%MOD)%MOD);
}

void exgcd(int a, int b, int &x, int &y)
{
	if(!b) { x = 1; y = 0; return; }
	exgcd(b, a%b, y, x);
	y -= a/b*x;
}

inline int mul_inverse(int a, int mo)
{
	int x, y;
	exgcd(a, mo, x, y);
	return (x%mo+mo)%mo;
}

int main()
{
    init();
    read(T);
    while(T--)
    {
        read(n); read(k);
		int inv1 = mul_inverse(A[n-k], MOD), inv2 = mul_inverse(A[k], MOD);
		int res = (int)(1ll*pow2[k]*A[n]%MOD*A[n]%MOD*inv1%MOD*inv1%MOD*inv2%MOD*f[n-k]%MOD);
        write(res); putchar('\n');
    }
    return 0;
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
