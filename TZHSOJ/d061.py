n=int(input())
a=int((n*(n-1))/2+1)
print(a)
for i in range(2,n+1,1):
    a=a-(n-i+1)
    print(a,end=" ")
    b=a
    for j in range(2,i+1,1):
        b=b+(n-i+j)
        print(b,end=" ")
    print(" ")
