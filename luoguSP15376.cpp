#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> v;

inline void clear(vector<int> &); // 清空vector
inline int getint(); // 快读

int main()
{
	int n, mid;
	while(true)
	{
		n = getint();
		if(n == 0) // 一组数据读完了，清空vector换个行
		{
			clear(v);
			putchar('\n');
		}
		else if(n == -1) // 查询中位数
		{
			mid = (v.size()+1)/2; // +1是针对奇数，偶数不影响。偶数/2之后即为较小的那个
			cout << v[mid-1] << endl; // -1是应为vector里是从v[0]开始存的
			v.erase(v.begin()+mid-1); // 删除v[mid-1]
		}
		else // 因为数据不递减，插到最后即可
		{
			v.push_back(n);
		}
	}
	return 0;
}

inline void clear(vector<int> &a)
{
	vector<int> tmp;
	swap(tmp,a);
}

inline int getint()
{
	char c;
	bool tag = false;
	while( (c = getchar()) < '0' || c > '9') 
		if(c == '-') tag = true; 
		else if(c == EOF) exit(0); // 文件以EOF结尾
	int res = c - '0';
	while( (c = getchar()) >= '0' && c <= '9') res = res * 10 + c - '0';
	return tag == true ? -res : res;
}
