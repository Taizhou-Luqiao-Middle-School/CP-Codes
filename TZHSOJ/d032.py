a=0
b=0
c=0
d=0
e=0
f=0
n = int(input())
for i in range(0,n):
    j = int(input())
    if j == 100:
        a+=1
    elif j>=90:
        b+=1
    elif j>=80:
        c+=1
    elif j>=70:
        d+=1
    elif j>=60:
        e+=1
    else :
        f+=1
print("%d"%a)
print("%d"%b)
print("%d"%c)
print("%d"%d)
print("%d"%e)
print("%d"%f)
