l=[]
a=input()
for i in a:
    l.insert(0,i)

l.sort(reverse=True)
for i in l:
print(i,end='')
