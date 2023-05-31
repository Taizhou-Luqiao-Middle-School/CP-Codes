n = int(input())
s = ""
for i in range(0,n,1):
    s = ""
    for a in range(0,i):
        s = s + ' '
    for b in range(0,2*(n-i)-1):
        s = s + '#'
    print (s)