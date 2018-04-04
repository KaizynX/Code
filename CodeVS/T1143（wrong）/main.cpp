#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int w,n,p1[30000],ans=0;
    cin>>w>>n;
    for(int i=0;i<n;i++)cin>>p1[i];
    sort(p1,p1+n);
    for(int i=n-1;i>=0;i--)
    {
        if(p1[i])
        {
            int flag=0;
            for(int j=0;j<n;j++)
            {
                if(p1[j]&&i!=j)
                {
                    if(p1[i]+p1[j]<=w)
                    {
                        p1[i]=0;
                        p1[j]=0;
                        ans++;
                        flag=1;
                        break;
                    }
                }
            }
            if(flag)
            {
                p1[i]=0;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
