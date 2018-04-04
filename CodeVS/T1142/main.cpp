#include <iostream>
using namespace std;
const int maxn=301;
int main()
{
    int n;cin>>n;
    int a[maxn][3],b[maxn][3];
    for(int i=1;i<=n;++i){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        b[i][0]=i;//学号
        b[i][2]=a[i][0];//语文成绩
        b[i][1]=a[i][0]+a[i][1]+a[i][2];//总分
    }
    for(int j=2;j<=n;++j){
        for(int i=1;i<=n;++i){
            if(b[i][1]>b[j][1]){
                swap(b[i][1],b[j][1]);
                swap(b[i][0],b[j][0]);
                swap(b[i][2],b[j][2]);
            }
            else if(b[i][1]==b[j][1]){
                if(b[i][2]>b[j][2]){
                    swap(b[i][1],b[j][1]);
                    swap(b[i][0],b[j][0]);
                    swap(b[i][2],b[j][2]);
                }
            }
        }
    }
    for(int i=n;i>n-5;--i){
        cout<<b[i][0]<<" "<<b[i][1]<<endl;
    }
    return 0;
}
