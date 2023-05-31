n=int(input())
for i in range(n,0,-1):
    for q in range(0,i-1):
        print(" ", end='')
    for f in range(0,n):
        print("*",end='')
    print()
    
