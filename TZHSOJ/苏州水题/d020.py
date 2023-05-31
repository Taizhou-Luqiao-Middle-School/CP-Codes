a=int(input())
s=0
for i in range(1,a+1,1):
    if a%i==0:
        s = s+i
print(s)