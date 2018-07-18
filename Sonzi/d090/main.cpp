#include <iostream>
#include <string>
#define Maxn 10 //10µÄ100´Î·½
using namespace std;
int a[Maxn]={0},b[Maxn]={0};
int main()
{
    string s1,s2;
    cin>>s1,s2;
    int len1=s1.length();
    for(int i=1;i<=len1;++i){
        a[len1-i]=s1[i-1]-'0';
    }
    int len1=s2.length();
    for(int i=1;i<=len2;++i){
        a[len2-i]=s2[i-1]-'0';
    }
    int len0=len1;
    if(len0<len2){len0=len2;}
    for(int i=1;i<=len0;++i){
        a[i]+=b[i];
        a[i+1]+=a[i]%10;
        a[i]-=a[i]%10;
    }
    for(int i=1;i<=len0;++i){
        cout<<a[i];
    }
    return 0;
}
