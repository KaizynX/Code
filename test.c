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
    printf("�����������:");
    scanf("%d", &n);
    printf("����������:");
    scanf("%lf", &zero);
    printf("�����������:");
    scanf("%lf", &yiqi);
    printf("�������ֵ:");
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
    printf("ƽ��ֵ: %lf\n", average);
    printf("������ƽ��ֵ: %lf\n", average-zero);
    printf("A�಻ȷ����UA: %lf\n", ua);
    printf("B�಻ȷ����UB: %lf\n", ub);
    printf("�ϳɲ�ȷ����U: %lf\n", ux);
    printf("������ʽ: %lf+-%lf\n", average-zero, ux);
    printf("��Բ�ȷ����E: %.1lf%%\n", E*100);
    return 0;
}

