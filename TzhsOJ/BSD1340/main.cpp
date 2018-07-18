#include <iostream>
#include<cstring>
using namespace std;
//49-74
int main()
{
    string a;
    cin>>a;
    int l=a.length();
    int n[200]={0};
    int minn=300,maxn=0,num,flag=1;
    for(int i=0;i<l;i++)
    {
        n[a[i]-'0']++;
    }
    for(int i=49;i<=74;i++)
    {
        if(n[i])
        {
            minn=min(n[i],minn);
            maxn=max(n[i],maxn);
        }
    }
    num=maxn-minn;
    if(num==0||num==1)
    {
        cout<<"No Answer"<<endl<<0<<endl;
    }
    else
    {
        for(int i=2;i<num;i++)
        {
            if(num%i==0)
            {
                cout<<"No Answer"<<endl<<0<<endl;
                flag=0;
                break;
            }
        }
        if(flag)cout<<"Lucky Word"<<endl<<num<<endl;
    }
    return 0;
}
