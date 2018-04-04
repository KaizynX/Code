#include <iostream>
//—œ÷ÿ≥¨ ±
using namespace std;

const int maxn=5;
int h[maxn],nh[maxn];
int step=0;

int jimu(int left,int right)
{
    if(left==right+1)return step;
    int flag=0;
    for(int i=left;i<=right;i++){
        if(nh[i]==h[i]){
            int nright=i;
            jimu(left,nright-1);
            jimu(nright+1,right);
        }
        else flag++;
    }
    if(flag==right-left+1){
        for(int i=left;i<=right;i++)nh[i]++;
        step++;
    }
    int judge=0;
    for(int i=left;i<=right;i++){
        if(nh[i]==h[i])judge++;
    }
    if(judge==right-left+1)return step;
    else return jimu(left,right);
}

int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>h[i];
    cout<<jimu(0,n-1);
    return 0;
}
