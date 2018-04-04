#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;cin>>n;
    int b[n];
    memset(b,0,sizeof(b));
    string a;
    int sum=0;
    for(int i=0;i<n;++i){
        cin>>a;
        int len=a.length();
        int flag=true;
        for(int j=0;j<len;j++){
            if(a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z')continue;
            else {
                flag=false;
                break;
            }
        }
        if(flag){
            sum++;
            b[i]=i+1;
        }
    }
    cout<<sum<<endl;
    for(int i=0;i<n;i++){
        if(b[i]!=0)cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}
