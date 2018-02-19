#include <iostream>

using namespace std;
int a[18][2];
int xian(int x,int y){
    if(a[x][y]==0)return 0;
    cout<<a[x][y]<<" ";
    xian(a[x][y],0);
    xian(a[x][y],1);
}
int zhong(int x,int y){
    if(a[x][y]==0)return 0;
    zhong(a[x][y],0);
    cout<<a[x][y]<<" ";
    zhong(a[x][y],1);
}
int hou(int x,int y){
    if(a[x][y]==0)return 0;
    hou(a[x][y],0);
    hou(a[x][y],1);
    cout<<a[x][y]<<" ";
}
int main()
{
    int n;cin>>n;
    a[0][0]=a[0][1]=1;
    for(int i=1;i<=n;++i){
        cin>>a[i][0]>>a[i][1];
    }
    xian(0,0);cout<<endl;
    zhong(0,0);cout<<endl;
    hou(0,0);cout<<endl;
    return 0;
}
