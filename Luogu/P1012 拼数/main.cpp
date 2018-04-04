#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=20+5;
int n;
string s[maxn];

bool cmp(string a,string b)
{
    return a+b>b+a;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>s[i];
    sort(s+1,s+1+n,cmp);
    for(int i=1;i<=n;++i)
        cout<<s[i];
    cout<<endl;
    return 0;
}
