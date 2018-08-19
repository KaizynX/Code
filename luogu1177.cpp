#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int Maxn = 1e5+7;

int n, a[Maxn];

void quick_sort(int l, int r)
{
    if(l >= r) return;
    swap(a[l], a[l+rand()%(r-l)]);
    int i = l, j = r, mid = a[l];
    while(i < j)
    {
        while(i < j && a[j] >= mid) --j;
        swap(a[i], a[j]);
        while(i < j && a[i] < mid) ++i;
        swap(a[i], a[j]);
    }
    quick_sort(l, i-1);
    quick_sort(i+1, r);
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", a+i);
    quick_sort(1, n);
    for(int i = 1; i < n; ++i)
        printf("%d ", a[i]);
    printf("%d\n", a[n]);
    return 0;
}
