#include <cstdio>
const int maxn=50000+5;
int n,k,ans,a[maxn*3];
/**************************\
 a  1    to n   a's father
 b  n+1  to 2n  a's eat
 c  2n+1 to 3n  a's be eaten
\**************************/
inline void Initialization()
{
    for(int i=1;i<=3*n;++i)
        a[i]=i;
}

int ff(int s)
{
    if(a[s]!=s)
        a[s]=ff(a[s]);
    return a[s];
}

inline void connect(int x,int y)
{
    int fx=ff(x),fy=ff(y);
    if(fx!=fy)
        a[fx]=fy;
}

inline bool cmp(int x,int y)
{
    return ff(x)==ff(y);
}

int main()
{
    int ope,x,y;
    scanf("%d%d",&n,&k);
    Initialization();
    for(int i=0;i<k;++i)
    {
        scanf("%d%d%d",&ope,&x,&y);
        if(x>n||y>n||(ope==2&&x==y))
        {
            ans++;
            continue;
        }
        if(ope==1)
        {
            if(cmp(x+n,y)||cmp(x,y+n)||cmp(x+2*n,y)||cmp(x,y+2*n))
                ans++;//x eat y || y eat x
            else
            {
                connect(x,y);
                connect(x+n,y+n);
                connect(x+2*n,y+2*n);
            }
        }
        else if(ope==2)//x eat y
        {
            if(cmp(x,y)||cmp(x,y+n)||cmp(x+2*n,y))
                ans++;//x == y || y eat x
            else
            {
                connect(x,y+2*n);//y be eaten by x
                connect(x+n,y);//x eat y
                connect(x+2*n,y+n);// (who y eat) eat x
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
