#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
const int maxn=1000;
char a[maxn];
int main()
{
    int len;
    s.push(0);
    for(int i=1;i<=maxn;i++){
        cin>>a[i];
        if (a[i]='@'){
            len=i;
            break;
        }
    }
    for(int i=1;i<=len;i++){
        if(a[i]>='0' && a[i]<='9'){
            s.push(s.top()*10+a[i]);
        }
        switch (a[i]){
            case '+':
                int a=s.top();
                int b=s.top();
                s.push(a+b);
                break;
        }
    }
    return 0;
}
