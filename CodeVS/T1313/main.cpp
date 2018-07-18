//超时的超时，错的错？？？
/*#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,ans=0,out=0;
    cin>>n;
    bool flag1=true,flag2=true;
    for(int i=1;i<=n;++i){
        int j;
        if(i!=1&&i!=2){
            for(int k=2;k<=sqrt(i);++k){
                if(i%k==0){
                    flag1=false;
                    break;
                }
            }
        }
        if(flag1){
            for(j=1;j<=n;++j){
                if(j!=1&&j!=2){
                    for(int k=2;k<=sqrt(j);++k){
                        if(j%k==0){
                            flag2=false;
                            break;
                        }
                    }
                }
                if(flag2)if(i*j==n)ans=max(i,j);
            }
        }
        out=max(ans,out);
        flag1=flag2=true;
    }
    cout<<out;
    return 0;
}
*/
//原理不明
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=2;i<n;i++){
        if(n%i==0){
            cout<<n/i;
            break;
        }
    }
    return 0;
}
