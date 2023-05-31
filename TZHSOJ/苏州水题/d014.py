a,b,c = input().split()
a=int(a)
b=int(b)
c=int(c)
if (a+b<=c)or(a+c<=b)or(b+c<=a)or(a<=0)or(b<=0)or(c<=0):
    print("Error!")
elif (a*a+b*b==c*c)or(c*c+b*b==a*a)or(a*a+c*c==b*b):
    print("Yes!")
else :
    print("No!")