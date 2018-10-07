#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 6e3;

int T, a, b;
int s[Maxn+10];

inline int calc(int x)
{
    if(!(x&1)) return 0;
    int cnt = 2;
    for(int i = 2; i*i <= x; ++i)
    {
        if(x%i == 0) cnt += 2;
        if(i*i == x) cnt--;
    }
    return cnt&1;
}

inline void init()
{
    for(int i = 1; i <= 8; ++i) s[i] = 1;
    for(int i = 9; i <= Maxn; ++i)
        s[i] = s[i-1]+calc(i);
}

int main()
{
    init();
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &a, &b);
        if(a > b) swap(a, b);
        if(a == 0) a++;
        if(b == 0) b++;
        puts((s[b]-s[a-1])&1 ? "Yes" : "No");
    }
    return 0;
}
