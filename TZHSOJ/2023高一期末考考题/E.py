l=input().split()
a,b=int(l[0]),int(l[1])
c=l[2]
if(c=='+'):
    print(int(a+b))
elif(c=='-'):
    print(int(a-b))
elif(c=='*'):
    print(a*b)
elif(c=='//' and b):
    print(int(a//b))
elif(c=='%' and b):
    print(a%b)
else :
print("Error")



