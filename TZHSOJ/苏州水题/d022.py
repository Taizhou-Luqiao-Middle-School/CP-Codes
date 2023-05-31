a=input()
n=0
for i in a:
    if i=='a' or i=='A':
        n=n+1
    if i=='#':
        break
print (n)