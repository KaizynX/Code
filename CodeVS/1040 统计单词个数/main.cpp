#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxs=10;
const int maxl=205;
const int maxk=45;
int N,p,k,s,a[maxl][maxl],f[maxl][maxk];
int n,i,j,ai,ki,len,fd;
bool v[maxl];
bool cmp(string a,string b)
{
    return a.length()<b.length();
}
//http://blog.csdn.net/maxwei_wzj/article/details/51959645
//a[i][j]表示区间（i,j）内所含的单词个数
//f[i][j]为字符串前i个字符分割成j份的最优解
//f[i][j]=max(f[i][j],f[k][j-1]+a[k+1][i])
int main()
{
    string S,line,word[maxs];
    scanf("%d",&N);
    for(n=0;n<N;++n)
    {
        scanf("%d%d",&p,&k);
        S="";
        memset(a,0,sizeof a);
        memset(f,0,sizeof f);
        for(i=0;i<p;++i)
        {
            cin>>line;
            S+=line;
        }
        len=S.length();
        scanf("%d",&s);
        for(i=1;i<=s;++i)
            cin>>word[i];
        sort(word+1,word+s+1,cmp);
        for(i=1;i<=len;++i)// a
            for(j=1;j<=len;++j)
            {
                memset(v,0,sizeof v);
                for(ai=1;ai<=s;++ai)
                {
                    fd=S.find(word[ai],i-1);
                    while(fd!=S.npos)
                    {
                        if(v[fd]);
                        else if(fd+word[ai].length()<=j)
                        {
                            v[fd]=1;
                            a[i][j]++;
                        }
                        fd=S.find(word[ai],fd+1);
                    }
                }
            }
        for(i=1;i<=k;++i)
            for(j=1;j<=len;++j)
                for(ki=i-1;ki<=j-1;++ki)
                    f[j][i]=max(f[j][i],f[ki][i-1]+a[ki+1][j]);
        printf("%d\n",f[len][k]);
    }
    return 0;
}
