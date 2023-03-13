zs=[2,3]
zsp = 0

def pre():
    for i in range(5,10000):
        b = 1
        for j in zs:
            if i%j==0:
                b=0
                break
        if b==1:
            zs.append(i)

pre()
n = int(input())
for i in zs:
    b=0
    for j in zs:
        if j<i:
            continue
        if i+j==n:
            print(str(n)+'='+str(i)+'+'+str(j))
            b=1
            break
    if b==1:
        break