#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int Maxn = 1e6+5;//最长长度
int n;
int f_lower[Maxn],f_upper[Maxn];
//dp 第i个作为大写(小写) 到此位置最大的对数
bool is_aeiou[Maxn];
string S;

int main()
{
	cin>>n;
	for(int i=0;i<n;++i)
	{
		//重置
		memset(f_lower,0,sizeof f_lower);
		memset(f_upper,0,sizeof f_upper);
		memset(is_aeiou,0,sizeof is_aeiou);

		cin>>S;
		//以 后一个字母匹配前一个字母来找,故从位置1开始
		for(unsigned int pos=1;pos<S.length();++pos)
		{
			//pos+1防止下界溢出
			switch(S[pos])
			{
				case'a':case'e':case'i':case'o':case'u':case'w':case'y':
					is_aeiou[pos+1]=true;//标记无法使用
					f_lower[pos+1]=f_lower[pos];
					f_upper[pos+1]=f_upper[pos];
					break;
				default:
				//如果上一个不是元音尚可以增加
				f_lower[pos+1]=( is_aeiou[pos] ? f_lower[pos] : f_upper[pos]+1 );
				f_upper[pos+1]=( is_aeiou[pos] ? f_upper[pos] : f_lower[pos]+1 );
			}
		}
		//最后一个是(S.length()-1)+1
		cout<<max(f_upper[S.length()],f_lower[S.length()])<<endl;
	}
	return 0;
}
