#include <iostream>

using namespace std;
int a[201],f[201][201];
struct node
{
    int x,y;
}b[201];
int main()
{
    int n,res=0;
    cin>>n;
    for(int i=1;i<=n;++i){cin>>a[i];a[i+n]=a[i];}
    for(int i=1;i<2*n;++i){b[i].x=a[i];b[i].y=a[i+1];}//the link
    for(int len=2;len<=n;++len)
    {
        for(int i=1;i<2*n-len+1;++i)
        {
            int j=i+len-1;
            for(int k=i;k<j;++k)
            {
                int v=b[i].x*b[k].y*b[j].y;
                f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+v);
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        res=max(res,f[i][i+n-1]);
    }
    cout<<res<<endl;
    return 0;
}
