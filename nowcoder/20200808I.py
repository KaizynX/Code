'''
Author: Kaizyn
Date: 2020-08-08 12:16:13
LastEditTime: 2020-08-08 12:22:47
'''
if __name__ == "__main__":
  T = int(input())
  for t in range(T) :
    n = int(input())
    cnt = [0 for i in range(10)]
    x = 0
    y = 0
    a = list(map(int, input().split()))
    # print(a)
    for i in a:
      cnt[i] += 1
    for i in range(1, 10) :
      if cnt[i] :
        x = i
        cnt[i] -= 1
        break
    for i in range(1, 10) :
      if cnt[i] :
        y = i
        cnt[i] -= 1
        break
    for i in range(10) :
      while cnt[i] :
        y = y*10+i
        cnt[i] -= 1
    print(x*y)
