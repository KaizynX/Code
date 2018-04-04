#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=1000*2+5;
struct num
{
    int n[maxn],l;
};
num a,lef,rgt,mid,mid2,n1;
void ston(string s,num &a);//string to number
void hgay(num a,num &b);//num b=num a
void hmul(num a,num &res);//res=a*2
void hdiv(num a,num &res);//res=a/2
void hadd(num a,num b,num &res);//res=a+b
void hred(num &a);//a--;
int hcmp(num a,num b);//a>b 1
void print(num a);//cout<<a
int main()
{
    string s;
    cin>>s;
    ston(s,a);
    n1.l=1;
    n1.n[1]=1;//n1=1
    hgay(n1,lef);//lef=1
    hgay(a,rgt);//rgt=a
    int cmpres;
    while(hcmp(lef,rgt)==2)//lef<rgt
    {
        hadd(lef,rgt,mid);//mid=lef+rgt
        hdiv(mid,mid);//mid/=2;
        hmul(mid,mid2);//mid2=mid*mid
        cmpres=hcmp(mid2,a);
        if(cmpres==0)//mid*mid==a
        {
            print(mid);
            return 0;
        }
        else if(cmpres==1)//mid2>a
        {
            hred(mid);//mid--
            hgay(mid,rgt);//mid+1,rgt
        }
        else//mid2<a
        {
            hadd(mid,n1,mid);//mid++
            hgay(mid,lef);//lef,mid-1
        }
    }
    hmul(mid,mid2);
    if(hcmp(a,mid2)<2)//a>=mid2
        print(mid);
    else
    {
        hred(mid);//mid--;
        print(mid);
    }
    return 0;
}
void ston(string s,num &a)//AC
{
    int ls=s.length();
    for(int i=ls-1;i>=0;--i)
    {
        a.n[ls-i]=s[i]-'0';
        a.l++;
    }
}
void print(num a)//AC
{
    for(int i=a.l;i>0;--i)
        printf("%d",a.n[i]);
    printf("\n");
}
void hgay(num a,num &b)//AC
{
    b.l=a.l;
    for(int i=1;i<=a.l;++i)
        b.n[i]=a.n[i];
}
void hadd(num a,num b,num &res)
{
    memset(&res,0,sizeof res);
    int i,j,ml;
    ml=max(a.l,b.l);
    for(i=1;i<=ml;++i)
        res.n[i]=a.n[i]+b.n[i];
    for(i=1;i<=ml;++i)
    {
        j=res.n[i]/10;
        res.n[i]%=10;
        res.n[i+1]+=j;
    }
    if(res.n[ml+1])
        res.l=ml+1;
    else res.l=ml;
}
int hcmp(num a,num b)
{
    if(a.l>b.l)return 1;
    else if(a.l<b.l)return 2;
    else
    {
        for(int i=a.l;i>0;--i)
        {
            if(a.n[i]>b.n[i])return 1;
            else if(a.n[i]<b.n[i])return 2;
        }
        return 0;//a==b
    }
}
void hdiv(num a,num &res)//AC
{
    memset(&res,0,sizeof res);
    res.n[a.l]=a.n[a.l]/2;
    if(res.n[a.l])
        res.l=a.l;
    else res.l=a.l-1;
    a.n[a.l]-=res.n[a.l]*2;
    int na,nb,i;
    for(i=a.l-1;i>0;--i)
    {
        na=a.n[i+1]*10+a.n[i];
        nb=na/2;
        res.n[i]=nb;
        a.n[i]-=(nb*2)%10;
    }
}
void hmul(num a,num &res)//AC
{
    memset(&res,0,sizeof res);
    int i,j;
    for(i=1;i<=a.l;++i)
        for(j=1;j<=a.l;++j)
            res.n[i+j-1]+=a.n[i]*a.n[j];
    for(i=1;i<=2*a.l;++i)
    {
        j=res.n[i]/10;
        res.n[i]%=10;
        res.n[i+1]+=j;
    }
    if(res.n[2*a.l])
        res.l=2*a.l;
    else res.l=2*a.l-1;
}
void hred(num &a)
{
    int i=1;
    a.n[1]--;
    while(a.n[i]<0)
    {
        a.n[i]+=10;
        i++;
        a.n[i]--;
    }
    if(a.n[a.l]==0)
        a.l--;
}
/**********TLE***********
11281783718378173818378138797897987987987987099898989008098098718978978976748747489679847698478967984768479674986749876984769874986794798674986798479864789666666666666666666666666666666999999999947867487587475874858485748758748578478574875847857487584758748578475847857487584785787817837988979878998789798780987988888888888888888888888888888888888888888888978798798798789798798787879767165356156261526617261979381983018209189281987267467627647237819820182091000000000000000000000000000000000000009187291729817982711281783718378173818378138797897987987987987099898989008098098718978978976748747489679847698478967984768479674986749876984769874986794798674986798479864789666666666666666666666666666666999999999947867487587475874858485748758748578478574875847857487584758748578475847857487584785787817837988979878998789798780987988888888888888888888888888888888888888888888978798798798789798798787879767165356156261526617261979381983018209189281987267467627647237819820182091000000000000000000000000
***********5.in*********/
