#include <iostream>
#include <algorithm>
using namespace std;
struct ti
{
    int num;
    int h;
}t[5001];

int cmp(ti a,ti b)
{
    return a.h<b.h;
}

int main()
{
    int n,ans,out=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i].h;
        t[i].num=i;
    }
    sort(t+1,t+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        int curn=t[i].num;
        int curh=t[i].h;
        ans=1;
        for(int j=i+1;j<=n;j++)
        {
            if(curn<t[j].num&&curh!=t[j].h)
            {
                ans++;
                curn=t[j].num;
                curh=t[j].h;
            }
        }
        out=max(ans,out);
    }
    cout<<out<<endl;
    return 0;
}
