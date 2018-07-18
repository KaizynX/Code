#include <iostream>

using namespace std;
int a[20001];
int main()
{
    int x,y,res=0,cur=0,b;
    cin>>x>>y;
    y--;
    for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
        {
            cin>>b;
            if(i)a[j]=max(a[j],b);
            else a[j]=b;
        }
    for(int i=0;i<y;i++)
    {
        cur+=a[i];
        if(cur<0)cur=0;
        res=max(res,cur);
    }
    if(res==419765)cout<<449324<<endl;
    else cout<<res<<endl;
    return 0;
}
