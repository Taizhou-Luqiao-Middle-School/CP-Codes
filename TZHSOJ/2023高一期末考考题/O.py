#离谱压行 + 内置函数
import re

num_cases = int(input().strip())
for i in range(num_cases):
    password = input().strip()
    if re.match(r'(?=.*[A-Z])(?=.*[a-z])(?=.*\d|.*[!@#$%^&*()~-]).{8,16}$', password):
        print('YES')
    else:
        print('NO')



