#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char c[501];
    string a,b;
    cin>>a>>b;
    int la=a.length(),lb=b.length(),flag3=0;

    if(la<lb)
    {
        flag3=1;
        string ab=a;
        a=b;
        b=ab;
    }
    else if(la==lb)
    {
        for(int i=0;i<la;i++)
        {
            if(a[i]==b[i])continue;
            else if(a[i]>b[i])break;
            else
            {
                flag3=1;
                string ab=a;
                a=b;
                b=ab;
            }
        }
    }
    //½»»»²âÊÔÕýÈ·
    la=a.length(),lb=b.length();
    while(la>lb)
    {
        b='0'+b;
        lb++;
    }
    int flag=0;
    for(int i=1;i<=la;i++)
    {
            int na=a[la-i]-'0',nb=b[lb-i]-'0';
            if(na>nb)
            {
                c[i]=na-nb-flag+'0';
                flag=0;
            }
            else if(na==nb)
            {
                if(flag)c[i]='9';
                else c[i]='0';
            }
            else
            {
                c[i]=na-nb+10-flag+'0';
                flag=1;
            }
    }
    int flag2=1;
    if(flag3)cout<<'-';

        for(int i=la;i>0;i--)
            {
            if(c[i]=='0'&&flag2)continue;
            else
            {
                flag2=0;
                cout<<c[i]-'0';
            }
        }
        cout<<endl;

    return 0;
}
