#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+7;

int T, n;

inline int check(int x)
{
    if (x == 1) return 18;
    int res = 2*x+3+2*x+1;
    res += (2*x+3+4)*x;
    res += (x+1)*2+1;
    return res;
}

inline void print(int x)
{
    if (x == 1) {
        puts("  *");
        puts(" * *");
        puts("*****");
        puts("  *");
        puts(" * *");
        puts("*****");
        puts("  *");
        puts("  *");
        return;
    }
    for (int i = 0; i <= x; ++i) putchar(' ');
    putchar('*'); putchar('\n');
    for (int i = x; i; --i) {
        for (int j = 1; j <= i; ++j) putchar(' ');
        putchar('*');
        for (int j = 1; j <= (x+1-i)*2-1; ++j) putchar(' ');
        putchar('*'); putchar('\n');
    }
    for (int i = 1; i <= 2*x+3; ++i) putchar('*');
    putchar('\n');
    for (int t = 1; t <= x; ++t) {
        printf("  *");
        for (int i = 1; i <= (x-1)*2-1; ++i) putchar(' ');
        putchar('*'); putchar('\n');
        printf(" *");
        for (int i = 1; i <= x*2-1; ++i) putchar(' ');
        putchar('*'); putchar('\n');
        for (int i = 1; i <= 2*x+3; ++i) putchar('*');
        putchar('\n');
    }
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= x; ++j) putchar(' ');
        printf("* *\n");
    }
    for (int i = 1; i <= x; ++i) putchar(' ');
    printf("***\n");
}

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        int l = 1, r = 100;
        while (l < r) {
            int mid = (l+r+1)>>1;
            if (check(mid) > n) r = mid-1;
            else l = mid;
        }
        cout << check(l) << endl;
        print(l);
    }
    return 0;
}
