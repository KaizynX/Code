#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int s=0;
    bool flag=true;
    for(int i=2;i<=n;i++){
        int b=sqrt(i);
        for(int j =2;j<=b;j++){
            if(i%j==0){
                flag=false;
                break;
            }
        }
        if(flag)s++;
        flag=true;
    }
    cout<<s;
    return 0;
}
