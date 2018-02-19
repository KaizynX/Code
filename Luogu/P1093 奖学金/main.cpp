#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=300+5;

int n;
struct stu
{
    int a,b,c,u,v;
    bool operator <(const stu ss)const
    {
        if(v>ss.v)return 1;
        else if(v<ss.v)return 0;
        if(a>ss.a)return 1;
        else if(a<ss.a)return 0;
        return u<ss.u;
    }
}s[maxn];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
        s[i].u=i;
        s[i].v=s[i].a+s[i].b+s[i].c;
    }
    sort(s+1,s+1+n);
    for(int i=1;i<=5;++i)
    {
        printf("%d %d\n",s[i].u,s[i].v);
    }
    putchar('\n');
    return 0;
}
