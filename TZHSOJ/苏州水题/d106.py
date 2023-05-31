n=float(input())
sm=n*0.001
way=0.00
while n>=sm:
    way=way+n
    n=n*0.7
    if n>=sm:
        way=way+n
    else:
        break
    
print("%.2lf"%way)
