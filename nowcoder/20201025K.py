'''
Author: Kaizyn
Date: 2020-10-25 11:54:55
LastEditTime: 2020-10-25 16:05:54
'''
import math
if __name__ == "__main__":
  A = int(input())
  B = int(input())
  n = int(input())
  MAX = '1'
  for i in range(10) :
    MAX += '0'
  MAX = int(MAX)
  C = MAX
  D = 0
  if A <= B :
    D = C-1
  else :
    if A*A < n*B*B :
      # A/B < C/D < sqrt(n)
      D = C*B//A-1
    else :
      # sqrt(n) < C/D < A/B
      D = C*B//A+1
  print(C)
  print(D)
  # print((B*C-A*D)*(C-D*math.sqrt(n)) < 0)