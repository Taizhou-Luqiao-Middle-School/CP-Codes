c = input()
l = ['A','B','C','D','E','F','G','H','I','J','K','L',"M",'N','O','P','Q','R','S','T','U','V','W','X','Y','Z']

n=1
for i in l:
    if c==i:
        break
    n+=1

for i in range (0,n):
    s = ""
    for j in range (0,(n-i-1)):
        s = s+' '
    for j in range (0,2*i+1):
        s = s+l[i]
    print(s)
for i in range (0,n-1):
    s = ""
    for j in range (0,i+1):
        s = s+' '
    for j in range (0,2*(n-i-1)-1):
        s = s+l[n-i-2]
    print(s)