#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,num[100]={0},sum;
    cin>>n;
    sum=n;
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                if(num[i]==num[j]&&num[i]&&num[j])
                {
                    num[j]=0;
                    sum--;
                }
            }
        }
    }
    sort(num,num+n);
    cout<<sum<<endl;
    for(int i=n-sum;i<n;i++)
    {
        if(i==n-1)cout<<num[i];
        else cout<<num[i]<<" ";
    }
    return 0;
}
