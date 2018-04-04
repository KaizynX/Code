#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=6+2;
int a[maxn],pos;
string b[maxn];
string nu[10]={"0","1","2","3","4","5","6","7","8","9"};
string num[30]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","a","both","another","first","second","third"};

bool cmp(string a,string b)
{
    return a+b<b+a;
}

void Find(string s)
{
    int cur,j;
    for(int i=0;i<=26;++i)
    {
        if(s==num[i])
        {
            pos++;
            if(i==21 || i==23 || i==24)j=1;
            else if(i==22 || i==25)j=2;
            else if(i==26)j=3;
            else j=i;
            a[pos]=j*j;
            cur=a[pos]%10;
            b[pos]=nu[cur];
            cur=a[pos]/10%10;
            b[pos]=nu[cur]+b[pos];
            break;
        }
    }
}

int main()
{
    int pos0=0,flag=1;
    string s,ans;
    for(int i=1;i<=6;++i)
    {
        cin>>s;
        Find(s);
    }
    sort(b+1,b+1+pos,cmp);
    for(int i=1;i<=pos;++i)
    {
        ans+=b[i];
    }
    for(int i=0;i<ans.length();++i)
    {
        if(ans[i]=='0'&&flag)pos0++;
        else flag=0;
    }
    for(int i=pos0;i<ans.length();++i)
    {
        cout<<ans[i];
    }
    if(pos==0)cout<<0;
    cout<<endl;
    return 0;
}
