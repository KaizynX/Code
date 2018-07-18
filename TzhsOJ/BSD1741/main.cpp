#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int>s;
    int n,a,flag=1,judge;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(!s.empty()&&s.top()==a)s.pop();
        else
        {
            judge=0;
            for(int j=flag;j<=n;j++)
            {
                flag++;
                s.push(j);
                if(s.top()==a)
                {
                    s.pop();
                    judge=1;
                    break;
                }
            }
        }
    }
    if(!judge)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}
