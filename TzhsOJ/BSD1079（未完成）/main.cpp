#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int cmp(string a,string b)
{
    return a+b>b+a;
}

int main()
{
    string num[21];
    int n;//n<=20
    cin>>n;
    for(int i=0;i<n;i++)cin>>num[i];
    sort(num,num+n,cmp);
    for(int i=0;i<n;i++)cout<<num[i];
    return 0;
}
