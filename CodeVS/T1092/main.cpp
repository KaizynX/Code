#include <iostream>

using namespace std;

int main()
{
    int a[8][2],b[8],c[8]={0};
    for(int i=1;i<=7;++i){
        cin>>a[i][0]>>a[i][1];
        b[i]=a[i][0]+a[i][1];
        if(b[i]>8)c[i]=b[i]-8;
    }
    if(c[1]==0&&c[2]==0&&c[3]==0&&c[4]==0&&c[5]==0&&c[6]==0&&c[7]==0)cout<<0;
    else{
        int flag1=c[1],flag2;
        for(int i=2;i<=7;++i){
            if(c[i]>flag1){
                flag1=c[i];
                flag2=i;
            }
        }
        cout<<flag2;
    }
    return 0;
}
