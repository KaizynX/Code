#include <iostream>
#include <cstdio>
#include <cstring>
#define fn find_name
using namespace std;
const int maxn=10+2;
int n,money[maxn];
string name[maxn];

int find_name(string now)
{
    for(int i=1;i<=n;++i)
        if(name[i]==now)return i;
}

int main()
{
    string give,given;
    int v,m;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>name[i];
    for(int j=1;j<=n;++j)
    {
        cin>>give>>v>>m;
        for(int i=1;i<=m;++i)
        {
            cin>>given;
            money[fn(given)]+=v/m;
            money[fn(give)]-=v/m;
        }
    }
    for(int i=1;i<=n;++i)
    {
        cout<<name[i]<<" "<<money[i]<<endl;
    }
    return 0;
}
