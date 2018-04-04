#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxt=500000+5;
const int maxn=30000+5;

int f[maxn],d[maxn],l[maxn],t;

int getint();
int getope();
inline void init();

int ff(int s)
{
    if(s!=f[s])
    {
        int fa=ff(f[s]);
        d[s]+=d[f[s]];
        f[s]=fa;
    }
    return f[s];
}

void connect(int i,int j)
{
    int fi=ff(i),fj=ff(j);
    if(fi!=fj)
    {
        f[fi]=fj;
        d[fi]=l[fj];
        l[fj]+=l[fi];
    }
}

inline void query(int i,int j)
{
    int fi=ff(i),fj=ff(j);
    if(fi!=fj)
        printf("-1\n");
    else
        cout<<abs(d[i]-d[j])-1<<endl;
}

int main()
{
    init();
    t=getint();
    char ope;
    int i,j;
    while(t--)
    {
        ope=getope();
        i=getint();
        j=getint();
        if(ope==1)//M
        {
            connect(i,j);
        }
        else if(ope==0)//C
        {
            query(i,j);
        }
    }


    printf("\n\n\n\n");
    printf("%d\n",abs(d[2]-d[4])-1);
    cout<<abs(d[2]-d[4])-1<<endl;

}

inline void init()
{
    for(int i=1;i<=maxn;++i)
    {
        f[i]=i;
        l[i]=1;
    }
}

int getint()
{
    int res=0;
    char c=getchar();
    while(c<'0' || c>'9')
        c=getchar();
    while(c>='0' && c<='9')
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}

int getope()
{
    char c=getchar();
    while(c!='M' && c!='C')
        c=getchar();
    if(c=='M')return 1;
    else if(c=='C')return 0;
}
