#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=505;
struct node
{
    int num[maxn],len;
};

node a,b,ans;

void read(node* n)
{
    string s;
    cin>>s;
    int l=s.length();
    (*n).len=l;
    for(int i=1;i<=l;++i)
        (*n).num[i]=s[l-i]-'0';
}

void hplus(node a,node b,node* ans)
{
    int l=max(a.len,b.len),cur,ansl;
    for(int i=1;i<=l;++i)
    {
        cur=a.num[i]+b.num[i];
        (*ans).num[i]+=cur;
        ansl=i;
        while((*ans).num[ansl]>9)
        {
            (*ans).num[ansl+1]+=(*ans).num[ansl]/10;
            (*ans).num[ansl]%=10;
            ansl++;
        }
    }
    if((*ans).num[l+1])
        (*ans).len=l+1;
    else (*ans).len=l;
}

void print(node a)
{
    for(int i=a.len;i>=1;--i)
        printf("%d",a.num[i]);
}

int main()
{
    read(&a);
    read(&b);
    hplus(a,b,&ans);
    print(ans);
    return 0;
}
