a,b,n = input().split()
a = int(a)
b = int(b)
n = int(n)
a = a%b
a = a*(10**n)
print( int(a/b) )