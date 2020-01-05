#include<stdio.h>
#include<string.h>
int main()
{
    int a = 1;
    switch(a) {
        case 1 : printf("1\n");
        case 2 : printf("2\n"); break;
        default : printf("3\n");
    }
    return 0;
}
