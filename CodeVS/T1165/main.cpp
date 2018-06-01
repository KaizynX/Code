#include <iostream>
#include <cstring>
using namespace std;
int p1,p2,p3;
char now,last;
string a,out="";
int change (int i)
{
    char next=a[i+1];
    if(last==next)
    {
        out+='-';
        return 0;
    }
    else if(last>='a'&&last<='z'&&next>='a'&&next<='z'
    ||last>='A'&&last<='Z'&&next>='A'&&next<='Z'
    ||last>='0'&&last<='9'&&next>='0'&&next<='9')
    {
        if(p1==3)
        {
            for(char i=last+1;i<next;++i)
            {
                for(int j=0;j<p2;j++)out+='*';
            }
        }
        if(p1==1)
        {
            if(p3==1)
            {
                for(char i=last+1;i<next;++i)
                {
                    for(int j=0;j<p2;j++)
                    {
                        if(i>='a'&&i<='z'||i>='0'&&i<='9')out+=i;
                        else if(i>='A'&&i<='Z')out+=i+32;
                    }
                }
            }
            else if(p3==2)
            {
                for(char i=next-1;i>last;--i)
                {
                    for(int j=0;j<p2;j++)
                    {
                        if(i>='a'&&i<='z'||i>='0'&&i<='9')out+=i;
                        else if(i>='A'&&i<='Z')out+=i+32;
                    }
                }
            }
        }
        else if(p1==2)
        {
            if(p3==1)
            {
                for(char i=last+1;i<next;++i)
                {
                    for(int j=0;j<p2;j++)
                    {
                        if(i>='A'&&i<='Z'||i>='0'&&i<='9')out+=i;
                        else if(i>='a'&&i<='z')out+=i-32;
                    }
                }
            }
            else if(p3==2)
            {
                for(char i=next-1;i>last;--i)
                {
                    for(int j=0;j<p2;j++)
                    {
                        if(i>='A'&&i<='Z'||i>='0'&&i<='9')out+=i;
                        else if(i>='a'&&i<='z')out+=i-32;
                    }
                }
            }
        }
    }
    else out+='-';
}

int main()
{
    cin>>p1>>p2>>p3;
    cin>>a;
    for(int i=0;i<a.length();i++)
    {
        now=a[i];
        if(now=='-')
        {
            change(i);
        }
        last=now;
        if(now!='-')out+=now;
    }
    cout<<out;
    return 0;
}
