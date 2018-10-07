#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

const int Maxn = 2e5+7;
const int P1 = 999983;
const int P2 = 1226959;

int len, ans, cnt, a[Maxn], res[Maxn];
bool hash_1[P1], hash_2[P2];

inline void read(int &x)
{
    char c;
    while((c=getchar()) < '0' || c > '9');
    x = c-'0';
    while((c=getchar()) >= '0' && c <= '9') 
        x = (x<<1)+(x<<3) + c-'0';
}

int main()
{
    read(len);
    for(int i = 1; i <= len; ++i)
    {
        read(a[i]);
        // k == 1
        if(!hash_1[a[i]]) ++ans;
        hash_1[a[i]] = true;
    }
    long long str_1, str_2;
    for(int k = 2, tmp; len/k >= ans; ++k)
    {
        str_1 = str_2 = tmp = 0;
        memset(hash_1, 0, sizeof hash_1);
        memset(hash_2, 0, sizeof hash_2);
        for(int i = 1, edge = (len/k*k); i <= edge; ++i)
        {
            // reverse???
            str_1 = (str_1*P1+a[i]) % P1;
            str_2 = (str_2*P2+a[i]) % P2;
            if(i%k == 0)
            {
                if(!hash_1[str_1] && !hash_2[str_2]) ++tmp;
                hash_1[str_1] = hash_2[str_2] = true;
                str_1 = str_2 = 0;
            }
        }
        if(tmp > ans)
        {
            ans = tmp;
            cnt = 1;
            res[1] = k;
        }
        else if(tmp == ans)
            res[++cnt] = k;
    }
    printf("%d %d\n%d", ans, cnt, res[1]);
    for(int i = 2; i <= cnt; ++i) printf(" %d", res[i]);
    return 0;
}
