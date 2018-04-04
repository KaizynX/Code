#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn = 350+5;
//const int Maxm = 120+5;//������
const int Maxb = 40+5;//����������

int n,m;
int a[Maxn],b[5];
//a��¼�õ�ķ�ֵ,b��¼��Ƭ����
int f[Maxb][Maxb][Maxb][Maxb];

int main()
{
	//����
	scanf("%d%d",&n,&m);
	//��1~n,�ʵ�Ч��0~n-1
	for(int i=0;i<n;++i)
	{
		scanf("%d",a+i);
	}
	for(int i=0;i<m;++i)
	{
		int tmp;
		scanf("%d",&tmp);
		b[tmp]++;
	}

	//DP
	//����O(30^4)
	for(int b1=0;b1<=b[1];++b1)
	{
		for(int b2=0;b2<=b[2];++b2)
		{
			for(int b3=0;b3<=b[3];++b3)
			{
				for(int b4=0;b4<=b[4];++b4)
				{
					//Ѱ��֮ǰ�����ŷ���
					int &tmp=f[b1][b2][b3][b4];
					if(b1>=1)tmp=max(tmp,f[b1-1][b2][b3][b4]);
					if(b2>=1)tmp=max(tmp,f[b1][b2-1][b3][b4]);
					if(b3>=1)tmp=max(tmp,f[b1][b2][b3-1][b4]);
					if(b4>=1)tmp=max(tmp,f[b1][b2][b3][b4-1]);
					//������һ���ķ���
					tmp+=a[b1+b2*2+b3*3+b4*4];
					//debug
					//printf("%d %d %d %d %d\n",b1,b2,b3,b4,tmp);
				}
			}
		}
	}
	printf("%d",f[b[1]][b[2]][b[3]][b[4]]);
	return 0;
}
