#include <stdio.h>
#include <string.h>

#define N 100

const int w[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};

int main()
{
    int n, flag = 1;
    char s[20];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        int tmp = 0;
        char m;
        for (int j = 0; j < 17; ++j)
            tmp += w[j]*(s[j]-'0');
        tmp %= 11;
        if (tmp == 2) m = 'X';
        else m = (12-tmp)%11+'0';
        if (m != s[17]) puts(s), flag = 0;
    }
    if (flag) puts("All passed");
    return 0;
}

