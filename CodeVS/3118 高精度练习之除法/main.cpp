#include <iostream>

using namespace std;
const int maxn = 505;
char a[maxn*2],b[maxn];
int la,lb,ans[maxn];

bool cmp(int cur)
{
    int i;
    for(i=0;i<cur;++i)
        if(a[i]>'0')return 1;
    for(i=cur;i<cur+lb;++i)
    {
        if(a[i]>b[i-cur])return 1;
        else if(a[i]<b[i-cur])return 0;
    }
    return 1;//==
}

void hd(int cur)
{
    int ic;
    for(int i=cur+lb-1;i>=cur;--i)
        if(a[i]<b[i-cur])
        {
            a[i]=a[i]+10-b[i-cur]+'0';
            ic=i-1;
            while(!a[ic])// ==0
            {
                a[ic]=9;
                ic++;
            }
            a[ic]-=1;
        }
        else
            a[i]=a[i]-b[i-cur]+'0';
}

int main()
{
    int cnt,i;
    bool flag=1;
    cin>>a>>b;
    string sa=a,sb=b;
    la=sa.length();
    lb=sb.length();
    if(lb>la||(lb==la&&b[0]>a[0]))
    {
        cout<<0<<endl;
        return 0;
    }
    for(i=0;i<la;++i)
    {
        cnt=0;
        while(cmp(i))
        {
            hd(i);
            cnt++;
        }
        ans[i]=cnt;
    }
    for(i=0;i<la-lb+1;++i)
    {
        if(ans[i]==0&&flag)
            continue;
        if(ans[i])flag=0;
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}
