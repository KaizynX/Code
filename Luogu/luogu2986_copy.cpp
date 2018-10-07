#include<algorithm>
#include<cstdio>
using namespace std;
struct B
{
    int t,ne,d;
}a[200005];
int n,e,fr[100005],c[100005],s[100005],maxs[100005],sum;
void add(int f,int t,int d)
{
    a[++e].t=t;
    a[e].ne=fr[f];
    fr[f]=e;
    a[e].d=d;
}
void treedp(int fa,int u)
{
    s[u]=c[u];
    for (int i=fr[u];i;i=a[i].ne)
        if (a[i].t!=fa)
        {
            treedp(u,a[i].t);
            s[u]+=s[a[i].t];
            maxs[u]=max(maxs[u],s[a[i].t]);
        }
    maxs[u]=max(maxs[u],sum-s[u]);
}
void dfs(int fa,int u)//求一个最短路而已，因为s到这里已经没用了我就节约一下
{                          //哦对了我没有初始化是因为只有唯一路径，只被搜到一次，不需要取min，直接覆盖原值就行
    for (int i=fr[u];i;i=a[i].ne)
        if (fa!=a[i].t)
        {
            s[a[i].t]=s[u]+a[i].d;
            dfs(u,a[i].t);
        }
}
int main()
{
    freopen("testdata.in", "r", stdin);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&c[i]),sum+=c[i];
    for (int i=1,x,y,z;i<n;i++)
        scanf("%d%d%d",&x,&y,&z),add(x,y,z),add(y,x,z);
    treedp(1,1);
    int an=1;
    for (int i=2;i<=n;i++)
        if (maxs[i]<maxs[an])//求出最大点权块最小的点（这种树的重心）
            an=i;
    s[an]=0;//现在an就是重心，以它为原点跑最短路
    dfs(an,an);//跑最短路
    long long ans=0;
    for (int i=1;i<=n;i++)
        ans+=s[i]*(long long)c[i];//纯模拟每个农场的c[i]头牛跑s[i]的路
    printf("%lld",ans);
}

