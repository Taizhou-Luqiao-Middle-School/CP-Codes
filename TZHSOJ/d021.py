for a in range(1,10,1):
    for b in range(0,10,1):
        for c in range(1,10,1):
            for d in range(0,10,1):
                x = (a*10+b) + (c*10+d)
                y = a*1000 + b*100 + c*10 + d
                if x*x==y:
                    print (y)