#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

int T, w, h;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &w, &h);
        if (w > h) swap(w, h);
        double res = 0.25*h*h*PI-(h*w-0.25*w*w*PI);
        printf("%.2f\n", res);
    }
    return 0;
}
