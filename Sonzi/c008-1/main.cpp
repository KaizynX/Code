#include <iostream>
#include <cstdio>
#include <iomanip>
#include <stack>
using namespace std;

int main()
{
    cout<<setprecision(2)<<setiosflags(ios::fixed);
    stack<double> sta;
    char ch;
    while(scanf("%c",&ch)==1 && ch!='@'){
        if(ch==' ')continue;
        double num=0,k=1;
        bool flag1=false,flag2=false;
        while(ch>='0'and ch<='9'){
           flag1=true;
           if(flag2){k*=10;}
           num=num*10+ch-'0';
           scanf("%c",&ch);
           if(ch=='.'){
              flag2=true;
              k=1;
              scanf("%c",&ch);
           }
        }
        if(flag1 and flag2) {num/=k;}
        if(flag1){sta.push(num);}
        if(ch=='+'){
            double b=sta.top();
            sta.pop();
            double a=sta.top();
            sta.pop();
            sta.push(a+b);
        }
        if(ch=='-'){
            double b=sta.top();
            sta.pop();
            double a=sta.top();
            sta.pop();
            sta.push(a-b);
        }
        if(ch=='*'){
            double b=sta.top();
            sta.pop();
            double a=sta.top();
            sta.pop();
            sta.push(a*b);
        }
        if(ch=='/'){
            double b=sta.top();
            sta.pop();
            double a=sta.top();
            sta.pop();
            sta.push(a/b);
        }
    }
    cout<<sta.top()<<endl;
    return 0;
}

