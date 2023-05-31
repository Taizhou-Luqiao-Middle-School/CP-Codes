n = int(input())
s = ''
k = 1
for i in range(1,n+1):
    s=""
    for j in range (k,k+i):
        s = s + str(j) + ' '
    print(s)
    k = k+i