#include <iostream>
#include <string>
using namespace std;

int main()
{
    string n;
    int m,ans=0,s=1;
    cin>>n>>m;
    for(int j=n.length()-1;j>=0;j--){
        if(n[j]=='A')ans+=10*s;
        else if(n[j]=='B')ans+=11*s;
        else if(n[j]=='C')ans+=12*s;
        else if(n[j]=='D')ans+=13*s;
        else if(n[j]=='E')ans+=14*s;
        else if(n[j]=='F')ans+=15*s;
        else ans+=(n[j]-'0')*s;
        s*=m;
    }
    cout<<ans<<endl;
    return 0;
}
