#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=100008;
const int mo=100007;
int hash_ku[maxn],n,m;

void updata(int a)
{
    int i=a%mo;
    if(!hash_ku[i])
        hash_ku[i]=a;
    else
        while(1)
        {
            i++;
            if(i>=maxn)i=0;
            if(!hash_ku[i])
            {
                hash_ku[i]=a;
                return;
            }
        }
}

bool query(int a)
{
    int i=a%mo;
    if(hash_ku[i]==a)
        return 1;
    else if(!hash_ku[i])
        return 0;
    else
        while(1)
        {
            i++;
            if(i>=maxn)i=0;
            if(hash_ku[i]==a)
                return 1;
        }
}

int main()
{
    int i,a;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i)
    {
        scanf("%d",&a);
        updata(a+1);
    }
    for(i=0;i<m;++i)
    {
        scanf("%d",&a);
        if(query(a+1))
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
