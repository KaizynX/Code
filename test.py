'''
@Author: Kaizyn
@Date: 2020-03-03 20:27:32
@LastEditTime: 2020-04-30 21:02:58
'''
# coding = utf-8

if __name__ == "__main__" :
    for E in ('骑士', '无赖') :
        for F in ('骑士', '无赖') :
            # 据分析,E说的话等价于我是无赖"
            if (F == '骑士' and E == '无赖') or (F != '骑士') :
                print('E{}F{}'.format(E, F))