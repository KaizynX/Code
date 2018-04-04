#include <iostream>
#include <cstring>
using namespace std;
//这里空格是什么意思
int main()
{
    string a,b;
    cin>>a;
    for(int i=0;i<a.length();i++){
        if(a[i]>='A'&&a[i]<='Z')a[i]+=32;
    }
    int sum=0,location=0,now=-1;
    while(cin>>b){
        for(int i=0;i<b.length();i++){
            if(b[i]>='A'&&b[i]<='Z')b[i]+=32;
        }
        if(a==b){
            sum++;
            if(location==-1)location=now;
        }
        now++;
    }
    if(sum==0)cout<<-1<<endl;
    else {
        cout<<sum<<" "<<location<<endl;
    }
    return 0;
}
