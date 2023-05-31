n=float(input())
k=float(n/100.0)
no=13.00
for i in range(1,1000):
    no=no*(k+1)
    if no>=20:
        print(i)
        break
