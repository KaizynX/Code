#include <bits/stdc++.h>

using namespace std;

const int kN = 1e2+7;

int T;
char s[kN];

int main()
{
    scanf("%d", &T);
    while (T--){
        scanf("%s", s);
        if (s[0] != 'z') {
            printf("%s\n", s);
        } else {
            s[0] = 'b';
            printf("%s\n", s);
        }
    }
    return 0;
}
