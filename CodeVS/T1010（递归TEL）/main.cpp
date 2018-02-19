#include <iostream>

using namespace std;
int a[21][21]={0},res=0,N,M,X,Y;;

void ma(int x,int y)
{
    a[x][y]=1;
    a[x-1][y+2]=1;
    a[x-1][y-2]=1;
    a[x+1][y+2]=1;
    a[x+1][y-2]=1;
    a[x-2][y+1]=1;
    a[x-2][y-1]=1;
    a[x+2][y+1]=1;
    a[x+2][y-1]=1;
}

void zu(int x,int y)
{
    if(x>N||y>M||a[x][y]==1)return;
    if(x==N&&y==M)res++;
    zu(x+1,y);
    zu(x,y+1);
}

int main()
{
    cin>>N>>M>>X>>Y;
    ma(X,Y);
    zu(0,0);
    cout<<res<<endl;
    return 0;
}
