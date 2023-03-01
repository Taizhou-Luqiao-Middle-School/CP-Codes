pi = 1
for i in range(1,1001):
    sign = 1.0
    if (i%2==1):
        sign = -1.0
    pi = pi + sign/(2*i+1)
print("%.4f"%(pi*4))