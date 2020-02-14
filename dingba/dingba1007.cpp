#include <bits/stdc++.h>

using namespace std;

int T, n;
double p;
string name;

int main()
{
    while (cin >> T) {
        int sum = 0;
        for (int i = 1; i <= T; ++i) {
            cin >> name >> n >> p;
            //printf("%.12lf\n", n*p);
            int tmp = (int)(n*p*100);
            //cout << tmp << endl;
            tmp += 10*(tmp%10 >= 5)-tmp%10;
            //cout << tmp << endl;
            sum += tmp;
        }
        printf("%.1f\n", sum/100.0);
    }
    return 0;
}
