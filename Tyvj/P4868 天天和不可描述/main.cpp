#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int maxl=500005;
string S;
char c;
stack<int>q;
int len,num;
void change(int left,int right)
{
    S[left]=' ';
    S[right]=' ';
    left++;
    right--;
    while(left<right)
    {
        c=S[left];
        S[left]=S[right];
        S[right]=c;
        left++;
        right--;
    }
    cout<<S<<endl;
}
int main()
{
    freopen("unknown.in","r",stdin);
    freopen("unknown.out","w",stdout);
    int i;
    cin>>S;
    len=S.length();
    for(i=0;i<len;++i)
    {
        if(S[i]=='(')
            q.push(i);
        else if(S[i]==')')
        {
            change(q.top(),i);
            q.pop();
        }
    }
    for(i=0;i<len;++i)
        if(S[i]!=' ')
            putchar(S[i]);
    return 0;
}
