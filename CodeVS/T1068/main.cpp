#include <iostream>

using namespace std;
int f[41][41][41][41];
int main()
{
    int N,M,n[355],m,sum[5]={0};
    cin>>N>>M;
    for(int i=1;i<=N;i++)cin>>n[i];
    for(int i=1;i<=M;i++)
    {
        cin>>m;
        sum[m]++;
    }
    f[0][0][0][0]=n[1];
    for(int i1=0;i1<=sum[1];i1++)
        for(int i2=0;i2<=sum[2];i2++)
            for(int i3=0;i3<=sum[3];i3++)
                for(int i4=0;i4<=sum[4];i4++)
                {
                    int num=1+i1*1+i2*2+i3*3+i4*4;
                    if(i1)f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1-1][i2][i3][i4]+n[num]);
                    if(i2)f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1][i2-1][i3][i4]+n[num]);
                    if(i3)f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1][i2][i3-1][i4]+n[num]);
                    if(i4)f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1][i2][i3][i4-1]+n[num]);
                }
    cout<<f[sum[1]][sum[2]][sum[3]][sum[4]]<<endl;
    return 0;
}
