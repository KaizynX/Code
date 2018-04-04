#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int m;cin>>m;
    string a;int b;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        int len=a.length();
        if(b>=len)b%=len;
        for(int j=len-b;j<len;++j)cout<<a[j];
        for(int j=0;j<len-b;++j)cout<<a[j];
        cout<<endl;
    }
    return 0;
}
