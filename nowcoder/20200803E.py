'''
@Author: Kaizyn
@Date: 2020-08-03 13:30:57
@LastEditTime: 2020-08-03 14:43:41
'''
if __name__ == "__main__":
  n = int(input())
  dp = [[0 for i in range(n+1)] for j in range(2)]
  f = [0 for i in range(n+1)]
  sum = [0 for i in range(n+1)]
  dp[3&1][6] = 1
  f[6] = 1
  for i in range(4, n+1):
    for j in range(6, n+1):
      dp[i&1][j] = dp[~i&1][j-1]+dp[~i&1][j-2]+dp[~i&1][j-3]
      for k in range(0, n):
        if j+i*k > n : break
        f[j+i*k] += dp[i&1][j]
  for i in range(1, n+1):
    sum[i] = sum[i-1]+f[i]
    # print("f[{}]={}".format(i, f[i]))
    # print("sum[{}]={}".format(i, sum[i]))
  print(f[n])