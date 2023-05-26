l=input()
c=int(len(l))
if(l[0:int(c/2)]==l[-1:int(-c/2-1):-1]):
    print("Yes")
else :
    print("No")


