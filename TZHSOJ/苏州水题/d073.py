import sys
a=[]
for line in sys.stdin.readlines():
    a=a+list(map(int,line.split()))
a.reverse()
for i in range(len(a)):
    if (i+1)%10==0:
        print("%d"%a[i])
    else:
        print("%d"%a[i],end=" ")
