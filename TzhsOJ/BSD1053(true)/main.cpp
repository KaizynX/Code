#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Kruskal
{
    int x;
    int y;
    double value;
};

int father[100002], son[100002];

bool cmp(const Kruskal &a, const Kruskal& b)
{
    return a.value < b.value;
}

int unionsearch(int x)
{
    if (x == father[x])
        return x;
    else
        return unionsearch(father[x]); //有改进余地
}

bool join(int x, int y)
{
    int root1 = unionsearch(x);
    int root2 = unionsearch(y);
    if (root1 == root2)
        return false;
    if (son[root1] >= son[root2])
    {
        father[root2] = root1;
        son[root1] +=son[root2];
    }
    else
    {
        father[root1] = root2;
        son[root2] += son[root1];
    }
    return true;
}

int main()
{

    double total = 0;
    double sum = 0;
    int n, m, flag = 0, num = 0;
    Kruskal edge[100002];
    scanf("%lf", &total);
    scanf("%d", &n);
    m = 1;
    while(3 == scanf("%d%d%lf", &edge[m].x, &edge[m].y, &edge[m].value))
        m++;
    m--;
    for(int i = 1; i <= n; i++)
    {
        father[i] = i;
        son[i] = 1;
    }
    sort(edge+1, edge+m+1, cmp);
    for (int i = 1; i <= m; i++)
    {
        if(join(edge[i].x, edge[i].y))
        {
            num++;  //edge number
            sum += edge[i].value;
        }
        if(num == n-1)
        {
            flag = 1;
            break;
        }
    }
    if (sum > total)
        flag = 0;
    if (flag)
        printf("Need %.2lf miles of cable\n", sum);
    else
        printf("Impossible\n");

    return 0;
}
