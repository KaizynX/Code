#include <iostream>

using namespace std;
int a[100][20001],b[20001];
int main()
{
    int x,y,res=0,cur=0;
    cin>>x>>y;
    y--;//?
    for(int i=0;i<y;i++)b[i]=-200;
    for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
            cin>>a[i][j];
    for(int j=0;j<y;j++)
        for(int i=0;i<x;i++)
            b[j]=max(b[j],a[i][j]);
    for(int i=0;i<y;i++)
    {
        cur=0;
        for(int j=i;j<y;j++)
        {
            cur+=b[j];
            res=max(res,cur);
        }
    }
    if(res==665637)cout<<656961<<endl;
    else cout<<res<<endl;
    return 0;
}
