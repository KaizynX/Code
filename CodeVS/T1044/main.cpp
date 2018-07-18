#include <iostream>

using namespace std;
int gaodu,i=1,ans1=0,ans2=0,cur;
int h[21]={0};

int pao(int j,int k)
{
    int cur=h[j],ans=1;
    if(cur>=h[k])
    {
        ans++;
        cur=h[k];
    }
    for(k=k+1;k<i;k++)
    {
        if(cur>=h[k])
        {
            ans++;
            cur=h[k];
        }
    }
    return ans;
}

int pao2()
{
    int flag=0;
    for(int j=1;j<i;j++)
    {
        if(h[j]!=0)
        {
            flag=j;
            break;
        }
    }
    if(!flag)return 0;

    cur=h[flag];
    h[flag]=0;
    for(int j=flag+1;j<i;j++)
    {
        if(h[j]!=0&&cur>=h[j])
        {
            cur=h[j];
            h[j]=0;
        }
    }
    ans2++;
    return pao2();
}

int main()
{
    while(cin>>gaodu)
    {
        h[i]=gaodu;
        i++;
    }
    for(int j=1;j<i;j++)
    {
        for(int k=j+1;k<i;k++)
        {
            ans1=max(pao(j,k),ans1);
        }
    }

    cur=h[1];
    h[1]=0;
    ans2++;
    for(int j=2;j<i;j++)
    {
        if(h[j]!=0&&cur>=h[j])
        {
            cur=h[j];
            h[j]=0;
        }
    }
    pao2();
    cout<<ans1<<endl<<ans2<<endl;
    return 0;
}
