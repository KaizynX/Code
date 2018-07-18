#include <iostream>

using namespace std;
//想不出怎么比较32  321这类数字
int a_first,b_first;
int compare(int a,int b){
    int a1=a,b1=b,a2=1,b2=1,a3=0,b3=0;
    while(a1!=0){
        a3=a1;
        a1/=10;
        a2*=10;
    }
    while(b1!=0){
        b3=b1;
        b1/=10;
        b2*=10;
    }
    if(a3>b3)return 1;
    else if(a3<b3)return 0;
    else if(a3=b3){
        if(a<10)a=a_first;//返回初值
        else a%=(a2/10);
        if(b<10)b=b_first;
        else b%=(b2/10);
        compare(a,b);
    }
}

int main()
{
    int n;cin>>n;
    int a[21]={0};
    for(int i=1;i<=n;++i)cin>>a[i];
    int big=1,com;
    for(int i=1;i<=n;++i){
        for(int j=2;j<=n;++j){
            a_first=a[j];b_first=a[big];
            com=compare(a[j],a[big]);
            if(com)big=j;
        }
        cout<<a[big];
        a[big]=0;
        big=1;
    }
    return 0;
}
