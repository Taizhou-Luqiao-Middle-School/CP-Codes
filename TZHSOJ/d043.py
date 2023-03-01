n = int(input())
s=1
for k in range(0,1000):
    if n<s:
        print (k-1)
        break
    s*=3