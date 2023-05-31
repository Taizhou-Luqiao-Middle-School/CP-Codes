a=2*int(input())
t=0
def next(n,p,l,pa):
    if n!=a:
        if (p>=1):
            if (p<a/2 and pa<a/2):
                l3=l+[0]
                next(n+1,p+1,l3,pa+1)
            l2=l+[1]
            next(n+1,p-1,l2,pa)
            
        else :
            next(n+1,p+1,l+[0],pa+1)
            
    else :
        l+=[1]
        for i in range(0,a):
            print(l[i],end=" ")
        print("")      
        
def n2(n,p,l,pa):
    if n!=a:
        if (p>=1):
            if (p<a/2 and pa<a/2):
                l3=l+[0]
                n2(n+1,p+1,l3,pa+1)
            l2=l+[1]
            n2(n+1,p-1,l2,pa)
            
        else :
            n2(n+1,p+1,l+[0],pa+1)
            
    else :
        global t
        l+=[1]
        t+=1       
            
n2(1,0,[],0)
print(t)
next(1,0,[],0)