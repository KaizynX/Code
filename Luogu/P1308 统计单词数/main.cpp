#include <iostream>
#include <cstdio>
#include <cstring>
#define A 'A'-'a'
using namespace std;
string a,b;
int pos,ans,cur;

inline void change(string &a)
{
    for(int i=0;i<a.length();++i)
    {
        if(a[i]>='A' && a[i]<='Z')
            a[i]-=A;
    }
}

int main()
{
    getline(cin,a);
    getline(cin,b);
    change(a);
    change(b);
    a=" "+a+" ";
    b=" "+b+" ";
    if(b.find(a)==b.npos)
    {
        cout<<-1<<endl;
    }
    else
    {
        cur=b.find(a);
        pos=cur;
        while(cur!=b.npos)
        {
            ans++;
            cur=b.find(a,cur+1);
        }
        cout<<ans<<" "<<pos<<endl;
    }
    return 0;
}
