
def hannoi(f,b,t,n,i):
    f = str(f)
    b = str(b)
    t = str(t)
    n = int(n)
    i = int(i)
    if n==1:
        print( str( str(i) +':' + str(f) + '->' + str(t) ) )
        i+=1
        return
    else:
        hannoi(f,t,b,n-1,i-1)
        hannoi(f,b,t,1,i)
        hannoi(b,f,t,n-1,i-1)

n = int(input())
hannoi('A','B','C',n,n)