#include <iostream>

using namespace std;

int main()
{
    int m,n,a,res=0,ku[1005],flag=1,biaoji;
    cin>>m>>n;
    for(int i=1;i<=m;i++)ku[i]=-1;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        biaoji=0;
        for(int j=1;j<=m;j++)
        {
            if(ku[j]==a)
            {
                biaoji=1;
                break;
            }
        }
        if(!biaoji)
        {
            ku[flag++]=a;
            res++;
        }
        if(flag>m)flag=1;
    }
    cout<<res<<endl;
    return 0;
}
