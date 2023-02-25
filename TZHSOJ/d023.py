a=int(input())
n=0
while a!=0:
    n = n + a%10
    a = int(a/10)
print (n)