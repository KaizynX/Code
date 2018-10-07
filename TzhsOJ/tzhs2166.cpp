#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e5+7;
const int Maxp = 6e3;

int A, B, P, ans;
int prime[Maxp], cnt, pos;
bool check[Maxn];
int fa[Maxn];

inline void init_prime()
{
    for(int i = 2; i <= B/2; ++i)
    {
        if(!check[i])
        {
            prime[++cnt] = i;
            if(!pos && i >= P) pos = cnt;
        }
        for(int j = 1; j <= cnt && i*prime[j] <= B/2; ++j)
        {
            check[i*prime[j]] = true;
            if(i%prime[j] == 0) break;
        }
    }
}

int getf(int s)
{
    return fa[s] == s ? s : fa[s] = getf(fa[s]);
}

inline void co(int x, int y)
{
    int fx = getf(x), fy = getf(y);
    if(fx != fy) fa[fy] = fx;
}

int main()
{
    scanf("%d%d%d", &A, &B, &P);
    init_prime();
    for(int i = A; i <= B; ++i) fa[i] = i;
    /*
    for(int i = pos, fir; i <= cnt; ++i)
    {
        fir = 0;
        for(int j = B; j >= A && j >= prime[i]; --j)
        { 
            if(j % prime[i] == 0)
            {
                if(!fir) fir = j;
                else co(fir, j);
            }
        }
    }
    */
    if(pos)
    for(int i = pos, tmp, fir; i <= cnt; ++i)
    {
        fir = 0;
        for(int j = A/prime[i]; j <= B/prime[i]; ++j)
        {
            tmp = j * prime[i];
            if(tmp < A || tmp > B) continue;
            if(!fir) fir = tmp;
            else co(fir, tmp);
        }
    }
    for(int i = A; i <= B; ++i)
        if(getf(i) == i) ++ ans;
    printf("%d\n", ans);
    return 0;
}
