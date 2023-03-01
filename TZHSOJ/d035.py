i = int(input())
i +=365
y = i%50
m = i-y
m = int(m/50)
m -=5
m /=2
m = int(m)
out = str(y)+' '+str(m)
print(out)