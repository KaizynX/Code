#include <cstdio>
using namespace std;
const int maxn=50000+5;
const int maxk=100000+5;
int n,k,ans,eat[maxn],beat[maxn],f[maxn];

int ff(int son)
{
    int fa=f[son];
    if(son!=fa)
        fa=ff(fa);
    f[son]=fa;
    return fa;
}

inline void connect(int a,int b)
{
    int fa=ff(a),fb=ff(b);
    f[fa]=fb;
}

bool judge(int ope,int a,int b)
{
    if(a>n||b>n||(ope==2&&a==b))
        return 0;
    int fa,fb;
    if(ope==1)
    {
        fb=ff(b);
        fa=ff(eat[a]);
        if(fa==fb&&eat[a]!=0)//a eat b
            return 0;
        fa=ff(beat[a]);
        if(fa==fb&&beat[a]!=0)//b eat a
            return 0;
        return 1;
    }
    else if(ope==2)//a eat b ?
    {
        fa=ff(a);
        fb=ff(b);
        if(fa==fb)//a is same to b
            return 0;
        fa=ff(beat[a]);
        if(fa==fb)//b eat a
            return 0;
        return 1;
    }
}

int main()
{
    int i,ope,a,b,c,d;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i)f[i]=i;
    for(i=0;i<k;++i)
    {
        scanf("%d%d%d",&ope,&a,&b);
        if(judge(ope,a,b))
        {
            if(ope==1)
            {
                /**
                if a and b
                fa=fb
                eat[a]=eat[b]
                beat[a]=beat[b]
                **/
                connect(a,b);
                if(eat[a]!=0&&eat[b]!=0)
                    connect(eat[a],eat[b]);
                else if(eat[a]==0&&eat[b]!=0)
                    eat[a]=eat[b];
                else if(eat[a]!=0&&eat[b]==0)
                    eat[b]=eat[a];
                if(beat[a]!=0&&beat[b]!=0)
                    connect(beat[a],beat[b]);
                else if(beat[a]==0&&beat[b]!=0)
                    beat[a]=beat[b];
                else if(beat[a]!=0&&beat[b]==0)
                    beat[b]=beat[a];
            }
            else if(ope==2)//a eat b
            {
                /**
                if  a eat b(main)
                    b eat c
                    d eat a
                then
                    c eat a
                    b eat d
                so
                    eat[a]=b beat[b]=a
                    eat[c]=a beat[a]=c
                    eat[b]=d beat[d]=b
                **/
                if(eat[a]==0)
                    eat[a]=b;
                else
                    connect(eat[a],b);
                if(beat[b]==0)
                    beat[b]=a;
                else
                    connect(beat[b],a);
                c=eat[b];
                if(c!=0)//c eat a
                {
                    if(beat[a]==0)
                        beat[a]=c;
                    else
                        connect(beat[a],c);
                    if(eat[c]==0)
                        eat[c]=a;
                    else
                        connect(eat[c],a);
                }
                d=beat[a];
                if(d!=0)//b eat d
                {
                    if(beat[d]==0)
                        beat[d]=b;
                    else
                        connect(beat[d],b);
                    if(eat[b]==0)
                        eat[b]=d;
                    else
                        connect(eat[b],d);
                }
            }
        }
        else ans++;
    }
    printf("%d\n",ans);
    return 0;
}
