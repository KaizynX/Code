#include <iostream>

using namespace std;
int h[10]={6,2,5,5,4,5,6,3,7,6};

int match(int num)
{
    int a[4]={0},flag=0,ans=0;
    a[3]=num/1000;
    a[2]=(num%1000)/100;
    a[1]=(num%100)/10;
    a[0]=num%10;
    for(int i=3;i>=0;i--)
    {
        if(a[i]!=0)flag=1;
        if(flag)ans+=h[a[i]];
    }
    if(flag)return ans;
    else return h[0];
}

int main()
{
    int n,a,b,res=0;
    cin>>n;
    n-=4;
    for(int i=0;i<=1000;i++)
    {
        a=match(i);
        for(int j=0;j<=1000;j++)
        {
            b=match(j);
            if(n-a-b==match(i+j))res++;
        }
    }
    cout<<res<<endl;
    return 0;
}
