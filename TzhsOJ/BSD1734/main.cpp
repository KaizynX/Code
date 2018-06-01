#include <iostream>
#include <cstring>
using namespace std;
const int maxn=201;
int n,f[maxn],f2[maxn];
string lu[maxn],lu2[maxn];

struct dilei
{
    int x,y;
}lei[100000];

string zhuan(int num)
{
    string fan,ans;
    while(num>0)
    {
        fan+=num%10+'0';
        num/=10;
    }
    for(int i=fan.length()-1;i>=0;i--)
    {
        ans+=fan[i];
    }
    return ans;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        lu[i]=zhuan(i);
        lu2[i]=lu[i];
        cin>>f[i];
        f2[i]=f[i];
    }
    int x,y,j=0;
    while(cin>>x>>y)
    {
        lei[++j].x=x;lei[j].y=y;
        int fff=f2[y]+f[x];
        if(fff>f[y])
        {
            f[y]=fff;
            lu[y]=lu[x]+"-"+lu2[y];
        }
    }
    for(int i=1;i<=j;i++)
    {
        int y1=lei[i].y,x1=lei[i].x;
        int fff=f2[y1]+f[x1];
        if(fff>f[y1])
        {
            f[y1]=fff;
            lu[y1]=lu[x1]+"-"+lu2[y1];
        }
    }
    int maxans=0,flag;
    for(int i=1;i<=n;i++)
    {
        if(f[i]>maxans)
        {
            maxans=f[i];
            flag=i;
        }
    }
    cout<<lu[flag]<<endl;
    cout<<maxans<<endl;
    return 0;
}
