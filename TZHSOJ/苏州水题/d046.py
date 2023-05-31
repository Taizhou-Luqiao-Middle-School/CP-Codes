x=int(input())
s=0
for n in range(1,1000):
    s+=n*n
    if s>x:
        print(n-1)
        break