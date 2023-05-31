n = int(input())

s1 = str(input())
s2 = str(input())

c = 0
a = []

for i in range(0, n):
    if s1[i] != s2[i]:
        c += 1
        a.append(i)

if c != 2:
    print("no")
if c == 2:
    i = a[0]
    j = a[1]
    if s1[i] == s1[j] and s2[i] == s2[j]:
        print("yes")
    else:
        print("no")