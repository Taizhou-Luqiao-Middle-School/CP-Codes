#离谱压行 + 内置函数
import re

num_cases = int(input().strip())
for i in range(num_cases):
    password = input().strip()
    if re.match(r'(?=.*[A-Z])(?=.*[a-z])(?=.*\d|.*[!@#$%^&*()~-]).{8,16}$', password):
        # 补充： re.match  https://blog.csdn.net/qq_33210042/article/details/116794784
        # 括号内的是要找的字符
        # 但是压行压成这p样我也不是很清楚其中的原理了
        print('YES')
    else:
        print('NO')



