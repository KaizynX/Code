#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int a[3];

int main()
{
    for(int i = 0; i < 3; ++i)
        scanf("%d", a+i);
    sort(a, a+3);
    printf("%d\n", a[2]*10+a[0]+a[1]);
    return 0;
}
