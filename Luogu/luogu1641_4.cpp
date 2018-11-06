#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e3+7;
const int MOD = 20100403; 

int n, m, ans;

void dfs(int i, int j)
{
    if(i == 0 && j == 0) ans++;
    int num1 = n-i, num2 = m-j;
    if(i > 0) dfs(i-1, j);
    if(j > 0 && num1 > num2) dfs(i, j-1);
}

int main()
{
    scanf("%d%d", &n, &m);
    dfs(n, m);
    printf("%d\n", ans);
    return 0;
}
