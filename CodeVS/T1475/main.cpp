#include <iostream>
//×Ö·û´®£¬Ê§°Ü
using namespace std;
char a[10];
int main()
{
    int m,i=1,n1,ans=0,s=1;
    while (cin>>a[0]){
        if(a[0]==' ')break;
        a[i]=a[0];
        i++;
    }
    m=a[0];
    n1=i-1;
    for(int j=n1;j>=1;j--){
        if(a[j]=='A')a[j]='10';
        else if(a[j]=='B')a[j]='11';
        else if(a[j]=='C')a[j]='12';
        else if(a[j]=='D')a[j]='13';
        else if(a[j]=='E')a[j]='14';
        else if(a[j]=='F')a[j]='15';
        ans+=(a[j]-'0')*s;
        s*=m;
    }
    cout<<ans<<endl;
    return 0;
}
