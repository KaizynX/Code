#include <bits/stdc++.h>

using namespace std;

#define N 2000

char s[N];

int check()
{
    int res, len = strlen(s), i = 0;
    for (; i < len; ++i) {
        if (s[i] < '0' || s[i] > '9') return 0;
    }
    sscanf(s, "%d", &res);
    if (res < 1 || res > 1000) return 0;
    return res;
}

void print(int x)
{
    if (!x) putchar('?');
    else printf("%d", x);
}

int main()
{
    int a, b;
    scanf("%s", s);
    a = check();
    // scanf("%s", s);
    getchar();
    cin.getline(s, sizeof s);
    b = check();
    print(a);
    printf(" + ");
    print(b);
    printf(" = ");
    if (!a || !b) printf("?\n");
    else printf("%d\n", a+b);
    return 0;
}
