#include <iostream>

using namespace std;

int main()
{
    int a[5];
    for (int i=1;i<=4;++i)cin>>a[i];
    int flag=0;
    for(int i=2;i<=4;++i){
        if(a[i]>a[i-1])flag++;
        if(a[i]<a[i-1])flag--;
    }
    if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4])cout<<"Fish At Constant Depth";
    else if(flag==3)cout<<"Fish Rising";
    else if(flag==-3)cout<<"Fish Diving";
    else cout<<"No Fish";
    return 0;
}
