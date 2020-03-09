'''
@Author: Kaizyn
@Date: 2020-03-03 20:27:32
@LastEditors: Kaizyn
@LastEditTime: 2020-03-06 18:31:35
@FilePath: \Code\test.py
'''
p = 0.5
cost = 1000
e = .0
while p*cost > 1e-3 :
    e += p*cost
    p *= 0.5
    cost += 2000
print(e)