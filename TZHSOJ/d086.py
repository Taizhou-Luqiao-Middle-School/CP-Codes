a=int(input())

def fun(n):

    lists=[[0 for i in range(n)]for i in range(n)]
    lists[0][n//2]=1

    x=0
    y=n//2
    for i in range(2,n**2+1):

        if x-1<0:
            x=n-1
        else:
            x-=1

        if y+1==n:
            y=0
        else:
            y+=1
        while 1:
            if lists[x][y]==0:
                lists[x][y]=i
                break
            else:

                for a in range(n):
                    for b in range(n):
                        if lists[a][b]==i-1:
                            before_x=a
                            before_y=b

                x=before_x+1
                y=before_y

                if x>n-1:
                    x=0
    for i in lists:
        i.reverse()
        for j in i:
            print(j,end=" ")
        print("")
        
        
fun(a)
