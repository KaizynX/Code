#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 3e5+7;

int n, res, resi, resj, head;
int a[N];
char s[N];

int main()
{
    scanf("%d%s", &n, s);
    // get pre-sum
    a[0] = (s[0] == '(' ? 1 : -1);
    for (int i = 1; i < n; ++i) {
        a[i] = a[i-1]+(s[i] == '(' ? 1 : -1);
        if (a[i] < a[head]) head = i;
    }
    // cnt of '(' is not equal to cnt of ')'
    if (a[n-1] != 0) return printf("0\n1 1\n")&0;
    // s.t. a[i] >= 0
    for (int i = 0, add = -a[head]; i < n; ++i)
        a[i] += add;
    head = (head+1)%n;

    // 1 --> -1 count -1
    int cnt0 = 0;
    for (int i = 0, cnt = 0, last; i < n; ++i) {
        if (a[(head+i)%n] == 0) {
            if (cnt > res) {
                res = cnt;
                resi = last;
                resj = (head+i)%n;
            }
            last = (head+i+1)%n;
            cnt = 0;
            ++cnt0;
        } else if (a[(head+i)%n] == 1) {
            if (++cnt == 1) last = (head+i)%n;
        }
    }
#ifdef DEBUG
    printf("%d\n%d %d\n", res, resi+1, resj+1);
#endif
    if (cnt0 > res) {
        res = cnt0;
        resi = resj = 0;
    }
#ifdef DEBUG
    printf("%d\n%d %d\n", res, resi+1, resj+1);
#endif
    // 2 --> 0 count 0
    // a[head] == a[n-2] == 1
    for (int i = 0, cnt = 0, last; i < n; ++i) {
        if (a[(head+i)%n] == 1) {
            if (cnt+cnt0 > res) {
                res = cnt+cnt0;
                resi = last;
                resj = (head+i)%n;
            }
            cnt = 0;
        } else if (a[(head+i)%n] == 2) {
            if (++cnt == 1) last = (head+i)%n; 
        } // else if (a[(head+i)%n] == 0) last and next must be 1
    }
    printf("%d\n%d %d\n", res, resi+1, resj+1);
    return 0;
}
