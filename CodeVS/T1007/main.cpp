#include <iostream>

using namespace std;
//Sn= 1��1��2��1��3������1��n����Ȼ��������һ������K����n�㹻���ʱ��Sn����K��
//�����ָ���һ������K��1<=k<=15����Ҫ������һ����С��n��ʹ��Sn��K��
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
