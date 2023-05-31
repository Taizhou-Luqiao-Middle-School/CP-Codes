a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=a+b
d=list(set(c))
for i in range(0,len(d)):
    print(d[i],end=" ")