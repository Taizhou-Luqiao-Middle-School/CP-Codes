y,m=input().split()
y=int(y)
m=int(m)
if m==1 or m==3 or m==5 or m==7 or m==8 or m==10 or m==12:
    print("31")
elif m!=2:
    print("30")
else:
    if y%4 !=0:
        print("28")
    else:
        if y%100!=0:
            print(29)
        else:
            if y%400==0:
                print(29)
            else :
                print(28)