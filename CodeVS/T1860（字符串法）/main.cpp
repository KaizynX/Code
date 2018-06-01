#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
string a[21];
int cmp(string a,string b)
{
    return a+b>b+a;
}
int main()
{
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n,cmp);
    for(int i=0;i<n;++i)cout<<a[i];
    return 0;
}
