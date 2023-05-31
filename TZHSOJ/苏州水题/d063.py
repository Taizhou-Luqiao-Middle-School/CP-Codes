def reserve(n):
    a = int(n/10)
    b = n%10
    return b*10+a

n = int(input())
m = reserve(n)

b = 0

for i in range(11,100,1):
    if (i%10==0):
        continue
    if (n+i)==(m+reserve(i)) and m!=i:
        print(i)
        b=1
if b==0:
    print("No")