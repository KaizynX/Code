#include <cstdio>
#include <iostream>

using namespace std;

int x1, x2, x3, x4, y1, y2, y3, y4;

int main()
{
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int a = x1-x2, b = y1-y2;
    x3 = x2+b; y3 = y2-a;
    x4 = x1+b; y4 = y1-a;
    printf("%d %d %d %d\n", x3, y3, x4, y4);
    return 0;
}
