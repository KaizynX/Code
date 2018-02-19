#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxm = 55;
const int maxn = 1005;
int R,C,N,T[maxm][maxm],D[maxn],V[maxm][maxm];
int dir[4][2]={-1,0,1,0,0,-1,0,1};
queue<int> qx,qy;

void bfs (int sum,int n)
{
    int x,y,d,rsum=0;
    for(int i=0;i<sum;++i)
    {
        x=qx.front();
        y=qy.front();
        qx.pop();
        qy.pop();
        d=D[n];
        x+=dir[d][0];
        y+=dir[d][1];
        while(T[x][y])
        {
            if(V[x][y]!=n)
            {
                qx.push(x);
                qy.push(y);
                V[x][y]=n;
                rsum++;
            }
            x+=dir[d][0];
            y+=dir[d][1];
        }
    }
    if(n==N)
    {
        for(int i=0;i<rsum;++i)
        {
            x=qx.front();
            y=qy.front();
            qx.pop();
            qy.pop();
            T[x][y]=2;
        }
        return;
    }
    else bfs(rsum,n+1);
}

int main()
{
    int i,j,bx,by;
    char a;
    string s;
    scanf("%d%d",&R,&C);
    for(i=1;i<=R;++i)
        for(j=1;j<=C;++j)
        {
            cin>>a;
            if(a=='.')
                T[i][j]=1;
            else if(a=='*')
            {
                T[i][j]=1;
                bx=i;
                by=j;
            }
        }
    scanf("%d",&N);
    for(i=1;i<=N;++i)
    {
        cin>>s;
        if(s=="NORTH")
            D[i]=0;
        else if(s=="SOUTH")
            D[i]=1;
        else if(s=="WEST")
            D[i]=2;
        else if(s=="EAST")
            D[i]=3;
    }
    qx.push(bx);
    qy.push(by);
    V[bx][by]=1;
    bfs(1,1);
    for(i=1;i<=R;++i)
    {
        for(j=1;j<=C;++j)
        {
            if(T[i][j]==0)
                putchar('X');
            else if(T[i][j]==1)
                putchar('.');
            else putchar('*');
        }
        printf("\n");
    }
    return 0;
}
