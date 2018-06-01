#include <iostream>
#include <cstdio>
#define LL long long
#define print printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,ans)
using namespace std;
const int maxn=20+5;

LL a,b,c,ans;
LL W[maxn][maxn][maxn];

LL w(LL a,LL b,LL c)
{
    LL res=0;
    if(a<=0 || b<=0 || c<=0)
        return 1;
    else if(a>20 || b>20 || c>20)
    {
        if(W[20][20][20])
            return W[20][20][20];
        W[20][20][20]=w(20,20,20);
        return W[20][20][20];
    }
    else if(a<b && b<c)
    {
        if(W[a][b][c-1])
        {
            res+=W[a][b][c-1];
        }
        else
        {
            W[a][b][c-1]=w(a,b,c-1);
            res+=W[a][b][c-1];
        }
        if(W[a][b-1][c-1])
        {
            res+=W[a][b-1][c-1];
        }
        else
        {
            W[a][b-1][c-1]=w(a,b-1,c-1);
            res+=W[a][b-1][c-1];
        }
        if(W[a][b-1][c])
        {
            res-=W[a][b-1][c];
        }
        else
        {
            W[a][b-1][c]=w(a,b-1,c);
            res-=W[a][b-1][c];
        }
        return res;
    }
    else
    {
        if(W[a-1][b][c])
        {
            res+=W[a-1][b][c];
        }
        else
        {
            W[a-1][b][c]=w(a-1,b,c);
            res+=W[a-1][b][c];
        }
        if(W[a-1][b-1][c])
        {
            res+=W[a-1][b-1][c];
        }
        else
        {
            W[a-1][b-1][c]=w(a-1,b-1,c);
            res+=W[a-1][b-1][c];
        }
        if(W[a-1][b][c-1])
        {
            res+=W[a-1][b][c-1];
        }
        else
        {
            W[a-1][b][c-1]=w(a-1,b,c-1);
            res+=W[a-1][b][c-1];
        }
        if(W[a-1][b-1][c-1])
        {
            res-=W[a-1][b-1][c-1];
        }
        else
        {
            W[a-1][b-1][c-1]=w(a-1,b-1,c-1);
            res-=W[a-1][b-1][c-1];
        }
        return res;
    }
}

int main()
{
    while(1)
    {
        cin>>a>>b>>c;
        if(a==-1 && b==-1 && c==-1)
            break;
        ans=w(a,b,c);
        print;
    }
    return 0;
}
