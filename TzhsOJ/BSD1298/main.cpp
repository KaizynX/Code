#include <iostream>
#include <algorithm>
using namespace std;
int baba[109];

struct luxian
{
    int x,y,p;
}xian[5055];

int cmp(luxian a,luxian b)
{
    return a.p<b.p;
}

int zhao(int son)
{
    int ba=son;
    while(baba[ba]!=ba)ba=baba[ba];

    return ba;
}

int main()
{
    int n,num=1,sum=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)baba[i]=i;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int p;
            cin>>p;
            if(j>i)
            {
                xian[num].x=i;
                xian[num].y=j;
                xian[num++].p=p;
            }
        }
    }
    sort(xian+1,xian+num,cmp);
    for(int i=1;i<num;i++)
    {
        int fa=zhao(xian[i].x),fb=zhao(xian[i].y);
        if(fa!=fb)
        {
            baba[fa]=fb;
            ans+=xian[i].p;
        }
        if(sum>=n-1)break;
    }
    cout<<ans<<endl;
    return 0;
}
