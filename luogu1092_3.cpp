#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
// #define DEBUG

using namespace std;

const int Maxn = 30;

int n;
char s[3][Maxn];
int a[3][Maxn];
int v[Maxn], p[Maxn];
bool used[Maxn];

// 检查前面某一列是否冲突
inline bool judge(int cur)
{
	int tmp1, tmp2, tmp3;
	for(int i = 0; i < cur; ++i)
	{
		tmp1 = v[a[0][i]];
		tmp2 = v[a[1][i]];
		tmp3 = v[a[2][i]];
        // 最高位 要进位
		if(i == 0 && tmp1+tmp2+p[1] >= n) return false;
		if(tmp1 == -1 || tmp2 == -1 || tmp3 == -1) continue;
        // 预留进位的空间
		if(!((tmp1+tmp2)%n == tmp3 || (tmp1+tmp2+1)%n == tmp3)) return false;
	}
	return true;
}

void dfs(int cur, int line)
{
	if(cur < 0)
	{
		for(int i = 0; i <= n-2; ++i) printf("%d ", v[i]);
		printf("%d\n", v[n-1]);
		exit(0);
	}
	
    int &tmp1 = v[a[line][cur]];
    // 求和项
    if(line == 2)
    {
        int tmp = v[a[0][cur]]+v[a[1][cur]]+p[cur+1];
        // 已经有值，判断是否一致
        if(tmp1 != -1)
        {
            if(tmp%n != tmp1) return;
            p[cur] = tmp/n;
            dfs(cur-1, 0);
            p[cur] = 0;
        }
        // 计算求出该值
        else if(!used[tmp%n])
        {
            p[cur] = tmp/n;
            tmp1 = tmp%n;
            used[tmp1] = true;
            if(judge(cur))
                dfs(cur-1, 0);
            p[cur] = 0;
            used[tmp1] = false;
            tmp1 = -1;
        }
    }
    // 加数项
    else
    {
        // 有值则直接继续
        if(tmp1 != -1)
            dfs(cur, line+1);
        else
        {
            int tmp2 = v[a[line^1][cur]],
                tmp3 = v[a[2][cur]];
            // 利用 和 & 另一个加数 求得其值
            if(tmp2 != -1 && tmp3 != -1)
            {
                int tmp = (tmp3-p[cur+1]-tmp2+n)%n;
                if(!used[tmp])
                {
                    tmp1 = tmp;
                    p[cur] = (tmp1+tmp2)/n;
                    used[tmp] = true;
                    if(judge(cur))
                        dfs(cur, line+1);
                    p[cur] = 0;
                    tmp1 = -1;
                    used[tmp] = false;
                }
            }
            // 否则枚举
            else
            {
                for(int i = 0; i < n; ++i)
                {
                    if(used[i]) continue;
                    used[i] = true;
                    tmp1 = i;
                    if(judge(cur))
                        dfs(cur, line+1);
                    used[i] = false;
                    tmp1 = -1;
                }
            }
        }
    }
}

int main()
{
	memset(v, -1, sizeof v);
	scanf("%d", &n);
	scanf("%s%s%s", s[0], s[1], s[2]);
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < n; ++j)
			a[i][j] = s[i][j] - 'A';
	dfs(n-1, 0);
	return 0;
}
