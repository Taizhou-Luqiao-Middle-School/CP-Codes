a,b,c=input().split()
a=int(a)
b=int(b)
c=int(c)
a%=b
p=0
ans=""
n=a
while(p<c):
    n%=b
    n*=10
    ans+=str(n//b)
    p+=1

print(ans)

