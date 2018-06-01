#include <iostream>

using namespace std;

int main()
{
    int n;cin>>n;
    int f,now=0,time=0;
    for(int i=0;i<n;i++){
        cin>>f;
        if(f>now)time+=6*(f-now);
        else if(f<now)time+=4*(now-f);
        now=f;
        time+=5;
    }
    cout<<time;
    return 0;
}
