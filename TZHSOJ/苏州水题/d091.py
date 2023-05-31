def jc(a):
    if a==1:
        return 1
    elif a==0:
        return 1
    else:
        return a*jc(a-1)
a,b,c=input().split()
a=int(a)
b=int(b)
c=int(c)
ans=jc(a)+jc(b)+jc(c)
print(ans)
 
