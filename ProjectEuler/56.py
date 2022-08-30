def digitalSum(n):
    if n < 10 :
        return n
    return n % 10 + digitalSum( n // 10 )
    
mx = -1
for i in range(1, 101):
	for j in range(1, 101):
		mx = max(mx, digitalSum(pow(i, j)))
print(mx)	
