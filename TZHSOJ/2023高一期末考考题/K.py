import math

n = int(input().strip())

for i in range(2, n+1):
    sum_of_factors = 1
    for j in range(2, int(math.sqrt(i))+1):
        if i % j == 0:
            sum_of_factors += j
            if j != i // j:
                sum_of_factors += i // j
    if sum_of_factors == i:
        print(i)
