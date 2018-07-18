#include <iostream>
#include <cmath>
#include <cstdio>
int a[101][101];
using namespace std;
int main()
{
      int n,i,j;
      int mark2,sum=0;
      int x,y,tx,ty;
      cin >> n;
      x=n/2,y=n/2;
      for(i=1;i<=n/2+1;++i){
          mark2=((2*i-1)*(2*i-1));
          tx=x+i;ty=y+i;
          a[tx][ty]=mark2;
          for(j=1;j<2*i-1;++j)a[tx][--ty]=--mark2;
          for(j=1;j<2*i-1;++j)a[--tx][ty]=--mark2;
          for(j=1;j<2*i-1;++j)a[tx][++ty]=--mark2;
          for(j=1;j<2*i-2;++j)a[++tx][ty]=--mark2;
      }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;++j){
             if(i==j||i+j==n+1)sum+=a[i][j];
             printf("%d ",a[i][j]);//这里用"%6d"比较好看的。。。
         }
        cout<<"\n";
    }
    cout<<sum;
    return 0;
}
