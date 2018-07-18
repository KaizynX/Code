#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

const int Maxn = 1e3 + 7;

int n, begin_level, max_level;
bitset<Maxn> b, cut;

// b�д洢����i�Ƿ��ܴﵽ
// ������ĳ�׸質��ʱ b[i] == 1 ==> �ܴﵽ����i 
//                    b[i] == 0 ==> ���ܴﵽ����i

int main()
{
	scanf("%d%d%d", &n, &begin_level, &max_level);
	// ��ʼʱ������
	b[begin_level] = 1;
	// ����cutΪ[0, max_level] = 1������Ϊ0�Ķ���
	for(int i = 0; i <= max_level; ++i) cut[i] = 1;
	// tmp Ϊ��ǰ��������ı�ֵ
	for(int i = 0, tmp; i < n; ++i)
	{
		scanf("%d", &tmp);
		// ����������������tmp����λ,���ƾ�������tmp����λ
		// ��λ��| ֮��, b�ͱ�������ƺ�����һ�����Դﵽ��ֵ
		b = (b << tmp) | (b >> tmp);
		// ��ֵ < 0 ʱbitset���Զ����
		// ����ֵ > max_levelʱ������Ҫ�ֶ�ȥ��
		b &= cut;
	}
	// �����[0, max_level]���Ҳ�������Ϊ��Ŀ���������޷��������
	if(b.none()) printf("-1\n");
	// �������ܴﵽ�����ֵ
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
