n = int(input())
for i in range(n+1,1,-1):
    s=""
    d = i
    now = int( (i-2)*(i-1)/2 )+1
    for j in range(0,n+2-i,1):
        s = s + str(now) + ' '
        now += d
        d += 1
    print(s)