import math

n = int(input().strip())

def is_prime(x):
    if x < 2:
        return False
    for i in range(2, int(math.sqrt(x))+1):#如果你内存超限了，应该是这一行没有做好优化
        #枚举因数的时候只要枚举到 根号x 就可以了
        #用 int(x**0.5)+1 表示也可
        if x % i == 0:
            return False
    return True

count = 0
for i in range(2, n+1):
    if is_prime(i):
        count += 1

print(count)

