#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 30;

int N, Q;
int a[Maxn], b[Maxn];

inline bool ask(int x, int y)
{
    char res;
    printf("? %c %c\n", a[x], a[y]);
    fflush(stdout);
    scanf(" %c", &res);
    return res == '<' ? true : false;
}

void merge_sort(int l, int r)
{
    if(l >= r) return;
    int mid = (l+r)>>1;
    merge_sort(l, mid);
    merge_sort(mid+1, r);
    int i = l, j = mid+1, pos = l;
    while(i <= mid && j <= r)
    {
        if(ask(i, j)) // a[i] < a[j]
            b[pos++] = a[i++];
        else b[pos++] = a[j++];
    }
    while(i <= mid) b[pos++] = a[i++];
    while(j <= r) b[pos++] = a[j++];
    for(int i = l; i <= r; ++i)
        a[i] = b[i];
}

int main()
{
    scanf("%d%d", &N, &Q);
    for(int i = 1; i <= N; ++i)
        a[i] = 'A'+i-1;
    if(N == 5 && Q == 7)
    {
        if(ask(1, 2)) swap(a[1], a[2]);
        if(ask(3, 4)) swap(a[3], a[4]);
        if(ask(2, 4)) swap(a[1], a[3]), swap(a[2], a[4]);
        // 1 > 2 > 4, 3 > 4
        if(ask(2, 5)) // 2 < 5
        {
            if(ask(1, 5)) // 1 < 5
            {
                if(ask(1, 3)) // 1 < 3
                {
                    if(ask(3, 5)) // 3 < 5
                        printf("! %c%c%c%c%c\n", a[5], a[3], a[1], a[2], a[4]);
                    else          // 3 > 5
                        printf("! %c%c%c%c%c\n", a[3], a[5], a[1], a[2], a[4]);
                }
                else          // 1 > 3
                {
                    if(ask(2, 3)) // 2 < 3
                        printf("! %c%c%c%c%c\n", a[5], a[1], a[3], a[2], a[4]);
                    else          // 2 > 3
                        printf("! %c%c%c%c%c\n", a[5], a[1], a[2], a[3], a[4]);
                }
            }
            else          // 1 > 5
            {
                if(ask(3, 5)) // 3 < 5
                {
                    if(ask(3, 2)) // 3 < 2
                        printf("! %c%c%c%c%c\n", a[1], a[5], a[2], a[3], a[4]);
                    else          // 3 > 2
                        printf("! %c%c%c%c%c\n", a[1], a[5], a[3], a[2], a[4]);
                }
                else          // 3 > 5
                {
                    if(ask(1, 3)) // 1 < 3
                        printf("! %c%c%c%c%c\n", a[3], a[1], a[5], a[2], a[4]);
                    else          // 1 > 3
                        printf("! %c%c%c%c%c\n", a[1], a[3], a[5], a[2], a[4]);
                }
            }
        }
        else          // 2 > 5
        {
            if(ask(4, 5)) // 4 < 5
            { // 1 > 2 > 5 > 4, 3 > 4
                if(ask(2, 3)) // 2 < 3
                {
                    if(ask(3, 1)) // 3 < 1
                        printf("! %c%c%c%c%c\n", a[1], a[3], a[2], a[5], a[4]);
                    else          // 3 > 1
                        printf("! %c%c%c%c%c\n", a[3], a[1], a[2], a[5], a[4]);
                }
                else          // 2 > 3
                {
                    if(ask(5, 3)) // 5 < 3
                        printf("! %c%c%c%c%c\n", a[1], a[2], a[3], a[5], a[4]);
                    else          // 5 > 3
                        printf("! %c%c%c%c%c\n", a[1], a[2], a[5], a[3], a[4]);
                }
            }
            else          // 4 > 5
            { // 1 > 2 > 4 > 5, 3 > 4
                if(ask(3, 1)) // 3 < 1
                {
                    if(ask(3, 2)) // 3 < 2
                        printf("! %c%c%c%c%c\n", a[1], a[2], a[3], a[4], a[5]);
                    else          // 3 > 2
                        printf("! %c%c%c%c%c\n", a[1], a[3], a[2], a[4], a[5]);
                }
                else          // 3 > 1
                {
                    printf("! %c%c%c%c%c\n", a[3], a[1], a[2], a[4], a[5]);
                }
            }
        }
        return 0;
    }
    else merge_sort(1, N);
    printf("! ");
    for(int i = 1; i <= N; ++i)
        printf("%c", a[i]);
    putchar('\n');
    return 0;
}
