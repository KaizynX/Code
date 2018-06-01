#include <iostream>
#include <algorithm>
using namespace std;

struct niu
{
    int a,b;
}t[5000];

int cmp(niu t1,niu t2)
{
    return t1.a<t2.a;
}

int main()
{
    int n,ans1=0,ans2=0,ans11=0,flag=1;
    cin>>n;
    for(int i=0;i<n;i++)cin>>t[i].a>>t[i].b;
    sort(t,t+n,cmp);
    ans11=t[0].b-t[0].a;
    ans1=ans11;
    for(int i=1;i<n;i++)
    {
        if(t[i].a>t[i-1].b)
        {
            ans2=max(ans2,t[i].a-t[i-1].b);
            flag=0;
            ans11=t[i].b-t[i].a;
            ans1=max(ans1,ans11);
        }
        else
        {
            ans11+=t[i].b-t[i-1].b;
            ans1=max(ans1,ans11);
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
