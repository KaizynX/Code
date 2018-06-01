#include <iostream>

using namespace std;

int main()
{
    int T,step=0;
    cin>>T;
    int a[T];
    for(int i=1;i<=T;i++){
        cin>>a[i];
    }
    for(int i=1;i<=T;i++){
        if(a[i]==1)cout<<"0"<<endl;
        else {
            while(a[i]!=1){
                if(a[i]%2==1){
                    a[i]=3*a[i]+1;
                }else{
                    a[i]=a[i]/2;
                }
                step++;
            }
            cout<<step<<endl;
            step=0;
        }
    }
    return 0;
}
