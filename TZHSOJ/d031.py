result = "1 1 "
a = 1
b = 1
n = int(input())
if n==1:
    print("1")
else:
        
    for i in range (2,n,1):
        c = a+b
        if i%5==0:
            result = result + '\n'
        result = result + str(c) + ' '
        a = b
        b = c
    print(result)