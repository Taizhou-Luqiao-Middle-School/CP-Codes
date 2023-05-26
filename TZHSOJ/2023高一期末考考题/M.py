import math

n = int(input().strip())

def is_prime(x):
    if x < 2:
        return False
    for i in range(2, int(math.sqrt(x))+1):
        if x % i == 0:
            return False
    return True

count = 0
for i in range(2, n+1):
    if is_prime(i):
        count += 1

print(count)

