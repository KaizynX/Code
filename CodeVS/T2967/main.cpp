#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        int len=a.length();
        int flag1=0,flag2=0;
        for(int j=0;j<len;j++){
            if(a[j]=='R'&&flag1==0){flag1++;flag2++;}
            if(a[j]=='K'&&flag1==1){flag1++;flag2++;}
            if(a[j]=='Y'&&flag1==2){flag1++;flag2++;}
        }
        if(flag2==3)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
