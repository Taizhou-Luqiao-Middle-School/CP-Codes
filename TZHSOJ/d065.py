a,b,c=input().split()
a=int(a)
b=int(b)
c=int(c)
n = 0
p=1
while n<10:
    if (p%a==1) and (p%b==1) and (p%c==1):
        print(p)
        n+=1
    p+=1