#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1][n+1];
    memset(a,0,sizeof(a));
    int i=n,j=n;
    int t=n*n;
    while(t>1){
        while(i<n&&(a[i+1][j]==0)){
            a[i][j]=t;
            t--;
            i++;
        }
        while(j>1&&(a[i][j-1]==0)){
            a[i][j]=t;
            t--;
            j--;
        }
        while(i>1&&(a[i-1][j]==0)){
            a[i][j]=t;
            t--;
            i--;
        }
        while(j<n&&(a[i][j+1]==0)){
            a[i][j]=t;
            t--;
            j++;
        }
    }
    int tot=0;
    a[(n/2)+1][(n/2)+1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
            if(i==j||i+j==n+1)tot+=a[i][j];
        }
    cout<<endl;
    }
    cout<<tot;
    return 0;
}
