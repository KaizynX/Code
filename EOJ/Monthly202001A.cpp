#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 20;
const int b[] = {0,9,5,9,5,1,2,3};
const int d[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int k;
int a[] = {0,2,0,2,0,0,1,2,2,1,0,0,2,0,2};

inline bool check()
{
    int year = a[1]*1000+a[2]*100+a[3]*10+a[4];
    int month = a[5]*10+a[6];
    int day = a[7]*10+a[8];
    int h = a[9]*10+a[10];
    int m = a[11]*10+a[12];
    int s = a[13]*10+a[14];
    if (month > 12 || month < 1 || day < 1 || h >= 23 || m >= 60 || s >= 60) return false;
    if (month == 2) {
        int tmp = (year%4 == 0 && (year%100 || year%400 == 0)) ? 29 : 28;
        if (day > tmp) return false;
    } else {
        if (day > d[month]) return false;
    }
    return true;
}

inline void print()
{
    for (int i = 1; i <= 14; ++i)
        cout << a[i];
    cout << endl;
}

int main()
{
    cin >> k;
    for (int i = 0; i < k; ++i) {
        while (true) {
            ++a[7];
            int cur = 7;
            while (cur && a[cur] > b[cur]) {
                ++a[cur-1];
                for (int j = cur; j <= 7; ++j) a[cur] = 0;
                --cur;
            }
            for (int j = 8; j <= 14; ++j) a[j] = a[15-j];
#ifdef DEBUG
            print();
#endif
            if (check()) break;
        }
#ifdef DEBUG
        puts("***");
#endif
    }
    print();
    return 0;
}
