#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;cin>>n;
    int a1,a2,a3;
    int sum=0;
    for(int i=1;i<=n;++i){
        a1=i%10;//��
        a2=(i%100)/10;//ʮ
        a3=i/100;//��
        if(i%3==0 || i%5==0 || a1==3 || a1==5 || a2==3 || a2==5 || a3==3 || a3==5)continue;
        else sum+=pow(i,2);
    }
    cout<<sum;
    return 0;
}
