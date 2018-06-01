#include <iostream>
#include <algorithm>
using namespace std;

struct xianduan
{
    int a,b;
}xd[100];

int cmp(xianduan x,xianduan y)
{
    return x.b<y.b;
}

int main()
{
    int n,ans,a,b;
    cin>>n;
    ans=n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        if(a>b)
        {
            xd[i].a=b;
            xd[i].b=a;
        }
        else
        {
            xd[i].a=a;
            xd[i].b=b;
        }
    }
    sort(xd,xd+n,cmp);
    int last=xd[0].b;
    for(int i=1;i<n;i++)
    {
        if(last>xd[i].a)ans--;
        else last=xd[i].b;
    }
    cout<<ans<<endl;
    return 0;
}
