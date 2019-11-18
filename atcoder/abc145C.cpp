#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int n, tot = 1;
int x[N], y[N], p[N];
double sum;

inline double dis(int i, int j) {
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", x+i, y+i);
        p[i] = i;
        tot *= (i+1);
    }
    do {
        for (int i = 1; i < n; ++i)
            sum += dis(p[i-1], p[i]);
    } while (next_permutation(p, p+n));
    printf("%10lf\n", sum/tot);
    return 0;
}

