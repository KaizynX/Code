#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int P1 = 12255871;
const int P2 = 16341163;
const int P3 = 19260817;
const int Maxn = 1e5+7;

int A, B, C;
bool hash_1[P1], hash_2[P2], hash_3[P3];
unsigned long long ai = 1;

int main()
{
    scanf("%d%d%d", &A, &B, &C);
    memset(hash_1, 0, sizeof hash_1);
    memset(hash_2, 0, sizeof hash_2);
    memset(hash_3, 0, sizeof hash_3);
    hash_1[1] = hash_2[1] = hash_3[1] = true;
    for(int i = 1; i <= 2e6; ++i)
    {
        ai = (A*ai+ai%B)%C;
        // printf("%d %lld\n", i, ai);
        if(hash_1[ai%P1] && hash_2[ai%P2] && hash_3[ai%P3])
        {
            printf("%d\n", i);
            break;
        }
        hash_1[ai%P1] = hash_2[ai%P2] = hash_3[ai%P3] = true;
    }
    return 0;
}
