#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int maxi=128;
const int maxl=100+5;

int main()
{
    freopen("3295.in","r",stdin);//
    freopen("3295.out","w",stdout);//
    int N,L,O,now,cur,x,y,cen,nc[maxl];
    char c;
    bool usei[maxi],res;
    stack<int> q;
    scanf("%d",&N);
    while(N--)
    {
        O=0;
        res=0;//1 err
        now=0;//n^now
        cen=0;
        memset(usei,0,sizeof usei);
        memset(nc,0,sizeof nc);

        scanf("%d",&L);
        if(L%2==1)res=1;
        c=getchar();
        while(c!='(')c=getchar();//O(
        c=getchar();
        if(c=='1')
        {
            c=getchar();//)
        }
        else if(c=='n')
        {
            c=getchar();//^
            c=getchar();
            while(c>='0'&&c<='9')
            {
                O=O*10+c-'0';
                c=getchar();//...)
            }
        }
        while(L--)
        {
            x=0;
            y=0;
            cin>>c;
            if(c=='F')
            {
                cen++;
                cin>>c;// i
                if(usei[c]==1 && res==0)
                    res=1;
                usei[c]=1;
                q.push(c);

                cin>>c;// x
                if(c>='0' && c<='9')
                {
                    while(c>='0' && c<='9')
                    {
                        x=x*10+c-'0';
                        c=getchar();
                    }
                }

                cin>>c;// y
                if(c>='0' && c<='9')
                {
                    while(c>='0' && c<='9')
                    {
                        y=y*10+c-'0';
                        c=getchar();
                    }
                }

                if(x!=0 && y==0)
                {
                    nc[cen]=nc[cen-1]+1;
                    now=max(now,nc[cen]);
                }
                else
                {
                    nc[cen]=nc[cen-1];
                }
            }
            else if(c=='E')
            {
                if(q.empty() && res==0)
                    res=1;
                else
                {
                    cen--;
                    cur=q.top();
                    q.pop();
                    usei[cur]=0;
                }
            }
        }
        if(res==1)printf("ERR\n");
        else if(now==O)printf("Yes\n");
        else if(now!=O)printf("No\n");
    }
    return 0;
}
