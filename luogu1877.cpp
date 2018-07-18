#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

const int Maxn = 1e3 + 7;

int n, begin_level, max_level;
bitset<Maxn> b, cut;

// b中存储音量i是否能达到
// 即：当某首歌唱完时 b[i] == 1 ==> 能达到音量i 
//                    b[i] == 0 ==> 不能达到音量i

int main()
{
	scanf("%d%d%d", &n, &begin_level, &max_level);
	// 开始时的音量
	b[begin_level] = 1;
	// 设置cut为[0, max_level] = 1，其余为0的东东
	for(int i = 0; i <= max_level; ++i) cut[i] = 1;
	// tmp 为当前歌的音量改变值
	for(int i = 0, tmp; i < n; ++i)
	{
		scanf("%d", &tmp);
		// 左移是音量降低了tmp个单位,右移就是升高tmp个单位
		// 按位或| 之后, b就变成了左移和右移一共可以达到的值
		b = (b << tmp) | (b >> tmp);
		// 当值 < 0 时bitset会自动溢出
		// 而当值 > max_level时，就需要手动去掉
		b &= cut;
	}
	// 如果在[0, max_level]中找不到，则为题目中描述的无法避免情况
	if(b.none()) printf("-1\n");
	// 倒着找能达到的最大值
	for(int i = max_level; i; --i)
	{
		if(b[i])
		{
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}
