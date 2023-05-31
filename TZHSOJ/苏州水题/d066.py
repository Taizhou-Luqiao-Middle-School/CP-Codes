s = input()
n = 0
r = ""
s1=""
for i in s :
    if i==' ':
        r = r+s1
        s1 = ""
    else :
        s1 = s1 + i
        n+=1
r = r+s1
print(r)
print(n)