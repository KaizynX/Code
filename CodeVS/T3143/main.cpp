#include <iostream>

using namespace std;
int a[18][3];
int n,fa1,fa2;
void findfather(int a1,int a2){
    int flag=false;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=1;++j){
            if(a1==a[i][j]){
               fa1=i;fa2=j;
               flag=true;
               break;
            }
        }
        if(flag)break;
    }
}
int main()
{
    int q1=0,q2=0,time=0;
    cin>>n;
    a[0][0]=1;a[0][1]=0;
    for(int i=1;i<=n;++i)cin>>a[i][0]>>a[i][1];
    //前序排列
    while(a[q1][q2]!=0){
        if(time>=n)break;
        cout<<a[q1][q2]<<" ";
        if(a[a[q1][q2]][q2]!=0)q1=a[q1][q2];
        else if(a[a[q1][q2]][q2+1]!=0){q1=a[q1][q2];q2++;}
        else if(a[q1][q2+1]!=0)q2++;
        else {//返回父亲节点
            findfather(q1,q2);
            q1=fa1;q2=fa2+1;
            while(a[q1][q2]==0){
                if(q1==0)break;
                findfather(q1,q2);
                q1=fa1;q2=fa2+1;
            }
        }
        ++time;
    }
    //中序遍历

    //后序遍历
    return 0;
}
