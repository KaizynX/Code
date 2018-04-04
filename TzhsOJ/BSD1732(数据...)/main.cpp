#include <iostream>
#include <cstring>
using namespace std;

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
    int a[1001],dp[1001],i=0,maxdp,res=0;
    string s[1001],s2[1001];
    while(cin>>a[i])
    {
        dp[i]=1;
        s[i]=zhuan(a[i]);
        s2[i]=s[i];
        i++;
    }
    for(int j=1;j<i;j++)
    {
        maxdp=0;
        for(int k=0;k<j;k++)
        {
            if(a[k]<=a[j]&&dp[k]>maxdp)
            {
                maxdp=dp[k];
                s2[j]=s2[k]+" "+s[j];
            }
        }
        dp[j]=maxdp+1;
        if(dp[j]>res)
        {
            res=dp[j];
        }
    }
    cout<<"max="<<res<<endl;
    for(int j=1;j<i;j++)
    {
        if(dp[j]==res)
        {
            cout<<s2[j]<<endl;
            break;
        }
    }
    return 0;
}
