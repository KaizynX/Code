/*
 * @Author: Kaizyn
 * @Date: 2020-03-20 11:40:55
 * @LastEditTime: 2020-03-20 11:41:00
 */
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int N = 10;

int n = 6;
double zero, yiqi;
double average = 0, ua = 0, ub = 0, ux, E;
double x[N];

int main()
{
    printf("输入测量次数:");
    scanf("%d", &n);
    printf("输入零点读数:");
    scanf("%lf", &zero);
    printf("输入仪器误差:");
    scanf("%lf", &yiqi);
    printf("输入测量值:");
    for (int i = 1; i <= n; ++i) scanf("%lf", x+i);
    for (int i = 1; i <= n; ++i) {
        average += x[i];
    }
    average /= n;
    for (int i = 1; i <= n; ++i) {
        ua += (x[i]-average)*(x[i]-average);
    }
    ua = sqrt(ua/n*(n-1));
    ub = yiqi/sqrt(3);
    ux = sqrt(ua*ua+ub*ub);
    E = ux/(average-zero);
    printf("平均值: %lf\n", average);
    printf("修正后平均值: %lf\n", average-zero);
    printf("A类不确定度UA: %lf\n", ua);
    printf("B类不确定度UB: %lf\n", ub);
    printf("合成不确定度U: %lf\n", ux);
    printf("结果表达式: %lf+-%lf\n", average-zero, ux);
    printf("相对不确定度E: %.1lf%%\n", E*100);
    return 0;
}

