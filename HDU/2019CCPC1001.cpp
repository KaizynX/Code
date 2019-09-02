#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int cases;
    scanf("%lld",&cases);
    while(cases--){
    long long a,b;
    scanf("%lld%lld",&a,&b);
    long long c=a&b;
    printf("%lld\n",c);    
    }
    return 0;
}
/*
#include <bits/stdc++.h>

using namespace std;

int T;
long long a, b, res;

int main()
{
    scanf("%d", &T);
    while (T--) {
        res = 0;
        scanf("%lld%lld", &a, &b);
        for (int i = 0; i < 32; ++i) {
            long long bit = 1ll<<i;
            // 这个位不同
            if ((a&bit)^(b&bit)) continue;
            // 都是1
            else if ((a&bit) && (b&bit)) continue;
            // 都是0
            else if ((a&bit) && (b&bit)) res += bit;
        }
        printf("%lld\n", res);
    }
    return 0;
}
*/
