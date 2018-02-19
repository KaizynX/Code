#include <iostream>

using namespace std;

int main()
{
    int x;
    cin>>x;
    int f[50];
    f[0]=f[1]=5;
    if(x>=0)cout<<5<<endl;
    else{
        for(int i=-1;i>=x;--i){
            f[i]=f[i+1]+f[i+2]+1;
        }
        cout<<f[x]<<endl;
    }
    return 0;
}
