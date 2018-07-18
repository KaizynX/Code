#include <iostream>
#include <stack>
using namespace std;
//从内到外必须是<>、()、[]、{}
int main()
{
    int n,l;
    string a;
    stack<char>s;
    cin>>n;
    while(n--)
    {
        cin>>a;
        l=a.length();
        for(int i=0;i<l;i++)
        {
            if(a[i]=='('||a[i]=='['||a[i]=='<'||a[i]=='{')
            {
                if(s.empty()||s.top()=='{')s.push(a[i]);
                else if(s.top()=='[')
                {
                    if(a[i]=='{')break;
                    s.push(a[i]);
                }
                else if(s.top()=='(')
                {
                    if(a[i]=='('||a[i]=='<')s.push(a[i]);
                    else break;
                }
                else
                {
                    if(a[i]=='<')s.push(a[i]);
                    else break;
                }
            }
            else
            {
                if(a[i]==')')
                {
                    if(!s.empty()&&s.top()=='(')s.pop();
                    else {s.push(0);break;}
                }
                else if(a[i]==']')
                {
                    if(!s.empty()&&s.top()=='[')s.pop();
                    else {s.push(0);break;}
                }
                else if(a[i]=='>')
                {
                    if(!s.empty()&&s.top()=='<')s.pop();
                    else {s.push(0);break;}
                }
                else
                {
                    if(!s.empty()&&s.top()=='{')s.pop();
                    else {s.push(0);break;}
                }
            }
        }
        if(s.empty())cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        while(!s.empty())s.pop();
    }
    return 0;
}
