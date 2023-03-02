n=int(input())
s = str(input())
a=0
b=0
c=0
for i in range(0,n):
    if s[i]=='a' or s[i]=='A':
        a+=1
    elif s[i]=='b' or s[i]=='B':
        b+=1
    elif s[i]=='c' or s[i]=='C':
        c+=1
    else :
        continue

if a>=b and a>=c:
    print("a",a)
    if b>=c :
        print("b",b)
        print("c",c)
    else :
        print("c",c)
        print("b",b)
elif b>a and b>=c:
    print("b",b)
    if a>=c:
        print("a",a)
        print("c",c)
    else :
        print("c",c)
        print("a",a)
else:
    print("c",c)
    if a>=b:
        print("a",a)
        print("b",b)
    else :
        print("b",b)
        print("a",a)

