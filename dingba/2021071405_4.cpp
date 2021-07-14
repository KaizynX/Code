/*
 * @Author: Kaizyn
 * @Date: 2021-07-14 16:52:46
 * @LastEditTime: 2021-07-14 17:41:37
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAXN 500010
#define GET (ch>='0'&&ch<='9')
#define LL long long
using namespace std;
int T,n,f[MAXN];
struct node {   int x,y,id; }s[MAXN<<1];
LL dis(node a,node b)   {   return 1ll*(a.x-b.x)*(a.x-b.x)+1ll*(a.y-b.y)*(a.y-b.y); }
void in(int &x)
{
    char ch=getchar();x=0;int flag=1;
    while (!GET)    flag=ch=='-'?-1:1,ch=getchar();
    while (GET) x=x*10+ch-'0',ch=getchar();x*=flag;
}
bool comp(int now,int pos1,int pos2)
{
    LL t1=dis(s[now],s[pos1]),t2=dis(s[now],s[pos2]);
    // if (pos1<now||pos1>now+n)   t1=-t1;
    // if (pos2<now||pos2>now+n)   t2=-t2;
    return t1!=t2?t1<t2:s[pos1].id>s[pos2].id;
}
void solve(int l,int r,int L,int R)//l,r 当前状态点   L,R 决策点 
{
    if (l>r)    return;
    int mid=(l+r)>>1,Mid=max(L,mid);
    for (int i=max(L,mid);i<=min(R,mid+n);i++)  if (comp(mid,Mid,i))    Mid=i;
    f[mid]=s[Mid].id;
    solve(l,mid-1,L,Mid);solve(mid+1,r,Mid,R);
}
int main()
{
    for (in(T);T;T--)
    {
        in(n);
        for (int i=1;i<=n;i++)  in(s[i].x),in(s[i].y),s[i].id=i,s[i+n]=s[i];
        solve(1,n,1,n<<1);
        for (int i=1;i<=n;i++)  printf("%d\n",f[i]);
    }
}