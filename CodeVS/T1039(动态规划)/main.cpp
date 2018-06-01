#include <iostream>
//http://blog.csdn.net/athenaer/article/details/8265234
/*
��һ��: n ���в����� 1 �ķַ���Ϊ��֤ÿ�ݶ� >= 2���������ó� k �� 1 ��
   ������ÿһ�ݣ�Ȼ���ٰ�ʣ�µ� n- k �ֳ� k �ݼ��ɣ��ַ���: dp[n-k][k]
�ڶ���: n ����������һ��Ϊ 1 �ķַ����������ǳ�һ�� 1 ��Ϊ������1�ݣ�ʣ
   �����µ� n- 1 �ٷֳ� k- 1 �ݼ��ɣ��ַ��У�dp[n-1][k-1]
*/
using namespace std;
int dp[205][205];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(i==j)dp[i][j]=1;
            else dp[i][j]=dp[i-1][j-1]+dp[i-j][j];
        }
    }
    cout<<dp[n][k]<<endl;
    return 0;
}
