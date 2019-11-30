#include <math.h>
#include <stdio.h>
#include <string.h>

const int N = 1e2+7;

int main()
{
    int a = 1;
    int *b = a, *c = a;
    b+c;
    b < c;
    return 0;
}
