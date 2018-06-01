#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int main()
{
    string a;cin>>a;
    int len=a.length();
    int numx=0,numn=0,num=0;
    int flag=0;
    char x;
    int i=0;
    while(a[i]!='='){
        if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9')num=num*10+a[i]-'0';
        else {
            if(a[i]=='-'){
                if(flag==1)numn+=num;
                if(flag==0)numn-=num;
                num=0;
                flag=1;
            }
            else if(a[i]=='+'){
                if(flag==1)numn+=num;
                if(flag==0)numn-=num;
                num=0;
                flag=0;
            }
            else {
                x=a[i];
                if(flag==1)numx-=num;
                if(flag==0)numx+=num;
                num=0;
            }
        }
        i++;
    }
    if(flag==1)numn+=num;
    if(flag==0)numn-=num;
    num=0;
    flag=0;
    for(i+=1;i<len;i++){
        if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9')num=num*10+a[i]-'0';
        else {
            if(a[i]=='-'){
                if(flag==1)numn-=num;
                if(flag==0)numn+=num;
                num=0;
                flag=1;
            }
            else if(a[i]=='+'){
                if(flag==1)numn-=num;
                if(flag==0)numn+=num;
                num=0;
                flag=0;
            }
            else {
                x=a[i];
                if(flag==1)numx+=num;
                if(flag==0)numx-=num;
                num=0;
            }
        }
    }
    if(flag==1)numn-=num;
    if(flag==0)numn+=num;
    cout<<setprecision(3)<<fixed;
    cout<<x<<"="<<(double)numn/numx<<endl;
    return 0;
}
