#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 2e5+7;

int n, k, cnt, add;
long long ans;
long long s[2][Maxn];

int main()
{
    scanf("%d%d", &n, &k);
    if(k == 1)
    {
        printf("%lld\n", 1ll*n*n*n);
        return 0;
    }
    add = k&1 ? k : k/2;
    for(int i = add, cnt = 1; i <= n; i += add, ++cnt)
    {
        // i i i
        ans++;
        // i i j && i j j
        ans += (i/k-(i%k == 0))*3*2;
        s[0][cnt] = s[0][cnt-1];
        s[1][cnt] = s[1][cnt-1];
        s[i%k == 0][cnt] += i/k-(i%k == 0);
        // i j j2
        ans += s[i%k == 0][cnt-1]*6;
        /*
        for(int j = i; j > 0; j -= k)
        {
            for(int j2 = j; j2 > 0; j2 -= k)
            {
                if(i == j && j == j2) ans++;
                else if(i == j || j == j2 || i == j2) ans += 3;
                else ans += 6;
                printf("%d %d %d %lld\n", i, j, j2, ans);
            }
        }
        */
    }
    printf("%lld\n", ans);
    return 0;
}
