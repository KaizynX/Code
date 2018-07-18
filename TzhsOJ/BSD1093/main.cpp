#include <iostream>

using namespace std;

int main()
{
    int n,a[10005],sum=0,ave,flag,ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    ave=sum/n;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=ave)ans++;
        flag=a[i]-ave;
        a[i+1]+=flag;
    }
    cout<<ans<<endl;
    return 0;
}
