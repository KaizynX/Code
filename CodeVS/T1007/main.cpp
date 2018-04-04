#include <iostream>

using namespace std;
//Sn= 1＋1／2＋1／3＋…＋1／n。显然对于任意一个整数K，当n足够大的时候，Sn大于K。
//　　现给出一个整数K（1<=k<=15），要求计算出一个最小的n；使得Sn＞K。
int main()
{
    int k,n=1;
    cin>>k;
    double sn=0;
    while(sn<=k){
        sn+=1.0/n;
        ++n;
    }
    cout<<n-1;
    return 0;
}
