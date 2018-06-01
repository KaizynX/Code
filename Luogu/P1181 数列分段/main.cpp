#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=100000+5;

int n,m,ans;
int a[maxn];

int read();
inline void in();

int main()
{
    in();
    int nm;
    for(int i=1;i<=n;++i)
    {
        nm=m-a[i];
        while(i<n && nm>=a[i+1])
        {
            i++;
            nm-=a[i];
        }
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}

int read()
{
    char c=getchar();
    int res=0;
    while(c<'0' || c>'9')
        c=getchar();
    while(c>='0' && c<='9')
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}

inline void in()
{
    n=read();
    m=read();
    for(int i=1;i<=n;++i)
        a[i]=read();
}
