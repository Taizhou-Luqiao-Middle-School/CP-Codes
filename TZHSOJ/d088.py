i,j=input().split()
i=int(i)
j=int(j)
t=0
a=[[]for i0 in range(max(i,j)+3)]
for i1 in range(1,i+1):
        b=list(map(int,input().split()))
        a[i1]=b
        
for i1 in range(1,i+1):
    for j1 in range(0,j):
        if a[i1][j1]:
            t+=1

print (t)
for i1 in range(1,i+1):
    for j1 in range(0,j):
        if a[i1][j1]:
            print(i1,j1+1,a[i1][j1])