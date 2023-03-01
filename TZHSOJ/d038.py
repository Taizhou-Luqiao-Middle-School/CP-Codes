n=int(input())
for i in range(0,n):
    out = ""
    for j in range (0,2*(n-i)-1):
        out = out + '*'
    for j in range (0,2*(i+1)-1 ):
        out = out + '$'
    print(out)
