#include <iostream>
#include <cstdio>
#include <cstring>
#define A 'A'  //num[0]==num[A]
using namespace std;
const int N=30;
int n,num[N];
bool use[N],flag=0,jin[N];
string sa,sb,sc;//sa+sb=sc

inline int pd(int a,int b,int c,int cur)
{
    int tmp=num[a]+num[b]+jin[cur+1];
    if(tmp>=n)
    {
        tmp%=n;
        jin[cur]=1;//s0
    }
    if(num[c]==-1)
    {
        if(use[tmp]==1)return 0;
        num[c]=tmp;//s0
        use[tmp]=1;//s0
        return 2;
    }
    else
    {
        if(tmp%n!=num[c])
            return 0;
        else return 1;
    }
}

void solve(int cur)
{
    if(cur<0)
    {
        for(int i=0;i<n-1;++i)
            printf("%d ",num[i]);
        printf("%d\n",num[n-1]);
        flag=1;
        return;
    }
    if(flag)return;//have found it

    int a=sa[cur]-A;
    int b=sb[cur]-A;
    int c=sc[cur]-A;
    int i,j,flagc=0,lj;
    if(num[a]==-1&&num[b]==-1)
    {
        for(i=0;i<n;++i)
        {
            if(use[i]==1)continue;
            num[a]=i;//s1
            use[i]=1;//s2
            for(j=0;j<n;++j)
            {
                if(use[j]==1)continue;
                num[b]=j;//s3
                use[j]=1;//s4
                lj=jin[cur];
                flagc=pd(a,b,c,cur);
                if(flagc==0)
                {
                    use[j]=0;//s4
                    jin[cur]=lj;
                    continue;
                }
                solve(cur-1);
                use[j]=0;//s4
                if(flagc==2)
                {
                    use[num[c]]=0;//s0
                    jin[cur]=lj;//s0
                    num[c]=-1;//s0
                }
            }
            use[i]=0;//s2
        }
        num[a]=-1;//s1
        num[b]=-1;//s3
    }
    else if(num[a]!=-1&&num[b]!=-1)
    {
        lj=jin[cur];
        flagc=pd(a,b,c,cur);
        if(flagc==0)return;
        solve(cur-1);
        if(flagc==2)//s0
        {
            use[num[c]]=0;
            jin[cur]=lj;
            num[c]=-1;
        }
    }
    else
    {
        if(num[a]==-1)
        {
            for(i=0;i<n;++i)
            {
                if(use[i]==1)continue;
                num[a]=i;//s6
                use[i]=1;//s7

                lj=jin[cur];
                flagc=pd(a,b,c,cur);
                if(flagc==0)
                {
                    use[i]=0;
                    jin[cur]=lj;//s7
                    continue;
                }
                solve(cur-1);
                if(flagc==2)//s0
                {
                    use[num[c]]=0;
                    jin[cur]=lj;
                    num[c]=-1;
                }
                use[i]=0;//s7
            }
            num[a]=-1;//s6
        }
        else if(num[b]==-1)
        {
            for(i=0;i<n;++i)
            {
                if(use[i]==1)continue;
                num[b]=i;//s8
                use[i]=1;//s9

                lj=jin[cur];
                flagc=pd(a,b,c,cur);
                if(flagc==0)
                {
                    use[i]=0;
                    jin[cur]=lj;//s9
                    continue;
                }
                solve(cur-1);
                if(flagc==2)//s0
                {
                    use[num[c]]=0;
                    jin[cur]=lj;
                    num[c]=-1;
                }
                use[i]=0;//s9
            }
            num[b]=-1;//s8
        }
    }
}

int main()
{
    scanf("%d",&n);
    cin>>sa>>sb>>sc;
    for(int i=0;i<n;++i)num[i]=-1;
    solve(sa.length()-1);
    return 0;
}
/**TLE
21
BADCEFGHIJKLMNOPQRSTU
BADCEFGHIJKLMNOPQRSTU
BDEGIKMOQTBDEGIKMOQST
**/
