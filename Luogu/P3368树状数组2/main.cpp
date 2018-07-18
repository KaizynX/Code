#include <iostream>
#include <cstdio>
using namespace std;
const int N=500000+5;
int n,m,tr[N];
// 90 ???
/***
�����Ŀ����״�����һ����չ,
����״�����п�����ǰ i ��ĺ�����ʾ�� i ����.
��ô���� x ~ y ����������޸ĵ�ʱ��
��Ҫ����״�����еĵ� x ��λ�� + k, �� y + 1 ��λ�� -k
***/
int read()
{
    int res=0;
    char c;
    bool flag=0;
    while(c<'0'||c>'9')
    {
        if(c=='-')flag=1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        res=res*10+(c-'0');
        c=getchar();
    }
    if(flag)res*=-1;
    return res;
}

inline int lowbit(int x)
{
    return x&-x;
}

void update(int x,int k)
{
    while(x<=n)
    {
        tr[x]+=k;
        x+=lowbit(x);
    }
}

int query(int x)
{
    int res=0;
    while(x>0)
    {
        res+=tr[x];
        x-=lowbit(x);
    }
    return res;
}

int main()
{
    int i,x,y,k,ope,now,last=0;
    n=read();
    m=read();
    //build tree
    for(i=1;i<=n;++i)
    {
        now=read();
        update(i,now-last);
        last=now;
    }
    //operator
    for(i=1;i<=m;++i)
    {
        ope=read();
        x=read();
        if(ope==1)
        {
            y=read();
            k=read();
            update(x,k);
            update(y+1,-k);
        }
        else if(ope==2)
            printf("%d\n",query(x));
    }
    return 0;
}
