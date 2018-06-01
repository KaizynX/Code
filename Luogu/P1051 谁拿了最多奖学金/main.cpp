#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100+5;

int n,v,sum;
string name;

int main()
{
    char c;
    int a1,a2,a3,a4,a5,m;
    string now;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        cin>>now;
        cin>>a1>>a2;
        cin>>c;
        if(c=='Y')a3=1;
        else if(c=='N')a3=0;
        cin>>c;
        if(c=='Y')a4=1;
        else if(c=='N')a4=0;
        cin>>a5;
        m=0;
        if(a1>80 && a5>=1)m+=8000;
        if(a1>85 && a2>80)m+=4000;
        if(a1>90)m+=2000;
        if(a1>85 && a4==1)m+=1000;
        if(a2>80 && a3==1)m+=850;
        sum+=m;
        if(m>v)
        {
            v=m;
            name=now;
        }
    }
    cout<<name<<endl;
    cout<<v<<endl;
    cout<<sum<<endl;
    return 0;
}
