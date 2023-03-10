a=int(input())

def rn(t,p):
    if t==a:
        for i in range(1,a+1):
            if not(i in p):
                p2=p+[i]
                for i2 in range(0,a):
                    print(p2[i2],end=" ")
                print("")
    else :
        for i in range (1,a+1):
            if not(i in p):
                p2=p+[i]
                rn(t+1,p2)
                
                
b=[]
rn(1,b)