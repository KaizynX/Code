#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main()
{
    stack <int> s;
    char c=getchar();
    int cnt=0,a,b;
    while(c!='@')
    {
        if(c>='0' && c<='9')
        {
            cnt=cnt*10+c-'0';
        }
        else if(c=='.')
        {
            s.push(cnt);
            cnt=0;
        }
        else if(c=='+')
        {
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            s.push(a+b);
        }
        else if(c=='-')
        {
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            s.push(b-a);
        }
        else if(c=='*')
        {
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            s.push(a*b);
        }
        else if(c=='/')
        {
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            s.push(b/a);
        }
        c=getchar();
    }
    printf("%d\n",s.top());
    return 0;
}
