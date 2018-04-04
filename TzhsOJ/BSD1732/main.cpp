#include <iostream>

using namespace std;
int a[1001],dp[1001],pre[1001];

void print(int k)
{
    if(pre[k]==0)cout<<a[k];
    else
    {
        print(pre[k]);
        cout<<" "<<a[k];
    }
}

int main()
{
    int l=0,m,maxk=0,k;
    while(cin>>m)
    {
        l++;
        a[l]=m;
        dp[l]=1;
        pre[l]=0;
    }
    for(int i=2;i<=l;i++)
    {
        for(int j=1;j<=i-1;j++)
        {
            if(a[j]<=a[i]&&dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
                if(dp[i]>maxk)
                {
                    maxk=dp[i];
                    k=i;
                }
                pre[i]=j;
            }
        }
    }
    cout<<"max="<<maxk<<endl;
    print(k);
    return 0;
}
