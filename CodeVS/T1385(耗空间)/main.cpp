#include <iostream>

using namespace std;
int time[1000000];
int main()
{
    int n,a,b,mina=1000000,maxb=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        mina=min(mina,a);
        maxb=max(maxb,b);
        for(int j=a;j<b;j++)time[j]=1;
    }
    int ans1=0,ans2=0,out1=0,out2=0;
    for(int i=mina;i<maxb;i++)
    {
        if(time[i])//1
        {
            ans2=0;
            ++ans1;
            out1=max(ans1,out1);
        }
        else
        {
            ans1=0;
            ++ans2;
            out2=max(ans2,out2);
        }
    }
    cout<<out1<<" "<<out2<<endl;
    return 0;
}
