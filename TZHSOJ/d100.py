
y,m = input().split()
y = int(y)
m = int(m)
print("Sun Mon Tue Wed Thu Fri Sat")
w = int(y-1+((y-1)/4)-((y-1)/100)+((y-1)/400)+1) % 7
pre_ = ""
for i in range (0,w-1):
    pre_ = pre_ + '    '
pre_ = pre_ + '   '
d=0
if m==1 or m==3 or m==5 or m==7 or m==8 or m==10 or m==12:
    d=31
elif m!=2:
    d = 30
else:
    if y%4 !=0:
        d = 28
    else:
        if y%100!=0:
            d = 29
        else:
            if y%400==0:
                d = 29
            else :
                d = 28

pre = "   "
r = pre_
for i in range(1,d+1):
    if w == 0:
        if i<10:
            pre = "  "
        else :
            pre = " "
    elif i>9:
        pre = "  "
    r = r+(pre+str(i))
    if w == 0:
        if i<10:
            pre = "   "
        else :
            pre = "  "
    w+=1
    if w==7:
        w=0
        print(r)
        r=""
print(r)