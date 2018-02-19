#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=10;//200000;

struct shuzu
{
    string a;
    int sum;
}zu[maxn];

int cmp(shuzu x,shuzu y)
{
    if(x.a.length()>y.a.length())return 0;
    else if(x.a.length()<y.a.length())return 1;
    else return x.a<y.a;
}

int main()
{
    int n;
    scanf("%d",&n);
    string b;
    int flag=0,flag2;
    for(int i=0;i<n;i++)
    {
        flag2=1;
        cin>>b;//scanf("%s",b);
        for(int j=0;j<flag;j++)
        {
            if(b==zu[j].a)
            {
                zu[j].sum++;
                flag2=0;
                break;
            }
        }
        if(flag2)
        {
            zu[flag].a=b;
            zu[flag].sum++;
            flag++;
        }
    }
    if(flag2)flag--;
    sort(zu,zu+flag,cmp);
    for(int i=0;i<flag;i++)
        cout<<zu[i].a<<" "<<zu[i].sum<<endl;//printf("%s %d\n",a[i],sum[i]);
    return 0;
}
