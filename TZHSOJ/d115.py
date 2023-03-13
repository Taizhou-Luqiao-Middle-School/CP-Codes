def small(n):
    r = 0
    
    num = []
    while (n!=0):
        num.append(n%10)
        n=int(n/10)
        
    new = []
    for i in range(0,4):
        p = 5
        min = 10
        for j in range(0,len(num)):
            if num[j]<min:
                p = j
                min = num[j]
        new.append( num.pop(p) )
        
    for i in new:
        r = r*10 + i
    return r

def large(n):
    r = 0
    
    num = []
    while (n!=0):
        num.append(n%10)
        n=int(n/10)
        
    new = []
    for i in range(0,4):
        p = 5
        min = 10
        for j in range(0,len(num)):
            if num[j]<min:
                p = j
                min = num[j]
        new.append( num.pop(p) )
    
    new.reverse()
    
    for i in new:
        r = r*10 + i
    return r

n = int(input())
i = 0
while n!=6174:
    l = large(n)
    s = small(n)
    n = l-s
    i+=1
print(i)