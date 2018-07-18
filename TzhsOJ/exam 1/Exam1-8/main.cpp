#include <iostream>
#include <string>
//自己写的，不知所错。。。
using namespace std;
int righ[400]={0},lef[400]={0};
int main()
{
    int n,len,sum=0,flag1=0,flag2=0;
    cin>>n;
    string a,b;
    cin>>a;
    b=a+a+a;
    len=b.length();
    b[len]='w';
    b[-1]='w';
    for(int i=0;i<len;++i){
        if(b[i]=='w'){
            for(int j=1;j<=flag1;++j)++righ[i-j];
            ++flag1;
        }
        else if(b[i]==b[i-1])flag1++;
        else if(b[i]!=b[i-1])flag1=1;
        righ[i]=flag1;
    }
    for(int i=len-1;i>=0;--i){
        if(b[i]=='w'){
            for(int j=1;j<=flag2;++j)++lef[i+j];
            ++flag2;
        }
        else if(b[i]==b[i+1])flag2++;
        else if(b[i]!=b[i+1])flag2=1;
        lef[i]=flag2;
    }
    for(int i=0;i<len;++i){
        sum=max((righ[i+1]+lef[i]),sum);
    }
    cout<<sum;
    return 0;
}
