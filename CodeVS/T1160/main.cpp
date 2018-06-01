#include <iostream>

using namespace std;
int a[200][200];
int main()
{
    int n,x,y,x1,y1,flag,sum=0;
    cin>>n;
    x1=y1=n/2;
    for(int i=1;i<=n/2+1;i++){
        flag=(i*2-1)*(i*2-1);
        x=x1+i;
        y=y1+i;
        a[x][y]=flag;
        for(int j=1;j<2*i-1;j++)a[x][--y]=--flag;
        for(int j=1;j<2*i-1;j++)a[--x][y]=--flag;
        for(int j=1;j<2*i-1;j++)a[x][++y]=--flag;
        for(int j=1;j<2*i-2;j++)a[++x][y]=--flag;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j||i+j==n+1)sum+=a[i][j];
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<sum;
    return 0;
}
