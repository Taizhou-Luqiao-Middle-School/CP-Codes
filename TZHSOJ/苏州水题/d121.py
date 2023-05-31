a,b,c=input().split()
a=int(a)
b=int(b)
c=int(c)

for i in range(1,10):
    for j in range(1,10):
        for n in range(1,10):
            if a*j==b*i and a*n==c*i and b*n==c*j:
                print(i,j,n)