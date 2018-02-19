#include <iostream>
//成功按照 自己的意志，但题目理解错了
using namespace std;
int bag=6,a[7],sum=0,i;

int fuc(int b)
{
    int flag=false,j1;
    for(int j=6;j>=1;j--){
        if(a[j]==0)continue;
        if(bag>=j){
            bag-=j;
            a[j]--;
            flag=true;
            j1=j;
            break;
        }
    }
    if(bag==0){bag=6;sum++;}
    if(a[j1]!=0&&flag)return fuc(1);
    if(a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0&&a[6]==0)return 1;
    else return fuc(1);
}
int main()
{
    while(1){
        for(int i=1;i<=6;++i)cin>>a[i];
        if(a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0&&a[6]==0)break;
        else fuc(1);
        cout<<sum;
        sum=0;
    }
    return 0;
}
