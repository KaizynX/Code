#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
#define num ('A'-1)
#define mo 47
using namespace std;
string ans[2]={"STAY","GO"};
int main()
{
    int i;
    LL na=1,nb=1;
    string a,b;
    cin>>a>>b;
    for(i=0;i<a.length();++i)
        na*=a[i]-num;
    for(i=0;i<b.length();++i)
        nb*=b[i]-num;
    na%=mo;
    nb%=mo;
    cout<<ans[na==nb]<<endl;
    return 0;
}
