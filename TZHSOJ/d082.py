a,c=input().split()
a=int(a)
c=int(c)

def rn(t,n,p):
    if t==c:
        for i in range(n+1,a+1):
                p2=p+[i]
                for i2 in range(0,c):
                    print(p2[i2],end=" ")
                print("")
    else :
        for i in range (n+1,a+1):
            p2=p+[i]
            rn(t+1,i,p2)
                
                
b=[]
rn(1,0,b)