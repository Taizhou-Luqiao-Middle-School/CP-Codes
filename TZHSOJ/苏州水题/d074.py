n=int(input())
s=input().split()
for i in range(0,n-1,1):
    print(s[i],end=' ')
print(s[n-1])
s.append(s[0])
for i in range(1,n,1):
    print(s[i],end=' ')
print(s[n])
