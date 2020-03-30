'''
@Author: Kaizyn
@Date: 2020-03-03 20:27:32
@LastEditTime: 2020-03-27 11:04:17
'''
# coding = utf-8

import math

m1 = float(input('输入m1:'))
m2 = float(input('输入m2:'))
x = float(input('输入x:'))
n = int(input('输入测量次数:'))
t10 = [float(i) for i in input('输入%d组t10(空格分隔):' % (n)).split()]
t2 = [float(i) for i in input('输入%d组t2(空格分隔):' % (n)).split()]

v10 = [x/t for t in t10]
v2 = [x/t for t in t2]
m1v10 = [m1*v for v in v10]
m2v2 = [m2*v for v in v2]
e = [(v2[i]-0)/(v10[i]-0) for i in range(n)]
R = [(m1+m2*pow(ee, 2))/(m1+m2) for ee in e]
E = [100*abs(m2v2[i]-m1v10[i])/m1v10[i] for i in range(n)]

print('v10: ', v10)
print('v2: ', v2)
print('m1v10: ', m1v10)
print('m2v2: ', m2v2)
print('e: ', e)
print('R: ', R)
print('E%: ', E)