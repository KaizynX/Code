#include <iostream>
//Êý¾Ý·¶Î§ 1 ¡Ü L ¡Ü R¡Ü 10000
using namespace std;
int a[6];
int main()
{
    int l,r,ans=0;
    cin>>l>>r;
    for(int i=l;i<=r;++i){
        a[1]=i%10;
        a[2]=(i%100)/10;
        a[3]=(i%1000)/100;
        a[4]=(i%10000)/1000;
        a[5]=(i%100000)/10000;
        for(int j=1;j<=5;++j){
            if(a[j]==2)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
