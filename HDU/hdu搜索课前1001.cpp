#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int Maxn = 1e6+5;//�����
int n;
int f_lower[Maxn],f_upper[Maxn];
//dp ��i����Ϊ��д(Сд) ����λ�����Ķ���
bool is_aeiou[Maxn];
string S;

int main()
{
	cin>>n;
	for(int i=0;i<n;++i)
	{
		//����
		memset(f_lower,0,sizeof f_lower);
		memset(f_upper,0,sizeof f_upper);
		memset(is_aeiou,0,sizeof is_aeiou);

		cin>>S;
		//�� ��һ����ĸƥ��ǰһ����ĸ����,�ʴ�λ��1��ʼ
		for(unsigned int pos=1;pos<S.length();++pos)
		{
			//pos+1��ֹ�½����
			switch(S[pos])
			{
				case'a':case'e':case'i':case'o':case'u':case'w':case'y':
					is_aeiou[pos+1]=true;//����޷�ʹ��
					f_lower[pos+1]=f_lower[pos];
					f_upper[pos+1]=f_upper[pos];
					break;
				default:
				//�����һ������Ԫ���п�������
				f_lower[pos+1]=( is_aeiou[pos] ? f_lower[pos] : f_upper[pos]+1 );
				f_upper[pos+1]=( is_aeiou[pos] ? f_upper[pos] : f_lower[pos]+1 );
			}
		}
		//���һ����(S.length()-1)+1
		cout<<max(f_upper[S.length()],f_lower[S.length()])<<endl;
	}
	return 0;
}
