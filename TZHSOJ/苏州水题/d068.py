s = input()
r = ""
l = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
for i in s:
    b = 0
    p = 0
    for j in l:
        if i==j:
            r = r + l[(p+5)%26]
            b=1
            break
        else :
            p+=1
    if (b==0):
        r=r+i
print(r)