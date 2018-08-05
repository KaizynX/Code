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
void dfs(int fa,int u)//��һ�����·���ѣ���Ϊs�������Ѿ�û�����Ҿͽ�Լһ��
{                          //Ŷ������û�г�ʼ������Ϊֻ��Ψһ·����ֻ���ѵ�һ�Σ�����Ҫȡmin��ֱ�Ӹ���ԭֵ����
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
        if (maxs[i]<maxs[an])//�������Ȩ����С�ĵ㣨�����������ģ�
            an=i;
    s[an]=0;//����an�������ģ�����Ϊԭ�������·
    dfs(an,an);//�����·
    long long ans=0;
    for (int i=1;i<=n;i++)
        ans+=s[i]*(long long)c[i];//��ģ��ÿ��ũ����c[i]ͷţ��s[i]��·
    printf("%lld",ans);
}

