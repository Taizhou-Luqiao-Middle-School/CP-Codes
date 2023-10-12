l = list(map(int,input().split()))
n = int(input())
if l.count(n)==0:
    l.append(n)
    l.sort()
    print(l.index(n)+1)
    for i in l:
        print(i,end=' ')
else:
    di = []
    while(l.count(n)!=0):
        di.append(l.index(n)+len(di)+1)
        l.remove(n)
    for i in di:
        print(i,end = ' ')
    print()
    for i in l:
        print(i,end = ' ')
