def f(n):
    s = 0
    for i in range(1,n):
        if n%i==0:
            s+=i
    return s

for i in range(1,10000):
    for j in range(i+1,10000):
        if f(i)==j and f(j)==i:
            print(i,j)
            break
###
# 220 284
# 1184 1210
# 2620 2924
# 5020 5564
# 6232 6368
###

print("220 284\n1184 1210\n2620 2924\n5020 5564\n6232 6368")